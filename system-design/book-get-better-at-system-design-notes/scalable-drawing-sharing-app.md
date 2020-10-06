# Scalable Drawing Sharing App (Collaborative whiteboard app)

Let's go step by step, we will start with mentioning Functional and non-functional requirements initially and later on we will look at the implementation.

### Functional Requirements of the App

1. Support multiple whiteboards, people can create groups which other users can join.
2. Two or more Users should be able to connect together as one group on the App or in other words one whiteboard.
3. One User should be able to Draw.
4. Users except the drawing user should be able to see the drawing on their screens.

### Non-Functional Requirements of the App 

1. The interface should b easy to understand and in our case, the person drawing should see a color pallete and a white blank board, while other users can only see a blank white board.
2. The app should be reliable in short we want our app to be up 24/7/365.
3. The app should be scalable, which means you can create as many groups as possible and each group can support a large number of people. 
4. The app should be fairly fast in terms of Performance, ther shouldn't be difference of time between the users watching the whiteboard screen and looking at the drawing. 

### Understanding requirements in terms of numbers

1. How many maximum people will be using our drawing app at a particular time. (10,000).
2. How Many users can connect to one particular whiteboard i.e one channel? - (10 max).

For now, it seems that we have mostly covered the important functional and non-functional requirements, required to build the app. 

### High Level Design

Before jumping on to our main app implementation, let's look at the high level design we would need for our app. From the problem statemnt, it's clear we would need client-server architecture to our approach our design. Now that leaves us with two approaches in mind, either go with HTTP or websockets. 

#### HTTP vs WebSockets

Before deciding either to go with HTTP or WebSockets, let's take a deep dive whhich would serve our purpose exactly.

With HTTP, you have a once off request/reply pattern, you don't expect the next request from the client to come back to the same server. At least you shouldn't, because that means you have a *sticky session* problem and that you can't easily scale out for performance or redundancy. You can run virtually unlimited amount of web server instances behind a load balancer. The load balancer passes the request to a healthy web server instance when it comes in and the response gets passed back to the client once the web server has calculated it. 

On the other hand, WebSockets differ from HTTP requests in the sense that they are persistent. The WebSocket client opens up a connection to the server and resuses it. On this long running connection, both the server and client can publish and respond to events. This concept is called a duplex connection. A connection can be opened through a load balancer, but once the connection is opened, it stays with the same server until it's closes or interrupted. 

This in turn means that the interaction is stateful, that you will end up storing at least some data in memory on the WebSocket server for each client connection. For example, you will probably be aware which user is on the client side of the socket and what kind of data the user is interested in.

The fact that WebSocket connections are persistent is what makes it so powerful for real-time applications, but it's also what makes it more difficult to scale. 

### Who won among HTTP and WebSockets?

Keeping in mind our functional requirements and non-functional requirements, core reliability and persistent connection will be fulfilled by WebSockets, if we try to think on a high level, when a user draws on a particular whiteboard, it publishes the coordinates ovr a WebSocket connection and through to all the other users who have the same whiteboard open, in other words we have a pub/sub pattern exposed over WebSockets. 

### How do we do our design now?

Let's look at our functional requirements again before jumping on the design. To brief out the basic requirements, in this app there are multiple whiteboards, meaning multiple drawings that people can collaborate on. When a user draws on a particular whiteboard, it publishes the coordinates over a WebSocker connection and through to all the other users who have the same whiteboard open. It other words, we have a pub/sub pattern exposed over WebSockets.

It means that the server-side of the socker connection for each user of the app will need to know, at the very least, what whiteboard the user has open. Web socket implementations like socket.io have the concept of channels. Think of it as an address where clients subscribe to and either a service or other clients publishes to. 

It might be tempting to think that all we need to do is to build our collaborative white board app is to employ channels (each whiteboard has it's own channel) and then sit back and relax, but as you will see through the rest of this post, you will still have issues while scaling out and fault tolerance.

Firstly let's look closely into what pub/sub broker looks like. There is a variety of technologies around that support pub/sub pattern at considerable scale.

When you need to scale out a pub/sub architecture over sockets, you will need to find a good pub/sub technology to have at the core of your solution. 

Some good options available to us are - Redis, RabbitMQ, Kafka etc.

So lets list down few things:-

1. We need to use pub/sub architecture.
2. We don't just want to create a channel for each whiteboard blindly, that won't scale up quickly.
3. Each message or drawing done by the user should be reliable and others listening on that channel, should be able to see the exact drawings.

### How do we scale our application?

Imagine we only have one server, it's actually quite easy to build a pub/sub service with just WebSockets. This is because on one server the server will be aware of all clients and what data the clients are interested in. When a client sends coordinates of a drawing, we just find the correct channel for the drawing and publish the updates made to the drawing to that channel. All the clients are connected to the one server, so that all get notified of the change. It's kind of like in-memory pub/sub. 

But this won't last long and we would want to scale across multiple servers and we want to do this for two reasons:-

1. Sharing processing power.
2. Redundancy. 

We could scale our app to have more servers and clients could stay connected to those different servers instead of relying on processing power of one server. 

Now, what if we bring a database to our use instead of storing every data in-memory on server side, because we can't trust clients in-memory to persist the drawing data as it comes in because what if some client goes down, in that scenario we won't we able to get the old state back once it comes up, we will need some way to persist the drawing data as it comes in, so that we can serve up drawing anytimme a user opens the whiteboard.

But there is another problem. If a WebSocker on **server A** writes some data to the database, how would WebSocket on **server b** know to go and get the latest data from the database so that it can notify it's clients of new data?

##### Design walkthrough using example

Let's walk through the process of using Redis at the center of your solution. Although we might have hundreds of servers but for simplicity purpose, let's consider three servers for now. `WS1` , `WS2`, `WS3` .

So, again for simplicity purpose, let's consider that we have 9 people that opened up a specific drawing of a horse eating grass, we save this data in our database with an id of `xyz123` and we have 3 people connected to each server in the cluster (WS1, WS2, WS3).

Now one of the users connected to WS1 draws something on the whiteboard. In your websocket server logic, you write to the database, to ensure that the changes have been persisted and then publish to a channel based on a unique identifier associated to the drawing, most probably based on the database id for the drawing. Let's say that the channel name in this case is `drawing_abc123`.

At this point, you have the data written away safely in the DB and you have published an event to your pub/sub broker (Redis channel) notifying other interested parties that there is new data.

Because you have users connected to the other WebSocket servers (WS2, WS3), interested in the same drawing, they will have open subscriptions to Redis on the `drawing_abc123` channel. They get notified of the event, and each of the servers queries the DB for updates and emit it on the WebSocket channel used on your WebSocket tier.


### Handling failover

Another benefit of using a pub/sub broker to coordinate your WebSockets is that now it’s possible to easily handle failover.

When a client is connected to a WebSocket server, and that server falls over, the client can open a connection through the load balancer to another WebSocket server. The new WebSocket server will just ensure that there is a subscription to the pub/sub broker for the data that the WebSocket client is interested in and start piping through changes on the WebSocket when they occur

### Minor Improvements to the existing architecture

One thing to take into consideration when a client reconnects is making the client intelligent enough that it sends through some sort of data synchronization offset, probably in the form of a timestamp, so that the server doesn’t send it all the data again.

If every update to the drawing in question is time stamped, the clients can easily store the latest timestamp that they received. When the client loses the connection to a particular server, it can just reconnect to your websocket cluster (through your load balancer) by passing in the last timestamp that it received and that way the query to the DB can be built up so that it’ll only return updates that occur after the client last successfully received updates.

In loads of applications it might not be that important to worry about duplicates going down to the client. But even then, it might be a good idea to use a timestamp approach to save both your resources and the bandwidth of your users.

### Conclusion

Building a `pub/sub` service running on one server is relatively easy. The challenge is to build a service that can be scaled horizontally for load sharing and fault tolerance.

When you scale out, you need a way for the web socket services to subscribe to changed data, because changes to said data will also originate from other servers than itself. So in short each WebSocket server will have a redis client object declared inside of it using which it will make a connection with Redis 


