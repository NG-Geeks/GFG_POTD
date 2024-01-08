Question :: Merge 2 sorted linked list in reverse order

Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.
Solution::

Complexity
Time complexity:
    O(N + M).
Space complexity:
    O(N + M)


Code::

class Solution
{
       Node* reverse(Node * head){
        Node * prev = NULL;
        while(head){
            Node * next = head->next;
            head->next = prev;
           
            prev = head;
             head = next;
        }
        return prev;
    }
    public:
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        node1 = reverse(node1);
        node2 = reverse(node2);
        Node * head = new Node;
        Node* curr = head;
        while(node1 && node2){
            if(node1->data > node2->data){
                  Node * temp = new Node;
                  temp->data = node1->data;
                  curr->next =temp;
                  node1 = node1->next;
            }
            else{
                Node * temp = new Node;
                  temp->data = node2->data;
                  curr->next =temp;
                  node2 = node2->next;
            }
            curr = curr->next;
        }
        while(node1){
             Node * temp = new Node;
                  temp->data = node1->data;
                  curr->next =temp;
                  node1 = node1->next;
                  curr = curr->next;
        }
        while(node2){
             Node * temp = new Node;
                  temp->data = node2->data;
                  curr->next =temp;
                  node2 = node2->next;
                  curr = curr->next;
        }
        return head->next;
    }  
};