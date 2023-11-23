Symmetric Tree
Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

class Solution{
    public:
    bool solve(Node * left , Node * right){
        if(!left && !right)return 1;
        if(!left|| !right)return 0;
        if(left->data != right->data)return 0;
        return solve(left->left , right->right ) && solve(left->right , right->left) ;
    }
    bool isSymmetric(struct Node* root)
    {
	    if(!root)return 1;
	    return solve(root->left , root->right);
    }
};
