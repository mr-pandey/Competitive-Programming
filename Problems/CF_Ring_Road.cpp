//https://codeforces.com/contest/24/problem/A

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define M 998244353963

vector<vector<int>> adj;
vector<bool> vis;
map<pair<int, int>, int> m;
vector<int> path;

void dfs(int v)
{
    vis[v]=true;
    for(auto x:adj[v])
        if(!vis[x])
            dfs(x);
    path.pb(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    adj.resize(n);
    vis.resize(n);
    for(int i=0; i<n; i++)
        vis[i]=false;
    while(n--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        m[{u, v}]=0;
        m[{v, u}]=w;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    n=path.size();
    int ans1=0, ans2=0;
    for(int i=0; i<n; i++)
        ans1+=m[{path[i], path[(i+1)%n]}];
    reverse(path.begin(), path.end());
    for(int i=0; i<n; i++)
        ans2+=m[{path[i], path[(i+1)%n]}];
    cout<<min(ans1, ans2);
    return 0;
}