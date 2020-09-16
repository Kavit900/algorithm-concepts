## Partitioning Strategies 

Sometimes it's also called as sharding, if you want to scale your system when data is of terabytes, then even if you have powerful machines nowadays, there is still a need to split your database into subsets, so that each database has a subset of the whole original data and load is partitioned. Now to further add fault tolerance to this database, you can create multiple copies of these subset databases. 

### Partition Server by Key Range. 

We basically assign a range to each server, so let's consider an example where we want to store worlds all english words into our database and we only have `2` servers for it. So, we can assign key range `A-M` to `server 1` and `N-Z` to `server 2`, so all the incoming words that have starting letter between `A to M` inclusive will go to `server 1` and all the words which have starting letter between `N to Z` will go to `server 2`. 

But there are few disadvantages with this approach.

1. If there are more set of data that fall into one particular range, then data load will be more on one particular server than the other and it will not be equally partitioned or distributed. 

2. We need to be aware and keep track about how much data we get in each range, otherwise one node can get overloaded. 

### Partition Server using Consistent Hashing (Hash of Key)

In this approach we pass in the data object to a hash function, which in turn returns a number. Now we can make use of this hash range to dsitribute the keys. Most of the modern databases make use of `md5` or `SHA1` hash functions and then make use of last `m` digits of the number returned by the hash function. 

In order to understand a simple case, Let's take we have `4` servers and our Hash function returns a number between `[0,63]`.

So the ranges assigned to our sevrers will look something like this:-

- Server 1 belongs to [0,15].
- Server 2 range is [16,31].
- Server 3 range is [32,46].
- Server 4 range is [47, 63].

Now based on the value returned by Hash function, we will hit the server in the above described range or in case of data, we will insert or retrieve data from the server in that particular range. 


**What will happen if in between a particular server fails or goes down?**

For example, if `server 2` goes down, then in that case the range of `server 3` will change from `[32,46` to `[16,46]` and all the request in the range of `server 2` and `server 3` will be handled by `server 3` now.

**What will happen if a new server is brought up?**

Now, let's consider a scenario where we see lot of load being generated in a partciular hash range and it seems like adding one more server would actually take off the load. Now after adding new server in the range, let's say between `server 1` and `server 3`, so the new `server 4` will take some in between range between `server 1` and `server 3`. 

**How do we make sure the server load is uniformaly distributed?**

The hash function that we use will be a uniform random generator function and the range that we pick, will be split uniformly among the set of servers. 

**Who takes care of which server is ideal for a particular hash range?**

This logic either can be taken care of by a specific service which handles the routing or you can provide configuration to load balancer and it can be handled on the fly as we get the requests. 

**NOTE:- We can add virtual node around our original servers to balance load more, so let's say we add virtual server nodes between each range, so for example, we add virtual server node 3 and 4 in between the hash range server 1 and 2, so this way we split the range between server 1 and server 2 into more smaller parts such that the load is more uniformly distributed.**

