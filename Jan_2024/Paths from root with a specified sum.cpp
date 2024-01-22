Question :: Paths from root with a specified sum

Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path may not end on a leaf node.

Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(1)

Code::
class Solution
{   
    void solve(Node* root , vector<vector<int>>&v, vector<int>&res  , int curr , int sum){
        if(!root)return ;
        curr+=root->key;
        res.push_back(root->key);
        if(curr == sum)v.push_back(res);
        solve(root->left , v , res , curr , sum);
        solve(root->right , v , res , curr , sum);
        curr-=root->key;
        res.pop_back();
        
    }
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>>v;
        vector<int>res;
        int curr_sum =0;
        solve(root , v , res , curr_sum , sum);
        return v;
    }
};