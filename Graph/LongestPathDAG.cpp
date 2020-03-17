vector<int>adj[5005];
int vis[5005];
int dp[5005],ans;

class Solution {
public:
    
    bool cyc(int v)
    {
        vis[v]=1;
        bool ret = false;
        
        for(auto x: adj[v])
        {
            if(vis[x]==1)
                return true;
            else if(!vis[x])
                ret |= cyc(x);
        }
        vis[v]=2;
        return ret;
    }
    
    void dfs(int v)
    {
        // if(dp[v]!=-1) return;
        
        vis[v]=1;
        for(auto x:adj[v])
        {
            
            
            if(!vis[x])
                dfs(x);
            dp[v] = max(1+dp[x],dp[v]);
            // ans = max(ans,dp[x]);
        }
    }
    int minimumSemesters(int n, vector<vector<int>>& g) {
        
        for(int i=0;i<5004;i++) adj[i].clear();
        
        for(int i=0;i<g.size();i++)
        {
            int u = g[i][0], v = g[i][1];
            u--;v--;
            adj[u].push_back(v);
        }
        
        for(int i=0;i<n;i++) vis[i]=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && cyc(i))
                return -1;
        }
        
        for(int i=0;i<n;i++) dp[i]=1;
        for(int i=0;i<n;i++) vis[i]=0;
        ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i);
        }
        
        for(int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        
        return ans;
    }
};