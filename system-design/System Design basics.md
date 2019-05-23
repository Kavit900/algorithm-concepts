## Horizontal VS Vertical scaling

Horizontal scaling means adding more machines.

Vertical scaling means buying one bigger machine with high specifications.

| Horizontal | Vertical |
| -----------| ---------|
| Load Balancer is required | Load balancer is not required  |
| Resilient  | Single Point of failure  |
| Network calls (RPC), these are slow | Inter Process communication, these are fast |
| Data Inconsistency could be an issue | Data is consistent here |
| Scales well as users increase | Hardware limit |

In real world, it's good to have hybrid of both the above approaches.

## What is Load Balancing ?

 Let's say I have one user who is using my service, running on my laptop, everything works fine. Now, with time, our service becomes popular and there are more and more people trying out our services. What do we do ? We basically add another server and run our service on that as well. But there is a problem here as well. How do we redirect the users to use the new server that we have added.

 Let's take a bigger picture of our above example and let's say we have N servers, now how do we balance users requests to these different N servers ?

 To fix the above scenario, we will make use of a concept called Load Balancing. 

 So we will be making use of **Load Balancer** and a concept of **Consistent Hashing** will help us do that. 

 Let's take a look at how the old hashing system works in load balancing the requests 

 Let's say when a request comes in from the user, let's say we calculate and get a randommly generated *requestId*. 

 Now our concept is to pass this requestId to a hash function, a number that gets generated from here is then taken and then we calculate modulus of it with n (where n is number of servers) and the result tells us which server to redirect the request.

 Ex:- Let's say I have four servers S0, S1, S2 and S3.

 (i) we get requestId = 10.
 	h(10) = 3%4  = 3, where 4 is our server count, so we redirect the request to S3.

 (ii) Similarly we get requestId = 20.
 	h(20) = 3%4 = 3, so we redirect the request to S3.

 The above technique is not efficient enough as when we add one more server, the remapping takes place and it's not efficient

Let's take a look at an efficient Consistent Hashing technique 

#### Consistent Hashing 







