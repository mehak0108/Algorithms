vector<int>adj[15];
int vis[15];

bool check()
{
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            return false;
    }
    return true;
}

bool dfs(int src)
{
    if(check())
        return true;
    // if(ct==n)
    //     return true;
    for(auto x:adj[src])
    {
        if(!vis[x])
        {
            vis[x]=1;
            if(dfs(x))
                return true;
            vis[x]=0;
        }
    }
    return false;
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=0;i<n;i++) vis[i]=0;
        bool ans=false;
        
        for(int i=0;i<n;i++)
        {
            
            // vis[i]=1;
            // int ct=1;
            ans |= dfs(i);    
        }
        
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        for(int i=0;i<n;i++) adj[i].clear();
    }
	return 0;
}