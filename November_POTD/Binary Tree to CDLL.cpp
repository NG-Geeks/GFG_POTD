Binary Tree to CDLL

Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List (CDLL) in-place. 
The left and right pointers in nodes are to be used as previous and next pointers respectively in CDLL. 
The order of nodes in CDLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.
 Solution::
class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node* head = NULL  ,*prev = NULL;
    Node* b(Node *root){
        inorder(root);
        
        head->left = prev;
        prev->right = head;
        return head;
    }
    void inorder(Node * curr){
        if(curr == NULL)return ;
        
        inorder(curr->left);
        if(head == NULL)head = prev = curr;
        else{
            prev->right = curr;
            curr->left = prev;
        }   
        prev = curr;
        inorder(curr->right);
    }
    Node *bTreeToCList(Node *root)
    { 
        return b(root);
        
    }
};