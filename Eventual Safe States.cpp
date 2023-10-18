Eventual Safe States

A directed graph of V vertices and E edges is given in the form of an adjacency list adj.Each node of the graph is labelled with a distinct integer in the range 0 to V -
A node is a terminal node if there are no outgoing edges.A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph.The answer should be sorted in ascending order.link-- >>

link -->> https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
Solution:: 
class Solution
{
public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[])
    {

        vector<int> adjrev[v];
        int indeg[v] = {0};
        for (int i = 0; i < v; i++)
        {
            for (auto &it : adj[i])
            {
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        vector<int> safenode;
        for (int i = 0; i < v; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safenode.push_back(node);
            for (auto it : adjrev[node])
            {
                indeg[it]--;

                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        sort(begin(safenode), end(safenode));
        return safenode;
    }
};