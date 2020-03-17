#include <bits/stdc++.h>
using namespace std;

/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> adj[], bool vis[], int n)
{
    // Your code here
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        
        cout<<tp<<" ";
        
        for(auto v:adj[tp])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}

  // } Driver Code Ends