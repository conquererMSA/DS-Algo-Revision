
/*
 DSU directed graph e kaj kore na. Undirected graph e khub sohoje Cycle detect kora zay.
 Duti set er moddye intersaction korle zodi faka/empty set pawya zay sei faka/empty set i hocce disjoin union set. Duita vinno set er intersaction korle faka set pawya zabe.
Duti set er moddye union korar kkhetre tader moddye kuno common node/element thakte parbe na.

 Cycle detection:
DSU edge niye kaj kore, DSU edge er direction recognized korte pare na. Tai DSU undirected graph e cycle detect korte pare, kintu directed graph e cycle detect korte pare na.
DSU duita node er moddye cycle detect kore na. DSU diye cycle detect korar jonno at least 3 ti node dorkar.
CycleDetection: zodi ekti edge er duiti node er leader same hoy tahole ei edge cycle create korbe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader; //path relaxation
    return leader;
}
void dsu_union(int node1, int node2)
{
    // bad
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    par[leaderA] = leaderB;
}
//duti node er level same hole o size same hobe na.
void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    //a er level boro b theke
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    //b er level boro a theke
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    //a and b er level soman
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
//duti node er level same holeo size same hoy na, chuto othoba ba boro hoy. union korlei size chuto boro hoyei zabe.
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    //node a er size boro, b er size a theke chuto
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    //node b er size boro, a er size b theke chuto
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main()
{
    dsu_initialize(7);
    dsu_union_by_level(1, 2);
    dsu_union_by_level(2, 3);
    dsu_union_by_level(4, 5);
    dsu_union_by_level(5, 6);
    dsu_union_by_level(1, 4);
    cout << dsu_find(1) << endl; //1
    cout << dsu_find(4) << endl; //1
    return 0;
}