#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void _printNode(ListNode *node) {
    if (node == nullptr) {
        cout << "No cycle!" << "\n";
    } else {
        cout << node->val << "\n";
    }
}

ListNode* detectCycleSimple(ListNode *head) {
    if (head == nullptr) return nullptr;
    unordered_set<ListNode*> seen;
    seen.insert(head);
    while (head = head->next) {
        if (seen.find(head) != seen.end()) {
            return head;
        } else {
            seen.insert(head);
        }
    }
    return nullptr;
}

ListNode* detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    bool ok = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        // cout << "slow: " << slow->val << ", ";
        // cout << "fast: " << fast->val << "\n";
        if (slow == fast) {
            ok = true;
            break;
        }
    }
    if (ok == false)
        return nullptr;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        ListNode *head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = head->next;
        ListNode *result = detectCycle(head);
        ListNode *correct_result = head->next;
        cout << "Expected:\n\t";
        _printNode(correct_result);
        cout << "Output:\n\t";
        _printNode(result);
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = head;
        ListNode *result = detectCycle(head);
        ListNode *correct_result = head;
        cout << "Expected:\n\t";
        _printNode(correct_result);
        cout << "Output:\n\t";
        _printNode(result);
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 3=====\n";
        ListNode *head = new ListNode(1);
        ListNode *result = detectCycle(head);
        ListNode *correct_result = nullptr;
        cout << "Expected:\n\t";
        _printNode(correct_result);
        cout << "Output:\n\t";
        _printNode(result);
        // assert(result == correct_result);
    }
}
