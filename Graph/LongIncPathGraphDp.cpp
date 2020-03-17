int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int dp[500][500],vis[500][500];


class Solution {
public:
    
    bool check(int a,int b, vector<vector<int>>& A )
    {
        return (a>=0 && a<A.size() && b>=0 && b<A[0].size());
    }
    int dfs(int i,int j,vector<vector<int>>& A)
    {
        // vis[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int val=1;
        
        for(int k=0;k<4;k++)
        {
            int x1 = i+x[k];
            int y1 = j+y[k];
            if(check(x1,y1,A) && A[i][j]<A[x1][y1])
            { 
                val = max(val,1+dfs(x1,y1,A));
            }
        }
        return dp[i][j] = val;
    }
    
    int longestIncreasingPath(vector<vector<int>>& A) {
        int n = A.size();
        int ans=0;
        if(n==0) return n;
        int m = A[0].size();
        
        ans = INT_MIN;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++) 
            {
                vis[i][j]=0;
                dp[i][j]=-1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if(!vis[i][j])
                if(dp[i][j]==-1)
                    dfs(i,j,A);

            }
        }
        
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans = max(ans,dp[i][j]); 
        
        return ans;
        
    }
};