vector<pair<int,int>>adj[10005];
int vis[10005];
#define pii pair<int,int>
#define F first
#define S second
long long cst;
class Solution {
public:
    void prims()
    {
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto tp = pq.top();
            pq.pop();
            
            int v = tp.S;
            if(!vis[v])
            {
                vis[v]=1;
                
                cst+= tp.F;
                for(auto x:adj[v])
                {
                    int y = x.F;
                    if(!vis[y])
                        pq.push({x.S,y});
                }
            }
        }
        
    }
    int minimumCost(int n, vector<vector<int>>& g) {
        
        for(int i=0;i<10004;i++) adj[i].clear();
        
        for(int i=0;i<g.size();i++)
        {
            int u = g[i][0], v = g[i][1], w =  g[i][2];
            u--;v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        for(int i=0;i<n;i++) vis[i]=0;
        
        cst=0;
        prims();
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
                return -1;
        }
        return cst;
    }
};