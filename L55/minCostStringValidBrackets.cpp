#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
  if (str.length() % 2 == 1) {
    return -1;
  }

  stack<int> s;
  
  for(int i = 0; i < str.length(); i ++) {
    char ch = str[i];

    if(ch == '{') {
      s.push(ch);
    }
    else {
      if(!s.empty() && s.top() == '{') {
        s.pop();
      }
      else {
        s.push(ch);
      }
    }
  }

  int o = 0, c = 0;

  while(!s.empty()) {
    if(s.top() == '{') {
      o ++;
    }
    else {
      c ++;
    }

    s.pop();
  }

  return (o + 1) / 2 + (c + 1) / 2;
}