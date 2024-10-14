#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool vis[105][105];
    int ans;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;

    bool valid(int ci, int cj)
    {
        return ci >= 0 && ci < n && cj >= 0 && cj < m;
    }

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            // If the cell is out of bounds or water, increment perimeter
            if (!valid(ci, cj) || grid[ci][cj] == 0)
                ans++;
            else if (!vis[ci][cj] && grid[ci][cj] == 1)
                dfs(ci, cj, grid);
        }
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        memset(vis, false, sizeof(vis));
        ans = 0;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    // Since we only care about the perimeter of one island,
                    // we can return early after finding and processing the first island.
                    return ans;
                }
            }
        }
        return ans;
    }
};
