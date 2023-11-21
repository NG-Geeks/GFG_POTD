Determine if Two Trees are Identical
Given two binary trees, the task is to find if both of them are identical or not.
Note: You need to return true or false, the printing is done by the driver code.

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {  if(!r1 && !r2)return 1;
       
       if(!r1 || !r2)return 0;
       if(r1->data!=r2->data)return 0;
       return isIdentical(r1->left , r2->left) && isIdentical(r1->right , r2->right);
    }
};
