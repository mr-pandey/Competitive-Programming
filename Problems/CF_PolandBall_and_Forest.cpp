//https://codeforces.com/contest/755/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define M 998244353

vector<int> parent, sze;
// vector<vector<int>> adj;

void init(int n)
{
    parent.resize(n);
    sze.resize(n);
    // cost.resize(n);
    // adj.resize(n);
    for(int i=0; i<n; i++)
    {
        // cin>>cost[i];
        sze[i]=1;
        parent[i]=i;
        // adj[i].clear();
    }
}

int find(int x)
{
    if(parent[x]==x)
        return x;
    return parent[x]=find(parent[x]);
}

void merge(int x, int y)
{
    int a=find(x), b=find(y);
    if(a!=b)
    {
        if(sze[b]>sze[a])
            swap(a, b);
        parent[b]=a;
        sze[a]+=sze[b];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans=0;
    cin>>n;
    init(n);
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        x--;
        merge(i, x);
    }
    unordered_set<int> s;
    for(int i=0; i<n; i++)
        s.insert(find(i));
    cout<<s.size();
    return 0;
}