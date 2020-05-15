#include "bits/stdc++.h"
using namespace std;

struct Node {
    bool terminal;
    vector<Node*> children;
    Node() : terminal(false) { children.assign(26, nullptr); }
};

class Trie {
private:
    Node *root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->terminal = true;
    }

    bool search(string word) {
        Node *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->terminal;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    {
        Trie trie = Trie();
        trie.insert("apple");
        cout << trie.search("apple") << endl;   // 1
        cout << trie.search("app") << endl;     // 0
        cout << trie.startsWith("app") << endl; // 1
        trie.insert("app");   
        cout << trie.search("app") << endl;     // 1
    }
    return 0;
}
