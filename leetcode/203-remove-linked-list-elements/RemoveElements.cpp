#include "bits/stdc++.h"
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x_, ListNode *next_) : val(x_), next(next_) {}
};

void _print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

ListNode* Recursive(ListNode* head, int val) {
    if (head == nullptr)
        return head;
    if (head->val == val)
        return Recursive(head->next, val);
    head->next = Recursive(head->next, val);
    return head;
}

ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *cur = head;
    while (cur) {
        if (cur->val == val) {
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur= cur->next;
    }
    return dummy->next;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(6);
        int val = 6;
        ListNode *result = removeElements(head, val);
        cout << "Expected:\n";
        cout << "1 2 3 4 5\n";
        cout << "Output:\n";
        _print(result);
    }

    {
        cout << "=====Example 2=====\n";
        ListNode *head = new ListNode(1);
        int val = 1;
        ListNode *result = removeElements(head, val);
        cout << "Expected:\n";
        cout << "\n";
        cout << "Output:\n";
        _print(result);
    }

    {
        cout << "=====Example 3=====\n";
        ListNode *head = new ListNode(1);
        head->next = new ListNode(1);
        int val = 1;
        ListNode *result = removeElements(head, val);
        cout << "Expected:\n";
        cout << "\n";
        cout << "Output:\n";
        _print(result);
    }
    return 0;
}
