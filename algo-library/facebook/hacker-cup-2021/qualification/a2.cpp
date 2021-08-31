#include <bits/stdc++.h>
#include<fstream>

using namespace std;

vector<int>g[26];

int bfs(int s, int d) {
  queue<pair<int, int>> q;

  q.push(make_pair(s,0));

  set<int> visited;

  while(!q.empty()) {
    pair<int, int> front = q.front();
    if(front.first == d) {
      return front.second;
    }
    q.pop();
    if(visited.find(front.first) == visited.end()) {
      visited.insert(front.first);
      for(int i=0; i<g[front.first].size(); i++) {
        q.push(make_pair(g[front.first][i], front.second+1));
      }
    }
  }

  return -1;
}

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

    for(int i=0; i<26; i++) {
      g[i].clear();
    }

    string s;
    cin>>s;

    int k;
    cin>>k;

    while(k--) {
      char x,y;
      cin>>x>>y;
      int a = x-'A';
      int b = y-'A';

      g[a].push_back(b);
    }

    int ans = 1e5+7;

    int valid_ans = 0;

    for(int i=0; i<26; i++) {
      char f = 'A' + i;

      int sum = 0;
      int flag = 1;
      for(int j=0; j<s.length(); j++) {
        if(f == s[j]) {
          continue;
        }

        int st = s[j]-'A';
        int d = f - 'A';

        int val = bfs(st,d);

        if(val == -1) {
          flag = 0;
          break;
        } else {
          sum += val;
        }
      }

      if(flag) {
        ans = min(ans, sum);
        valid_ans++;
      }
    }

    if(valid_ans > 0) {
      cout<<"Case #"<<w<<": "<<ans<<endl;
    } else {
      cout<<"Case #"<<w<<": "<<-1<<endl;
    }

    w++;
  }

  return 0;
}
