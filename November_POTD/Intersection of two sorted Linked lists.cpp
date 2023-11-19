Intersection of two sorted Linked lists
Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.Solution::

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node * n = new Node(0);
        Node *t = n;
        while(head1 && head2){
            if(head1->data == head2->data){
                t->next = head1;
                t = t->next;
                 head1 = head1->next;
                  head2 = head2->next;
            }
            else if(head1->data < head2->data){
                head1 = head1->next;
            }
            else {
                head2 = head2->next;
            }
        }
        t->next = NULL;
        return n->next;
    }
};
