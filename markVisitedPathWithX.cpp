#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
pair<int, int> parent[N][N];

int n, m;
char graph[N][N];

bool valid(int ci, int cj) {
    return ci >= 0 && ci < n && cj >= 0 && cj < m && graph[ci][cj] != '#';
}

void bfs(int si, int sj) {
    vis[si][sj] = true;
    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ci = node.first + dx[i];
            int cj = node.second + dy[i];

            if (valid(ci, cj) && !vis[ci][cj]) {
                vis[ci][cj] = true;
                q.push({ci, cj});
                parent[ci][cj] = node;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(vis, false, sizeof(vis));

    int si, sj, di, dj;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'R') {
                si = i; sj = j;
            }
            if (graph[i][j] == 'D') {
                di = i; dj = j;
            }
        }
    }

    bfs(si, sj);

    if (vis[di][dj]) {
        int sti = di, stj = dj;

        while (true) {
            if (sti == si && stj == sj) {
                break;
            }
            if (sti != di || stj != dj) {
                graph[sti][stj] = 'X';
            }
            auto p = parent[sti][stj];
            sti = p.first;
            stj = p.second;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << graph[i][j];
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << graph[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
