#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
bool pathVisit[N];
vector<int> adj[N];
bool ans;
pair<int, int> cycleMakerEdge = {-1, -1};

void dfs(int parent) {
    vis[parent] = true;
    pathVisit[parent] = true;

    for (int child : adj[parent]) {
        if (pathVisit[child]) {
            ans = true;
            cycleMakerEdge = {parent, child};
            return; // Early exit after finding a cycle
        }
        if (!vis[child]) {
            dfs(child);
            if (ans) return; // If a cycle is found, no need to continue
        }
    }

    pathVisit[parent] = false;
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(pathVisit, false, sizeof(pathVisit));
    ans = false;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (ans) break; // Stop checking further if a cycle is detected
        }
    }

    if (ans && cycleMakerEdge.first != -1 && cycleMakerEdge.second != -1)
        cout << "Cycle detected at edge: " << cycleMakerEdge.first << " -> " << cycleMakerEdge.second << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}