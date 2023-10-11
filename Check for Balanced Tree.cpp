Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

link-- > https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

solution-- >
 pair<bool, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    bool leftt = left.first;
    bool rightt = right.first;
    int heightleft = left.second;
    int heightright = right.second;

    bool ans = abs(heightleft - heightright) <= 1;
    pair<bool, int> pr;
    if (leftt && rightt && ans)
    {
        pr.first = true;
    }
    pr.second = max(heightleft, heightright) + 1;

    return pr;
}

public:
// Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    return solve(root).first;
}
};
