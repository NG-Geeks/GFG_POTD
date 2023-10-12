Duplicate subtree in Binary Tree

Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.
Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one. 

link-- > https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

solution-- >

class Solution {
    public:
    unordered_map<string,int>m;
    string solve(Node * root){
        if(!root)return "$";
        if(!root->left && !root->right){
            return to_string(root->data);
        }
        string s="";
        s+=to_string(root->data);
        s+=solve(root->left);
        s+=solve(root->right);
        m[s]++;
        return s;
    }
    int dupSub(Node *root) {
        m.clear();
        solve(root);
         for(auto x:m){
             if(x.second>=2)return 1;
         }
         return 0;
    }
};