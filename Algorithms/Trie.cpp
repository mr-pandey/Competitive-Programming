struct node
{
    bool leaf;
    map<char, node*> m;
};

node *root=NULL;

void push(string s)
{
    if(root==NULL)
        root=new node();
    node *tmp=root;
    for(auto x:s)
    {
        if(tmp->m.find(x)==tmp->m.end())
            tmp->m[x]=new node();
        tmp=tmp->m[x];
    }
    tmp->leaf=true;
}

bool find(string s)
{
    if(root==NULL)
        return false;
    node *tmp=root;
    for(auto x:s)
    {
        tmp=tmp->m[x];
        if(tmp==NULL)
            return false;
    }
    return tmp->leaf;
}
