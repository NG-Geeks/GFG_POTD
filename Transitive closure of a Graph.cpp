Transitive closure of a Graph

Stuck on a problem? Level up with 35% Off on premium GfG Courses and master coding! 

banner
Given a directed graph, determine whether a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here, vertex j is reachable from another vertex i means that there is a path from vertex i to j. The reachability matrix is called the transitive closure of a graph. The directed graph is represented by an adjacency matrix where there are N vertices.
 
link-->> https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1
class Solution
{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> &grid)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        grid[i][j] = 1;
                    if (grid[i][j] == 0)
                        if (grid[i][k] == 1 && grid[k][j] == 1)
                            grid[i][j] = 1;
                }
            }
        }
        return grid;
    }
};