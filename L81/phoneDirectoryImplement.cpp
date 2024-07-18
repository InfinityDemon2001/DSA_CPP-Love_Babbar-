#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i ++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if(word.length() == 0) {
            root -> isTerminal = true;
            return;
        }

        // Assumption: word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            // Absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {
        if(curr -> isTerminal) {
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch ++) {
            TrieNode* next = curr -> children[ch - 'a'];

            if(next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i = 0; i < str.length(); i ++) {
            char lastCh = str[i];

            prefix.push_back(lastCh);

            // Check for lastCh
            TrieNode* curr = prev -> children[lastCh - 'a'];

            // If not found
            if(curr == NULL) {
                break;
            }
            
            // If found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr) {
    // Creation of trie
    Trie* t = new Trie();

    // Insert all contacts in trie
    for(int i = 0; i < contactList.size(); i ++) {
        string str = contactList[i];
        t -> insertWord(str);
    }

    // Answer
    return t -> getSuggestions(queryStr);
}