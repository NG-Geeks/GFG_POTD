Find Common Nodes in two BSTs
Questions --> Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.

link -->> https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1
class Solution
{   void solve(Node * root , vector<int>&ans){
    if(!root)return ;
    ans.push_back(root->data);
    solve(root->left, ans);
    solve(root->right , ans);
}

    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int>ans;
        solve(root1,ans);
        vector<int>res;
        solve(root2 , res);
        unordered_set<int>s;
        for(int &i:ans )s.insert(i);
        ans.clear();
        ans.resize(0);
        for(auto &i:res){
            if(s.count(i)){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};