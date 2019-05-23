## Storage Scalability Introduction

A sound understanding of storage scalability is really important if you intend to interview for a senior backend engineer or a senior infrastructure engineer role. 
We try to walk you through some of these problems here to set a tone around how to approach these problems. Do note that no design is correct or wrong. There are just good designs and bad designs which heavily depend on the use case. 
Hence, it is extremely important to clarify the requirements for the problem asked. We discuss this in more detail in later slides.

## Pre Requisites

We assume in this section that you :

-  Have some experience working with a relational DB ( like MySQL ).
 
-  Have a basic idea about NoSQL DBs.

-  Understand the basics of the following : 
    1.  Concurrency : Do you understand threads, deadlock, and starvation? What happens when multiple processes / threads are trying to modify the same data? A basic understanding of read and write locks.
    2.  Networking : Do you roughly understand basic networking protocols like TCP and UDP? Do you understand the role of switches and routers?
    3.  File systems : You should understand the systems you’re building upon. Do you know roughly how an OS, file system, and database work? Do you know about the various levels of caching in a modern OS?


## Basic Terminologies

We try to explain some of the terminologies in simple words. Lookup wiki for a more formal definition.

- Replication : Replication refers to frequently copying the data across multiple machines. Post replication, multiple copies of the data exists across machines. This might help in case one or more of the machines die due to some failure.

- Consistency: Assuming you have a storage system which has more than one machine, consistency implies that the data is same across the cluster, so you can read or write to/from any node and get the same data.
        
- Eventual consistency : Exactly what the name suggests. In a cluster, if multiple machines store the same data, an eventual consistent model implies that all machines will have the same data eventually. Its possible that at a given instance, those machines have different versions of the same data ( temporarily inconsistent ) but they will eventually reach a state where they have the same data.

- Availability: In the context of a database cluster, Availability refers to the ability to always respond to queries ( read or write ) irrespective of nodes going down.

- Partition Tolerance: In the context of a database cluster, cluster continues to function even if there is a “partition” (communications break) between two nodes (both nodes are up, but can’t communicate).

- Vertical scaling and Horizontal scaling : In simple terms, to scale horizontally is adding more servers. To scale vertically is to increase the resources of the server ( RAM, CPU, storage, etc. ). Example: Lets say you own a restaurant which is now exceeding its seating capacity. One way of accommodating more people ( scaling ) would be to add more and more chairs (scaling vertically). However since the space is limited, you won’t be able to add more chairs once the space is full. 
    
Another way of scaling would be to open new branches of the restaurant ( horizontal scaling ). 

Source : http://stackoverflow.com/questions/5401992/what-does-scale-horizontally-and-scale-vertically-mean

- Sharding : With most huge systems, data does not fit on a single machine. In such cases, sharding refers to splitting the very large database into smaller, faster and more manageable parts called data shards.


## Cap Theorem 

CAP Theorem states that in a distributed system, it is impossible to simultaneously guarantee all of the following:

- Consistency
- Availability
- Partition Tolerance

http://ksat.me/a-plain-english-introduction-to-cap-theorem/ does an awesome job of explaining it in simple english

## Steps To Approach a Problem

It is recommended you follow the following steps to solving 

- Feature expectations ( First 2 mins ) : 
    As said earlier, there is no wrong design. There are just good and bad designs and the same solution can be a good design for one use case and a bad design for the other. It is extremely important hence to get a very clear understanding of whats the requirement for the question.

- Estimations ( 2-5 mins ) 
    Next step is usually to estimate the scale required for the system. The goal of this step is to understand the level of sharding required ( if any ) and to zero down on the design goals for the system. 
    For example, if the total data required for the system fits on a single machine, we might not need to go into sharding and the complications that go with a distributed system design. 
    OR if the most frequently used data fits on a single machine, in which case caching could be done on a single machine.
    
- Design Goals ( 1 mins ) 
    Figure out what are the most important goals for the system. It is possible that there are systems which are latency systems in which case a solution that does not account for it, might lead to bad design.

- Skeleton of the design ( 4 - 5 mins ) 
    30-40 mins is not enough time to discuss every single component in detail. As such, a good strategy is to discuss a very high level with the interviewer and go into a deep dive of components as enquired by the interviewer.

- Deep dive ( 20-30 mins ) 
    This is an extension of the previous section.

All of the problem discussions follow the exact same pattern on InterviewBit.


## System Design Useful reads

- Master Slave : https://www.quora.com/What-are-Master-and-Slave-databases-and-how-does-pairing-them-make-web-apps-faster

- Real life example of scaling using MySQL : https://medium.com/@Pinterest_Engineering/sharding-pinterest-how-we-scaled-our-mysql-fleet-3f341e96ca6f

- https://en.wikipedia.org/wiki/Paxos_(computer_science)



