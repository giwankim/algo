#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr)
        return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next) {
        // cout << "slow: " << slow->val << " ";
        // cout << "fast: " << fast->val << "\n";
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        ListNode *head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = head->next;
        bool result = hasCycle(head);
        bool correct_result = true;
        cout << boolalpha;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        cout << noboolalpha;
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = head;
        bool result = hasCycle(head);
        bool correct_result = true;
        cout << boolalpha;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        cout << noboolalpha;
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 3=====\n";
        ListNode *head = new ListNode(1);
        bool result = hasCycle(head);
        bool correct_result = false;
        cout << boolalpha;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        cout << noboolalpha;
        // assert(result == correct_result);
    }
    return 0;
}
