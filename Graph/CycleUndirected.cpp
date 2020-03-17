#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
int vis[110];

bool dfs(int src,int par,vector<int> adj[])
{
    vis[src]=1;
    
    bool ret = false;
    for(auto x:adj[src])
    {
        if(!vis[x])
            ret |= dfs(x,src,adj);
        else if(par!=x)
            return true;
    }
    
    return ret;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool ans = false;
   for(int i=0;i<V;i++) vis[i]=0;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            ans |= dfs(i,-1,adj);
    }
   return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
