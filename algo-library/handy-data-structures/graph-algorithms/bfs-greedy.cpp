/*
Problem link:- https://codeforces.com/contest/1520/problem/G
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int MAX_N = 2010;

int dd[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

void bfs(int sx, int sy, vector<vector<int>> &d, vector<vector<int>> &a) {
    int n = d.size();
    int m = d[0].size();
    queue<pair<int, int>> q;
    q.push({sx, sy});
    d[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dd) {
            int tx = x + dx;
            int ty = y + dy;
            if (tx >= 0 && ty >= 0 && tx < n && ty < m && d[tx][ty] == 0 && a[tx][ty] != -1) {
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    for (auto &e : d) {
        for (auto &i : e) {
            i--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> d1(n, vector<int>(m));
    vector<vector<int>> d2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    bfs(0, 0, d1, a);
    bfs(n - 1, m - 1, d2, a);
    ll bestFinish = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d2[i][j] != -1 && a[i][j] >= 1) {
                bestFinish = min(bestFinish, a[i][j] + w * 1ll * d2[i][j]);
            }
        }
    }
    ll ans = w * 1ll * d1[n - 1][m - 1];
    if (d1[n - 1][m - 1] == -1) {
        ans = 1e18;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d1[i][j] != -1 && a[i][j] >= 1 && bestFinish != 1e18) {
                ans = min(ans, w * 1ll * d1[i][j] + a[i][j] + bestFinish);
            }
        }
    }
    if (ans == 1e18) {
        cout << -1;
    } else {
        cout << ans;
    }
}
