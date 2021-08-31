#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
  ifstream  cin; //ifstream is for input from plain text files
  cin.open("input.txt"); //open input.txt

  ofstream cout;
  cout.open("output.txt");

  int T;
  cin>>T;

  int w = 1;
  while(T--) {
    int n;
    cin>>n;

    vector<vector<char>> mat(n, vector<char>(n, ' '));

    for(int i=0; i<n; i++) {
      string s;
      cin>>s;

      for(int j=0; j<s.length(); j++) {
        mat[i][j] = s[j];
      }
    }

    vector<int> res;

    set<vector<pair<int, int>>> u_points;

    // column traversal
    for(int j=0; j<n; j++) {
      int x = 0;
      int empty=0;
      vector<pair<int, int>> points;
      for(int i=0; i<n; i++) {
        if(mat[i][j] == 'X') {
          x++;
        } else if(mat[i][j] == '.') {
          points.push_back(make_pair(i,j));
          empty++;
        }
      }
      if((x + empty) == n) {
        sort(points.begin(), points.end());

        // for(int a=0; a<points.size(); a++) {
        //   pair<int, int> temp = points[a];

        //   cout<<temp.first<<" "<<temp.second<<endl;
        // }

        if(u_points.find(points) == u_points.end()) {
          u_points.insert(points);
          res.push_back(empty);
        }

      }
    }

    // row traversal
    for(int i=0; i<n; i++) {
      int x = 0;
      int empty = 0;
      vector<pair<int, int>> points;
      for(int j=0; j<n; j++) {
        if(mat[i][j] == 'X') {
          x++;
        } else if(mat[i][j] == '.') {
          points.push_back(make_pair(i,j));
          empty++;
        }
      }

      if((x+empty) == n) {
        sort(points.begin(), points.end());

        // for(int a=0; a<points.size(); a++) {
        //   pair<int, int> temp = points[a];

        //   cout<<temp.first<<" "<<temp.second<<endl;
        // }
        if(u_points.find(points) == u_points.end()) {
          u_points.insert(points);
          res.push_back(empty);
        }
      }
    }

    sort(res.begin(), res.end());

    // cout<<"result is:-"<<endl;
    // for(int i=0; i<res.size(); i++) {
    //   cout<<res[i]<<endl;
    // }

    if(res.size() == 0) {
      cout<<"Case #"<<w<<": Impossible"<<endl;
    } else {
      int cnt = 1;
      int start = 1;
      int ans = res[0];
      while(res[start] == ans) {
        cnt++;
        start++;
      }
      cout<<"Case #"<<w<<": "<<ans<<" "<<cnt<<endl;
    }
    w++;
  }

  return 0;
}

/*
1
3
OXO
X.X
OXO

*/
