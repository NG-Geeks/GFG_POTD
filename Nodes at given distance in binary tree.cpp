Nodes at given distance in binary tree
Question-->Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
Note:

You have to return the list in sorted order.
The tree will not contain duplicate values.


link->>> https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

class Solution
{

    unordered_map<Node*,Node*>m;
    
    void solve(Node * root,Node*par ,int target , Node*&head){
        if(!root)return ;
        if(root&&root->data == target ){
            head = root;
        }
        m[root] = par;
        solve(root->left,root,target ,head);
        solve(root->right,root ,target , head);
    }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {          Node* head =NULL;

        solve(root,NULL , target , head);
        unordered_set<Node*>s;
        queue<Node* >q;
        q.push(head);
        while(!q.empty() && k){
            k--;
            int  n = q.size();
            
            for(int i=0;i<n;i++){
            Node * curr= q.front();
            q.pop();
            s.insert(curr);
            if(!s.count(curr->left) && curr->left)q.push(curr->left);
             if(!s.count(curr->right) && curr->right)q.push(curr->right);
              if(!s.count(m[curr]) && m[curr])q.push(m[curr]);
        }
        }
        vector<int>ans(q.size());
        for(int i=0;i<ans.size();i++){
            ans[i] = q.front()->data;
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};