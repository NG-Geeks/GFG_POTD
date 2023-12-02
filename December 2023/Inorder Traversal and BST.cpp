Inorder Traversal and BST
Given an array arr of size N, determine whether this array represents an inorder traversal of a BST. 

Note: All keys in BST must be unique.Solution::

class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        for(int i = N-1;i>0;i--){
            if(arr[i-1]>arr[i])return 0;
            
        }
        return 1;
    }
};