vector<int> parent, sze;

void init(int n)
{
    parent.resize(n);
    sze.resize(n);
    for(int i=0; i<n; i++)
    {
        sze[i]=1;
        parent[i]=i;
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
