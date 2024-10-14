#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int parentArray[N];
bool ans;
pair<int, int> cycleMakerEdge = {-1, -1};

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parentArray[s] = -1;  // Source node has no parent

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int child : adj[parent]) {
            if (vis[child] && parentArray[parent] != child) {
                ans = true;
                cycleMakerEdge = {parent, child};
                return;  // Early exit after finding a cycle
            }
            if (!vis[child]) {
                vis[child] = true;
                parentArray[child] = parent;
                q.push(child);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bfs(i);
            if (ans) break;  // Stop further BFS if a cycle is detected
        }
    }

    if (ans && cycleMakerEdge.first != -1 && cycleMakerEdge.second != -1)
        cout << "Cycle detected at edge: " << cycleMakerEdge.first << " -> " << cycleMakerEdge.second << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
