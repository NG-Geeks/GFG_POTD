Normal BST to Balanced BST

Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

link-->>> https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1


class Solution
{

public:
    void solve(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        v.push_back(root->data);
        solve(root->left, v);
        solve(root->right, v);
    }
    Node *Bst(vector<int> &v, int l, int h)
    {
        if (l > h)
            return NULL;
        int mid = (l + h) / 2;

        Node *root = new Node(v[mid]);
        root->left = Bst(v, l, mid - 1);
        root->right = Bst(v, mid + 1, h);
        return root;
    }
    Node *buildBalancedTree(Node *root)
    {
        vector<int> v;
        solve(root, v);
        return Bst(v, 0, v.size() - 1);
    }
};
