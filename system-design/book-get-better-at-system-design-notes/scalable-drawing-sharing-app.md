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

