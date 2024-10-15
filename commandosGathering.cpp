#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> v[N];
int dis_from_src[N];
int dis_from_des[N];
bool vis[N];
void bfs(int s, int track)
{
    queue<int> q;
    q.push(s);
    if (track == 1)
        dis_from_src[s] = 0;
    else
        dis_from_des[s] = 0;
    vis[s] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                if (track == 1)
                    dis_from_src[child] = dis_from_src[par] + 1;
                else
                    dis_from_des[child] = dis_from_des[par] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int s, d;
        cin >> s >> d;
        memset(vis, false, sizeof(false));
        memset(dis_from_src, -1, sizeof(dis_from_src));
        bfs(s, 1);
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        memset(dis_from_des, -1, sizeof(dis_from_des));
        bfs(d, 2);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            //zei commando source ndoe theke sob cye durer building e cole zabe and destination node thekeo sob ceye dhure thake sei commandor distance er zug foloi hocce answer. ze commandor beshi somoy lagbe, sei time e hocce mission complete korar minimum time.
            //zodi bole ze kun commando age firbe tahole sob gulu commandor source theke n node e pouchanur time and destination node theke n node pouchanur min i hocce sorbo nimno time and i hocce commando.
            //evabe destination node theke sob ceye dhure ba kache obostito commando dis_from_des array theke pawya zabe.
            //evabe source node theke sob ceye dhure ba kache obostito commando dis_from_source array theke pawya zabe.
            int val = dis_from_src[i] + dis_from_des[i];
            ans = max(ans, val);
        }
        cout << "Case " << cs++ << ": " << ans << endl;
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}







// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;
// const int N = 105;

// vector<int> adj[N];
// int dist_s[N]; // Distance from source s
// int dist_d[N]; // Distance from destination d

// // Function to perform BFS and fill distance array
// void bfs(int start, int dist[], int n) {
//     queue<int> q;
//     fill(dist, dist + n, INF);
//     dist[start] = 0;
//     q.push(start);

//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();

//         for (int neighbor : adj[node]) {
//             if (dist[neighbor] == INF) {
//                 dist[neighbor] = dist[node] + 1;
//                 q.push(neighbor);
//             }
//         }
//     }
// }

// int main() {
//     int T;
//     cin >> T;

//     for (int tc = 1; tc <= T; ++tc) {
//         int n, r;
//         cin >> n >> r;

//         // Reset the adjacency list for each test case
//         for (int i = 0; i < n; ++i) {
//             adj[i].clear();
//         }

//         // Read the edges
//         for (int i = 0; i < r; ++i) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         int s, d;
//         cin >> s >> d;

//         // Perform BFS from `s` and `d`
//         bfs(s, dist_s, n);
//         bfs(d, dist_d, n);

//         int max_time = 0;
//         // Calculate the maximum time required for any commando to finish and regroup at `d`
//         for (int i = 0; i < n; ++i) {
//             max_time = max(max_time, dist_s[i] + dist_d[i]);
//         }
//         cout << "Case " << tc << ": " << max_time << endl;
//     }

//     return 0;
// }
