#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode *tmp = node->next;
    node->next = node->next->next;
    delete tmp;
}

int main(int argc, char const *argv[])
{
    {
        ListNode *head = new ListNode(4);
        head->next = new ListNode(5);
        head->next->next = new ListNode(1);
        head->next->next->next = new ListNode(9);

        ListNode *node = head->next;
        deleteNode(node);

        assert(head && head->val == 4);
        assert(head->next && head->next->val == 1);
        assert(head->next->next && head->next->next->val == 9);
    }
    {
        ListNode *head = new ListNode(4);
        head->next = new ListNode(5);
        head->next->next = new ListNode(1);
        head->next->next->next = new ListNode(9);

        ListNode *node = head->next->next;
        deleteNode(node);
        
        assert(head && head->val == 4);
        assert(head->next && head->next->val == 5);
        assert(head->next->next && head->next->next->val == 9);
    }
    return 0;
}
