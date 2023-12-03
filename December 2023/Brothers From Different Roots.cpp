Brothers From Different Roots

Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.


class Solution
{   void solve(vector<int>&v , Node * root){
    if(!root)return ;
    solve(v,root->left);
    v.push_back(root->data);
    solve(v,root->right);
}
bool check(vector<int>&v, int k){
    int s =0;
    int e = v.size()-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(v[mid]==k)return 1;
        else if(v[mid]>k)e = mid-1;
        else s = mid+1;
        mid = s + (e-s)/2;
    }
    return 0;
}
public:
    int countPairs(Node* root1, Node* root2, int x)
    {   int cnt=0;
        vector<int>v;
        vector<int>vec;
        solve(v,root1);
        solve(vec,root2);
        for(int i=0;i<v.size();i++){
            int k = x - v[i];
            if(check(vec,k))
            cnt++;
        }
        return cnt;
    }
};