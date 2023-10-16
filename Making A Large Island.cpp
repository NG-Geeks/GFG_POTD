Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1. A group of connected 1s forms an island. Two 1s are connected if they share one of their sides with each other.
Return the size of the largest island in the grid after applying this operation.
 link-- >>>https://practice.geeksforgeeks.org/problems/making-a-large-island/1
       

class Solution
{
    void solve(int id, int i, int j, vector<vector<int>> &grid, int m, int n, int &cnt)
    {
        if (i < 0 || j < 0 || i >= m or j >= n)
            return;
        else if (grid[i][j] > 1 or grid[i][j] == 0)
            return;
        else
        {
            grid[i][j] = id;
            solve(id, i + 1, j, grid, m, n, cnt);
            solve(id, i - 1, j, grid, m, n, cnt);
            solve(id, i, j + 1, grid, m, n, cnt);
            solve(id, i, j - 1, grid, m, n, cnt);
            cnt++;
        }
    }
    bool check(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m or j >= n)
            return 0;
        return 1;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int id = 2;
        unordered_map<int, int> p;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int cnt = 0;
                    solve(id, i, j, grid, m, n, cnt);
                    p.insert({id, cnt});
                    id++;
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int sum = 0;
                    set<int> s;
                    if (check(i - 1, j, m, n) && grid[i - 1][j] > 1 && s.find(grid[i - 1][j]) == s.end())
                    {
                        s.insert(grid[i - 1][j]);
                        auto it = p.find(grid[i - 1][j]);
                        sum += it->second;
                    }
                    if (check(i + 1, j, m, n) && grid[i + 1][j] > 1 && s.find(grid[i + 1][j]) == s.end())
                    {
                        s.insert(grid[i + 1][j]);
                        auto it = p.find(grid[i + 1][j]);
                        sum += it->second;
                    }

                    if (check(i, j - 1, m, n) && grid[i][j - 1] > 1 && s.find(grid[i][j - 1]) == s.end())
                    {
                        s.insert(grid[i][j - 1]);
                        auto it = p.find(grid[i][j - 1]);
                        sum += it->second;
                    }

                    if (check(i, j + 1, m, n) && grid[i][j + 1] > 1 && s.find(grid[i][j + 1]) == s.end())
                    {
                        s.insert(grid[i][j + 1]);
                        auto it = p.find(grid[i][j + 1]);
                        sum += it->second;
                    }

                    maxi = max(maxi, sum + 1);
                }
            }
        }
        return maxi == INT_MIN ? m * n : maxi;
    }
};