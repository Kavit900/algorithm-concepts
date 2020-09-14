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


