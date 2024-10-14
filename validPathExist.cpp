class Solution {
public:
    vector<int> v[200000];
    bool vis[200005];

    bool dfs(int s, int d) {
        if (s == d) return true;
        vis[s] = true;
        for (int child : v[s]) {
            if (!vis[child] && dfs(child, d)) {
                return true; 
            }
        }
        return false;  
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        for (const auto& edge : edges) {
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }

        return dfs(s, d);
    }
};
