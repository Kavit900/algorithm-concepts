## Replication in Distributed Systems

**What is Replication?** 

Key requirements for a scalable system is, you system is highly available, so in order to fulfill that condition is to replicate the servers and so if one server goes down, then we have other servers ready to serve our user needs. 

We are now going to look into three approaches to replicate our servers. 

### Single Leader (Master/Slave) architecture

Concept of Single Leader architecture is we have one leader and n number of replicas. 

- So the major goal of this approach is that writes to db always goes to leader node and all the reads can go to any of the servers, doesn't matter whether it's leader or slave. 

- It's master nodes duty to make sure all the slaves have same copy of that as master node. 

#### Strategies used to Sync Master and Slaves

1. Synchronous write - One strategy used during write is, master can synchronously write to all replicas and once write is completed successfully on all the child, then only master sends the message to client saying, write was successfully completed. One of the drawback of single master synchronous involves lot of latency. 

2. Semi-Synchronous write - Here the concept is, let's say we have 3 replicas and 1 master (obv). In this scenario, leader makes sure that 1 of the 3 replica update is synchronous and for the other replicas, it's lazy update and happens asynchronously. One of the disadvantages of this approach is that, if user tries to read from replica which has stale entry, then the user will have old data but the response of write will be quicker than fully synchronous write approach.

3. Asynchronous write - In this case syncing between leader and replicas will be asynchronous and so latency is very small but user has higher chances of getting stale data.

#### How does the Replication Works

Whenever Leader accepts a write, it has an internal logic called write ahead log (WAL), so the concept is, before writing data to replica, it basically writes to WAL file and responds *ack* to client. This WAL file is a persistent file and after writing log to this file, it forwards the sequnce of database operation to all replicas for them to run the same write operation that was run on the leader server. The database operation written to WAL can be - insert, update or delete. 

Now in case leader fails or goes down, this **WAL** provides a helping hand in the form that, when leader node comes up again, leader can quickly go through this WAL file and carry out the operations mentioned in the WAL to get in correct state. 

**If currently we have 2 replicas and based on the load, we decide to add a new replica, how do we make this transition without disrupting the existing system?**

Before we start copying the new data to this replica, we must have a mechanism in place where we take snapshots of our master database on a regular intervals, let's say every week (taking snapshots simply means keeping a backup). Now, once our replica is up, we can instantiate it using the last snapshot of our master db and then copy over the difference between last week snapshot and current state of master db. After these operations are complete, we will broadcast a message saying our db is up and ready and future read requests are now ready to be handled by our new replica. 

**What happens when leader node fails?**

If leader is failed, then we need to choose one of the replicas as the new leader. 

**What Strategy can we use to pick new leader among all the replicas?**

1. We can check and see which replica has the latest data, now in order to pick the new leader, all the replicas communicate with each other and based on consensus pick the most upto date replica as the new leader. 


**How do the replica come to know that leader is no longer available?**

One good strategy in this scenario would be, we can have a mechanism in place, where periodically replicas ping leader (periodic heartbeats), so if leader doesn't respond for some period of time then we can start the process of electing new leader among the replicas.

Another strategy would involve use of a microservice or zooker which tracks number of consecutive write failures or monitors it, to determine that leader node has gone down and based on that we can start the process of electing a new leader.

**What are some realtime examples, which use single leader approach?**
- MySQL,
- DynamoDB,
- RabbitMQ

There are many more but few of the famous ones are mentioned above.

### Multileader (Master/Slave) architecture




### Leaderless 



























