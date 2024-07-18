#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "Allen";

    stack<char> s;

    for(int i = 0; i < str.size(); i ++) {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()) {
        char temp = s.top();
        ans.push_back(temp);
        s.pop();
    }

    cout << "Reversed string is: " << ans << endl;

    return 0;
}