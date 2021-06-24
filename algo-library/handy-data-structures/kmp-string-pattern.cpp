/*
This algorithm is helpful for pattern matching
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  string t;
  cin>>s>>t;

  int n = s.length();

  int m = t.size();

  int lps[m];
  lps[0] = 0;

  // Here we form lps array
  for(int i=1; i<m; i++) {
    int current_size = lps[i-1];

    while(current_size >= 1 && t[i] != t[current_size]) {
      current_size = lps[current_size - 1];
    }

    if(t[i] != t[current_size]) {
      lps[i] = current_size;
    } else {
      lps[i] = current_size + 1;
    }
  }


  // Now that our pattern is ready, let's find it's occurrences in string s

  current_size = 0;
  int times = 0;

  for(int i=0; i<n; i++) {

    while(current_size == m || current_size >= 1 && s[i] != t[current_size]) {
      current_size = lps[current_size - 1];
    }

    if(s[i] == t[current_size]) {
      current_size++;
    }

    if(current_size == m) {
      times++;
    }
  }

  cout<<times<<endl;

  return 0;
}
