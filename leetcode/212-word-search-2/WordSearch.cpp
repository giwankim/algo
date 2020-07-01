#include "bits/stdc++.h"
using namespace std;

void _print(const vector<string>& words) {
    for (const auto& s : words)
        cout << s << " ";
    cout << "\n";
}

const int R = 26;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct TrieNode {
    TrieNode* children[R];
    bool terminal;
    char c;

    TrieNode(char _c) : c(_c), terminal(false) {
        memset(children, 0, sizeof(children));
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('#');
    }

    Trie(const vector<string>& words) {
        root = new TrieNode('#');
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i]);
        }
    }

    void insert(const string& s) {
        TrieNode *cur = root;
        for (int i = 0; i < s.size(); ++i) {
            int charIdx = s[i] - 'a';
            if (cur->children[charIdx] == nullptr) {
                cur->children[charIdx] = new TrieNode(s[i]);
            }
            cur = cur->children[charIdx];
        }
        cur->terminal = true;
    }

    bool isPrefix(const string& s) {
        TrieNode *cur = root;
        for (int i = 0; i < s.size(); ++i) {
            int charIdx = s[i] - 'a';
            if (cur->children[charIdx] == nullptr)
                return false;
            cur = cur->children[charIdx];
        }
        return true;
    }

    bool search(const string& s) {
        TrieNode *cur = root;
        for (int i = 0; i < s.size(); ++i) {
            int charIdx = s[i] - 'a';
            if (cur->children[charIdx] == nullptr)
                return false;
            cur = cur->children[charIdx];
        }
        return cur->terminal;
    }
};

void backtrack(int y, int x, string word, vector<vector<bool>>& visited, vector<vector<char>>& board, Trie& trie, set<string>& ret) {
    visited[y][x] = true;
    word += board[y][x];
    if (trie.isPrefix(word) == false) {
        visited[y][x] = false;
        return;
    }
    if (trie.search(word)) {
        ret.insert(word);
    }
    for (int k = 0; k < 4; ++k) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            continue;
        if (visited[ny][nx] == true)
            continue;
        backtrack(ny, nx, word, visited, board, trie, ret);
    }
    visited[y][x] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie(words);
    set<string> ret;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            visited.assign(board.size(), vector<bool>(board[0].size(), false));
            backtrack(i, j, "", visited, board, trie, ret);
        }
    }
    return vector<string>(ret.begin(), ret.end());
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<vector<char>> board{
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'},
        };
        vector<string> words{"oath", "pea", "eat", "rain"};
        vector<string> result = findWords(board, words);
        vector<string> correct_result{"eat", "oath"};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        sort(result.begin(), result.end());
        _print(result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<vector<char>> board{
            {'a', 'a'},
        };
        vector<string> words{"a"};
        vector<string> result = findWords(board, words);
        vector<string> correct_result{"a"};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        sort(result.begin(), result.end());
        _print(result);
    }
    {
        cout << "=====Example 3=====\n";
        vector<vector<char>> board{
            {'a', 'b'}, {'c', 'd'}
        };
        vector<string> words{"acdb"};
        vector<string> result = findWords(board, words);
        vector<string> correct_result{"acdb"};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        sort(result.begin(), result.end());
        _print(result);
    }
    return 0;
}
