#include "bits/stdc++.h"
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int val_) : val(val_), prev(nullptr), next(nullptr), child(nullptr) {}
};

void _print(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

void dfs(Node* head, vector<Node*>& nodes) {
    if (head == nullptr) return;
    nodes.push_back(head);
    dfs(head->child, nodes);
    dfs(head->next, nodes);
}

Node* flatten(Node* head) {
    vector<Node*> nodes;
    dfs(head, nodes);
    for (int i = 0; i < nodes.size(); ++i) {
        if (i+1 < nodes.size())
            nodes[i]->next = nodes[i+1];
        if (i > 0)
            nodes[i]->prev = nodes[i-1];
        nodes[i]->child = nullptr;
    }
    return head;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====" << endl;
        Node *one = new Node(1);
        Node *two = new Node(2);
        Node *three = new Node(3);
        Node *four = new Node(4);
        Node *five = new Node(5);
        Node *six = new Node(6);
        Node *seven = new Node(7);
        Node *eight = new Node(8);
        Node *nine = new Node(9);
        Node *ten = new Node(10);
        Node *eleven = new Node(11);
        Node *twelve = new Node(12);

        one->next = two;

        two->prev = one;
        two->next = three;

        three->prev = two;
        three->next = four;
        three->child = seven;

        four->prev = three;
        four->next = five;

        five->next = six;
        five->prev = four;

        six->prev = five;

        seven->next = eight;

        eight->next = nine;
        eight->prev = seven;
        eight->child = eleven;

        nine->next = ten;
        nine->prev = eight;

        ten->prev = nine;

        eleven->next = twelve;

        twelve->prev = eleven;

        Node *result = flatten(one);

        cout << "Expected:\n";
        cout << "1 2 3 7 8 11 12 9 10 4 5 6\n";
        cout << "Output:\n";
        _print(result);
    }
    return 0;
}
