#include <bits/stdc++.h>

string reverseWords(string S) { 
    string ans = "";
    string temp = "";
    
    for(int i = S.length() - 1; i >= 0; i --) {
        if(S[i] == '.') {
            reverse(temp.begin(), temp.end());
            ans += temp + '.';
            temp = "";
        }
        else {
            temp += S[i];
        }
    }
    
    reverse(temp.begin(), temp.end());
    ans += temp;
    
    return ans;
} 