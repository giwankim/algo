#include "bits/stdc++.h"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *_next) : val(x), next(_next) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *ohead = new ListNode();
    ListNode *otail = ohead;
    ListNode *ehead = new ListNode();
    ListNode *etail = ehead;

    for (ListNode* cur = head; cur != nullptr;) {
        otail->next = cur;
        otail = otail->next;
        cur = cur->next;
        if (cur == nullptr) {
            break;
        }

        etail->next = cur;
        etail = etail->next;
        cur = cur->next;
    }
    otail->next = ehead->next;
    etail->next = nullptr;
    return ohead->next;
}

int main(int argc, char const *argv[])
{
    {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        auto result = oddEvenList(head);
        for (ListNode* cur = result; cur != nullptr; cur = cur->next) {
            cout << cur->val << " ";
        }
        cout << endl;
    }

    
    return 0;
}
