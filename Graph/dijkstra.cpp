#include <bits/stdc++.h>
using namespace std;
int n,m;

int vis[10001],dst[10001];
#define F first
#define S second
#define pii pair<int,int>
vector<pii>adj[10001];

void dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dst[0]=0;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        
        // int dt = tmp.F;
        int u = tmp.S;
        
        if(!vis[u])
        {
            vis[u]=1;
            for(auto x:adj[u])
            {
                int v = x.F;
                int wt = x.S;
                if(dst[v]>dst[u]+wt)
                {
                    dst[v] = dst[u]+wt;
                    pq.push({dst[v],v});
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        adj[x].push_back({y,w});
    }
    
    for(int i=0;i<n;i++) 
    {
        vis[i]=0;
        dst[i] = INT_MAX;
    }
    
    dijkstra();
        
    for(int i=1;i<n;i++)
        cout<<dst[i]<<" ";
}