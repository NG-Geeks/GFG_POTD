Height of a Binary TRee
Given a binary tree, find its height.


link --> https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

solution-->
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* head ){
        if(!head)return 0;
        return 1 + max(height(head->left),height(head->right));
      
    }
};