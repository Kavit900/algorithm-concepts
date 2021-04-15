## Problem Statement

In a given grid, each cell can have one of three values:

the value `0` representing an empty cell;
the value `1` representing a fresh orange;
the value `2` representing a rotten orange.
Every minute, any fresh orange that is adjacent (`4-directionally`) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return `-1` instead.

`Example 1:`

```
Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

`Example 2:`

```
Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

`Example 3:`

```
Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
```

Note:

`1 <= grid.length <= 10`
`1 <= grid[0].length <= 10`
`grid[i][j] is only 0, 1, or 2.`


## Algorithm

1. First thing to notice here is, we need to find the maximum time, it will take to rot all the oranges.
2. It's a clear case of BFS traversal, where we try to rot all the oranges at each step and at the same time, keep track of the minutes elasped.
3. Use a visited data structure, to keep track of already visited cells.

## Code 

```
class Solution {
public: 
    struct Elem{
        int row;
        int col;
        int minute;
    };
    vector<vector<int>> Dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<Elem> q;
        set<pair<int, int>> visited;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                }
            }
        }
        
        int maxAns = 0;
        
        while(!q.empty()) {
            Elem e = q.front();
            q.pop();
            
            visited.insert(make_pair(e.row, e.col));
            maxAns = max(maxAns, e.minute);
            
            for(int d=0; d<Dirs.size(); d++) {
                int newRow = e.row + Dirs[d][0];
                int newCol = e.col + Dirs[d][1];
                int newMinute = e.minute+1;
                if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
                    continue;
                } else {
                    pair<int, int> temp = make_pair(newRow, newCol);
                    if (visited.find(temp) == visited.end() && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol, newMinute});
                    }
                }
                
            }
        }
        
        int flag = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    flag = true;
                    break;
                }
            }
        }
        
        if(flag) {
            return -1;
        }
        
        return maxAns;
    }
};
```