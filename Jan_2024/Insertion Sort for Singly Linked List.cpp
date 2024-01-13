Question :: Insertion Sort for Singly Linked List
MediumAccuracy: 76.93%Submissions: 10K+Points: 4

Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Solution::

Complexity
Time complexity:
    O(N^2)
Space complexity:
    O(1)


Code::
class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        Node* temp = head;
        Node * curr = head->next;
        while(curr!=NULL){
            if(curr->data < temp->data){
                Node * t = head;
                Node * p = t;
                while(t->data<curr->data){
                    t = t->next;
                    if(p->next->data < curr->data)
                       p= p->next;
                }
                    Node* next = curr->next;
                    curr->next = t;
                if(t==head){
                
                    head = curr;
                }
                else{
                    
                    p ->next = curr;
                 
                }
                   temp->next =  next;
                    curr = next;
            }
            else{
                temp = temp->next;
                curr = curr->next;
            }
        }
        return head;
    }
    
};