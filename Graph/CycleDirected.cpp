/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
int vis[110];

bool dfs(int s,vector<int> adj[])
{
    vis[s]=1;
    bool ret=false;
    for(int v:adj[s])
    {
        if(!vis[v])
            ret = ret | dfs(v,adj);
        else
            if(vis[v]==1)
                return true;
    }
    vis[s]=2;
    return ret;
}

bool isCyclic(int v, vector<int> adj[])
{
    // Your code here
    bool ans=false;
    for(int i=0;i<v;i++) vis[i]=0;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
            ans = ans | dfs(i,adj);
    }
    return ans;
}