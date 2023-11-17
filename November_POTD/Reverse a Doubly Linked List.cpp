Reverse a Doubly Linked List
Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.
Solution::

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node * p = NULL;
        
        while(head){
            head->prev =head->next;
            head->next = p;
            p = head;
            head = head->prev;
        }
        return p;
    }
};
