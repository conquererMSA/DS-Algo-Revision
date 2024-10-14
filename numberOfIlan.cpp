/*
https://leetcode.com/problems/number-of-islands/
*/
class Solution {
public:
    bool vis[300][300];
    vector<pair<int, int>> childPath={{0,1},{0,-1},{-1,0},{1,0}};
    int r, c;
    
    bool isValid(int cr, int cc) {
        if (cr < 0 || cr >= r || cc < 0 || cc >= c) return false;
        return true;
    }
    
    void dfs(int sr, int sc, vector<vector<char>>& grid) {
        vis[sr][sc] = true;
        for (int i = 0; i < 4; i++) {
            int cr = sr + childPath[i].first;
            int cc = sc + childPath[i].second;
            if (isValid(cr, cc) && !vis[cr][cc] && grid[cr][cc] == '1') {
                dfs(cr, cc, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        memset(vis, false, sizeof(vis));
        r = grid.size();
        c = grid[0].size();
        int ans=0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return ans;
    }
};

/*
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int r, c;
    
    bool isValid(int cr, int cc) {
        return cr >= 0 && cr < r && cc >= 0 && cc < c;
    }
    
    void dfs(int sr, int sc, vector<vector<char>>& grid) {
        // Mark the cell as visited by changing '1' to '0'
        grid[sr][sc] = '0';
        for (auto [dr, dc] : directions) {
            int cr = sr + dr;
            int cc = sc + dc;
            // Continue DFS if the neighboring cell is within bounds and is land ('1')
            if (isValid(cr, cc) && grid[cr][cc] == '1') {
                dfs(cr, cc, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // If we find an unvisited land cell ('1'), start a DFS
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return ans;
    }
};

*/
