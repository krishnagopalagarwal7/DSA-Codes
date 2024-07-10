#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // Default constructor: initializes val to 0 and next to nullptr
    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    // Constructor to initialize with a value: sets val to x and next to nullptr
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }

    // Constructor to initialize with a value and next node: sets val to x and next to the given node
    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
        // Here, this->next is used to refer to the member variable next of the class, differentiating it from the parameter next.
    }
};

ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr, curr = next;
    }
    return prev;
}

int main()
{
    ListNode *headA = new ListNode(5);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(7);
    headA->next->next->next = new ListNode(8);

    ListNode *headB = new ListNode(9);
    headB->next = new ListNode(10);
    headB->next->next = new ListNode(7);
    headB->next->next->next = new ListNode(8);

    return 0;
}