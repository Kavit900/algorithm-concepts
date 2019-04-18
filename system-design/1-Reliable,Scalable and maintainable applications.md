
# Chapter 1 - Reliable, Scalable and Maintainable applications

*Reliability :-*     Tolerating hardware, software faults and human error.

*Scalability :-*     Measuring load and performance, latency percentiles, throughput.

*Maintainability :-* Operability, simplicity and evolvability.

Many applications today are data-intensive, as opposed to compute-intensive. RAW CPU power is rarely a limiting factor for these application - bigger problems are usually the amount of data, the complexity of data and the speed at which it is changing.

A data-intensive application is typically built from staandard building blocks that provide commonly needed functionality. Some examples are:-

- Store data so that they can find it later again (*databases*)
- Remember the result of an expensive operation, to speed up reads (*caches*)
- Allow users to search data by keyword or filter it in various ways (*search indexes*)
- Send a message to another process, to be handled asynchronously (*stream processing*)
- Periodically crunch a large amount of accumulated data (*batch processing*)


### Reliability

Expectations for an application to be reliable are:-

- The application performs the function that the user expected.
- It can tolerate the user making mistakes or using the software in unexpected ways.
- It's performance is good enough for the required use case, under the expected load and data volume.
- The system prevents any unauthorized access and abuse.

The things that can go wrong are called *faults* and systems that anticipate faults and can cope are called *fault-tolerant or resilient*. 

Note fault is not the same as a failure. A fault is usually defined as one component of the system deviating from it's spec, whereas a failure is when the system as a whole stops providing the required service to the user.

It is impossible to reduce the probability of a fault to zero, therefor it is usually best to design fault-tolerance mechanisms that prevent faults from causing failures. 

##### Hardware Faults

In case of system failure, hardware faults come to mind i.e Hard disk crash, RAM becomes faulty, power grid blackout, someone unplugs the wrong network cable.

Hard disks have a mean time to failure (MTTF) of about 10 to 50 years, thus on a storage cluster with 10,000 disks, we should expect average one disk to die per day.

We can add redundancy to individual hardware components in order to reduce failure rate of the system. Disks may be set up in a RAID configuration (read up on this more),  servers may have dual power supplies and hot-swappable CPUs and datacenters may have batteries and diesel generators for backup power. When one component dies, redundant component takes it's place. 

But in recent times, we have systems that use software fault-tolerance techniques in addition to hardware redundancy. Such systems have advantage over single-server system which requires planned downtime (to apply OS security ptches), whereas a system that can tolerate machine failure can be patched one node at a time, without downtime of the entire system (rolling upgrade).

##### Software Errors

Hardware faults are usually random and independent from each other. But another class of faults is systematic error within the system, where more than one node are correlated and cause system failure, examples :-

- A software bug that causes every instance of an application server to crash when given a particular bad input.
- A runaway process that uses up some shared resource - CPU time, memory, disk space or network bandwidth.
- A service that the system depends on that slows down, becomes unresponsive or starts returning corrupted responses.
- Cascading failures, where a small fault in one component triggers a fault in another component, which in turn triggers further faults.

### Scalability

Scalability is the term we use to describe a system's ability to cope with increased load. It is meaningless to say 'X is scalable' and 'Y is not scalable'. We should ask questions like:-

- If the system grows in a particular way, what are our options for coping with the growth.
- How can we add computing resources to handle the additional load.

##### Describing Load

Load can be described with few numbers which we call load parameters, for example:-

- it may be requests per second to a web server.
- the ratio of reads to writes in a database.
- the number of simultaneously active users in a chat room.
- the hit rate on a cache.

Let's understand this by an example Twitter. Two of it's main operations are:-

- Post Tweer - a user can publish a new message to their followers (4.6K requests/sec on avg or 12K requests/sec at peak).
- Home Timeline - a user can view tweets posted by the people they follow (300K requests/sec).

Simply handling 12K writes per second would be fairly easy but twitter's sclaing challenge is not only tweet volume but *fan out* - each user can follow many people and each user is followed by many people. 

Two ways of implementing these two operations:-

- Posting a tweet simply inserts the new tweet into a global collection of tweets. When a user requests their home timeline, look up all the people they follow, find all the tweets for each of those users and merge them (sorted by time). In a relational database our query would look like:-

```
SELECT tweets.*, users.* FROM tweets
  JOIN users   ON tweets.sender_id    = users.id
  JOIN follows ON follows.followee_id = users.id
  WHERE follows.follower_id = current_user
```

- Maintain a cache for each user's home timeline - like a mailbox of tweets for each recipient user. When a user posts a tweet, look up all the people who follow that user and insert the new tweet into each of their home timeline caches. The request to read the home timeline is then cheap, because it's result has been computed ahead of time.

The first version of Twitter used approach 1 but the system struggled with the load of home timeline queries, so company switched to approach 2. The approach 2 works better because the average rate of published tweets is almost two orders of magnitude lower than the rate of home timeline reads and so in this case it's preferable to do more work at write time and less at read time.

The approach 2 has downside that posting a tweet triggers a lot of extra work and it's a lot of reads now as 1 person can have like 30 million followers.

Now Twitter is moving to a hybrid of both approaches, where approach 2 is used for users with less number of followers but in case of celebrities whose followers are more, approach 1 is used, where tweets for a user for home timeline is evaluated then only.

##### Describing Performance

What happens when the load increases on your system:-

- When you increase a load parameter and keep the system resources (CPU, memory, network bandwidth etc.) unchanged, how is the performace of your system affected ?
- When you increase a load parameter, how much do you need to increase the resources if you want to keep performance unchanged ?




