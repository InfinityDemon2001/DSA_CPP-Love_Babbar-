#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creation
    unordered_map<string, int> m;
    
    // Insertion
    // Method 1
    pair<string, int> p = make_pair("Allen", 21);
    m.insert(p);
    // Method 2
    pair<string, int> pair2("Sabu", 10);
    m.insert(pair2);
    // Method 3
    m["Mera"] = 3;

    // Search
    cout << m["Mera"] << endl;
    cout << m.at("Sabu") << endl;

    // cout << m.at("Unknown") << endl;  Error
    cout << m["Unknown"] << endl;     // Creates a map and gives a default value 0 to the map

    // Size
    cout << m.size() << endl;

    // To check presence 
    cout << m.count("Allen") << endl;

    // Erase
    m.erase("Sabu");
    cout << m.size() << endl;

    // Access all elements
    // Method 1
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }
    // Method 2
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()) {
        cout << it -> first << " " << it -> second << endl;
        it ++;
    }

    return 0;
}