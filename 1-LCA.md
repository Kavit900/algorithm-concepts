## Lowest Common Ancestor (LCA)

To understand what LCA is let's take the below image as example:-

![LCA tree](/images/lca-tree-example.png)

The above tree is an example of a rooted tree with 10 vertices and rooted at node number 0. You may verify manually that 
LCA(4,5) = 3,
LCA(4,6) = 1,
LCA(4,1) = 1, 
LCA(8,9) = 7 and LCA(4,8) = 0.
Throughout this article we will assume to denote N the total number of nodes in the tree.

### Naive Algorithm for finding the LCA:

Time Complexity Per Query: O(N)

A naive solution consists of two steps: From the first vertex , we go all the way up to the of the tree and record all the vertices traversed along the way . From the second vertex , we also go all the way up to the root of the tree , but this time we stop if we encounter a common vertex for the first time . This common vertex is the LCA. For example, if we want to compute LCA(4,6) of the tree in the figure of the tree given above in this article using this naive solution, we will first traverse the path 

`4 -> 3 -> 1 -> 0`

and mark these 4 vertices as visited.

*Step 1:-*

![LCA Naive approach step 1](/images/lca-naive-approach-step1.jpg)

*Step 2:-*

![LCA Naive approach step 2](/images/lca-naive-approach-step2.jpg)

 *Nodes visited in Step 1 are marked in green*

 Then we start our traversal from the second vertex of the the query 6 and traverse along the path 

 `6->1`

 We stop our traversal at node `1` because this is in the path from the first vertex to the root . Hence , the paths of `4` to `root` and `6` to `root` intersect for the first time at node `1`.As the traversal of the nodes is such that the distance of the nodes from the keeps decreasing as the traversal continues , We can say node is the node `1` farthest from the `root` that is an ancestor of nodes `4` and `6`. Hence , LCA(4,6) = 1.

This algorithm takes total time complexity of `O(h)`, where h is the maximum distance of the root from a leaf, in worst case, it will be equal to `N`. 

*Code:-*

```
int parent[MAX_NODES];                  /*Keeps track of the parent of every vertex in the tree*/
bool visited[MAX_NODES];                
vector<vector<int> > tree[MAX_NODES];   /*The tree is stored as an undirected graph using an adjacency list*/



/*GetParents() function traverses the tree and computes the parent array such that
The pre-order traversal begins by calling GetParents(root_node,-1) */
void GetParents(int node , int par){       
    for(int i = 0 ; i < tree[node].size() ; ++i){
        /*As this is a pre-order traversal of the tree the parent of the current    node has already been processed*/
        Thus it should not be processed again*/
        if(tree[node][i] != par){
            parent[tree[node][i]] = node ; 
            GetParents(tree[node][i] , node) ; 
        }
    }
}


/*Computes the LCA of nodes u and v . */
int LCA(int u , int v){
    /*traverse from node u uptil root node and mark the vertices encountered along the path . */
    int lca ; 
    while(1){
        visited[u] = true ; 
        if(u == root_node){
            break ; 
        }
        u = parent[u] ; 
    }

    /*Now traverse from node v and keep going up untill we dont hit a node that is in the path of node u to root node*/
    while(1){
        if(visited[v]){ /*Intersection of paths found at this node.*/
            lca = v;    
            break ;  
        }
        v = parent[v] ; 
    }
    return lca ; 
}
```



