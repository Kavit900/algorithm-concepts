/*
Floyd-Warshal algorithm is an all-pairs shortest path algorithm using dynamic programming.

It is too simple and undrestandable :
*/

void floyd_warshal()
	d[v][u] = inf for each pair (v,u)
	d[v][v] = 0 for each vertex v
	for k = 1 to n
		for i = 1 to n
			for j = 1 to n
				d[i][j] = min(d[i][j], d[i][k] + d[k][j])

//Time complexity : O(n3).
