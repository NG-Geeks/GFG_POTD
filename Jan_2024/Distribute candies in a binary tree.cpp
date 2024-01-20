Question :: Distribute candies in a binary tree
HardAccuracy:  63.24%Submissions: 21K+Points: 8

Given a binary tree with N nodes, in which each node value represents number of candies present at that node. In one move, one may choose two adjacent nodes and move only one candy from one node to another (the move may be from parent to child, or from child to parent.) 
The task is to find the number of moves required such that every node has exactly one candy.
Note that the testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves
Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(1)

Code::
class Solution
{   int solve(Node*root , int &m ){
    if(!root)return 0;
   int left =  solve(root->left , m);

   int right = solve(root->right,m );
   m+= abs(left)+abs(right);
    return root->key - 1 + left + right;
}
    public:
    int distributeCandy(Node* root)
    {  
        int m=0;
        solve(root , m);
        return m;
    }
};