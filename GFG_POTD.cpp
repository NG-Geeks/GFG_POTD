Pairwise swap elements of a linked listhttps : https : // practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

                                                       Ques-- > Given a singly linked list of size N.The task is to swap elements in the linked list pairwise.For example,
    if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.

                                      Solution-- > class Solution
{
public:
    Node *pairWiseSwap(struct Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *prev = head->next;
        Node *nextt = prev->next;
        prev->next = head;
        head->next = pairWiseSwap(nextt);
        return prev;
    }
};
