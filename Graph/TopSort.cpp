#include <bits/stdc++.h>
using namespace std;

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/
stack<int> st;
int vis[55];

void dfs(int u,vector<int> adj[])
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(!vis[v])
            dfs(v,adj);
    }
    st.push(u);
}

int* topoSort(int n, vector<int> adj[])
{
    // Your code here
    st.empty();
    
    for(int i=0;i<55;i++) vis[i]=0;
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i,adj);
    }
    
    int *arr = new int[50];
    int k=0;
    while(!st.empty())
    {
        arr[k++] = st.top();
        st.pop();
    }
    return arr;
}



// { Driver Code Starts.

/*  Function to check if elements returned by user 
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}

// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}
  // } Driver Code Ends