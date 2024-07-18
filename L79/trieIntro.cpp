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
        int index = word[0] - 'A';
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

    bool searchUtil(TrieNode* root, string word) {
        // Base case;
        if(word.length() == 0) {
            return root -> isTerminal;
        }

        // Assumption: word will be in caps
        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            // Absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    t -> insertWord("ABCD");
    t -> insertWord("DO");
    t -> insertWord("TIME");

    cout << "Present or not " << t -> search("TIM") << endl;
    
    return 0;
}