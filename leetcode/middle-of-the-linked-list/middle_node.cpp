#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(int argc, char const *argv[])
{
    /* code */
    auto *one = new ListNode(1);
    auto *two = new ListNode(2);
    auto *three = new ListNode(3);
    auto *four = new ListNode(4);
    auto *five = new ListNode(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    auto ans = middleNode(one);
    cout << ans->val << "\n";

    auto *six = new ListNode(6);
    five->next = six;
    ans = middleNode(one);
    cout << ans->val << "\n";
    return 0;
}
