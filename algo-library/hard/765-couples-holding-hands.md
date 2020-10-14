### Problem Statement

`N` couples sit in `2N` seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from `0` to `2N-1`, the couples are numbered in order, the first couple being `(0, 1)`, the second couple being `(2, 3)`, and so on with the last couple being `(2N-2, 2N-1)`.

The couples' initial seating is given by `row[i]` being the value of the person who is initially sitting in the i-th seat.

`Example 1:`

**Input:** row = [0, 2, 1, 3]
**Output:** 1

Explanation: We only need to swap the second (row[1]) and third (row[2]) person.


`Example 2:`

**Input:** row = [3, 2, 0, 1]
**Output:** 0

Explanation: All couples are already seated side by side.

Note:

1. `len(row)` is even and in the range of `[4, 60]`.
2. `row` is guaranteed to be a permutation of `0...len(row)-1`.

### Key Observations

Before jumping on the solution, there are few things we can observe from the problem statement. 

1. Numbering of couples is incremental i.e `first couple = (0,1)` , `second couple = (2,3)` and so on. So to make things easy, let's change the numbering from `0 to 2*N-1` to `0 to N-1`, so our first couple will be numbered as `0`, second couple `1` and so on. 

2. If a couple sits next to each other, then they form a group and if they sit some distance apart, then two or more couples for a group. 

Let's understand second point from the explanation below (diagram included). 

Let's say we have our row array as - `[0,2,4,8,3,5,6,9,1,7]`. Now once we change the array by their correct respective graph node numbers, our array will look like - `[0,1,2,4,1,2,3,4,0,3]`. 

After the above transformation, we know that `i` and `i+1` sit next to each other, so we can go ahead and form an undirected edge between them, representing the connection. Now because of the graph node numbers occuring twice in the array, we will see that there can be cycles formed, representing a self cycle if the couples are sitting in the correct place next to each other. 

[Diagram showing the graph between ]

From the diagrams we can see that interconnected groups basically form a graph cycle. Now, if a connected component has 3 members in the group, then it will take minimium of 2 swaps to get couples next to each other. 

So, we can come to our answer based in two ways:-

1. `N`, where N is total number of couples - number of connected components. 
2. Sum of (number of members in each connected component - 1). So if there are three connected components, each having `s1, s2, s3` members respectively, then the answer will be - `(s1-1) + (s2-1) + (s3-1)`. 

### Algorithm

1. Loop through the array and change the values of each numnber to it's corresponding graph node number, let's say array value is 5, then it's corresponding graph node will be - `(5-1)/2 = 2`, if it's an even number then the graph node value will be `4/2 = 2`.

2. Once the graph is created, traverse through each node and keep count of connected components in each graph. 

3. The other way would be to keep count of node inside of each connected componenets. 

4. If your approach is number `2` then answer will be `N - number of connected components`.

5. If your approach is number `3` then answer will be `Sum of (number of members in each connected component - 1)`.

### Code 

```
class Solution {
public:
    vector<int> g[61];
    int visited[61];
    
    void dfs(int s) {
        if(visited[s]) {
            return;
        }
        visited[s] = 1;
        for(int i=0; i<g[s].size(); i++) {
            dfs(g[s][i]);
        }
    }
    
    int minSwapsCouples(vector<int>& row) {
        
        for(int i=1; i<row.size(); i+=2) {
            int x = row[i-1]%2==0 ? row[i-1]/2 : (row[i-1]-1)/2;
            int y = row[i]%2==0 ? row[i]/2 : (row[i]-1)/2;
            
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        int N = row.size()/2;
        memset(visited, sizeof(visited), 0);
        
        // This variable stores the number of connected components
        int cnt = 0;
        for(int i=0; i<N; i++) {
            if(!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        return N-cnt;
    }
};
```







