#include <bits/stdc++.h>
#include <fstream>

using namespace std;

bool is_vowel(char ch) {
    if(ch == 'A' ||
        ch == 'E' ||
        ch == 'I' ||
        ch == 'O' ||
        ch == 'U'
    ) {
      return true;
    }

    return false;
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
    string s;
    cin>>s;

    int n = s.length();

    int ans = 1e5+7;

    for(int i=0; i<26; i++) {
      char f = 'A'+i;

      int sum = 0;

      // convert all the characters of the string into f
      for(int j=0; j<n; j++) {
        if(s[j] == f) {
          continue;
        }
        if(is_vowel(f)) {
          if(is_vowel(s[j])) {
            sum += 2;
          } else {
            sum += 1;
          }
        } else {
          if(is_vowel(s[j])) {
            sum += 1;
          } else {
            sum += 2;
          }
        }
      }

      ans = min(ans, sum);
    }

    cout<<"Case #"<<w<<": "<<ans<<endl;
    w++;
  }

  return 0;
}
