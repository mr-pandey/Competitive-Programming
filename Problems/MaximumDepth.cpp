//InterviewBit : Maximum Depth

map<int, set<int>> m;
int level=1;
vector<vector<int>> adj;
vector<bool> vis;

void bfs(int v, vector<int> &val)
{
    queue<int> q;
    q.push(v);
    vis[v]=true;
    vector<int> vec;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(auto x:adj[f])
            if(!vis[x])
            {
                vis[x]=true;
                vec.push_back(x);
            }
        if(q.empty())
        {
            for(auto x:vec)
            {
                m[level].insert(val[x]);
                q.push(x);
            }
            vec.clear();
            level++;
        }
    }
}

vector<int> Solution::solve(int n, vector<int> &U, vector<int> &V, vector<int> &val, vector<int> &L, vector<int> &X)
{
    adj.resize(n);
    vis.resize(n);
    for(int i=0; i<n; i++)
        vis[i]=false;
    m[0]={val[0]};
    int mm=U.size();
    for(int i=0; i<mm; i++)
    {
        int u=U[i]-1, v=V[i]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0, val);
    int q=L.size();
    vector<int> sol;
    for(int i=0; i<q; i++)
    {
        int l=L[i]%(level-1), x=X[i];
        if(m[l].lower_bound(x)==m[l].end())
            sol.push_back(-1);
        else
            sol.push_back(*(m[l].lower_bound(x)));
    }
    return sol;
}