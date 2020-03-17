vector<pair<int,double>>adj[10001];
unordered_map<string,int> mp;
int vis[10001];
double as;
class Solution {
public:

    int dfs(int s, int d)
    {
        if(s==d)
            return 1;
        
        for(auto x:adj[s])
        {
            int vt = x.first;
            double wt = x.second;
            
            if(!vis[vt])
            {
                vis[vt] = 1;
                as = (double)as*wt;
                if(dfs(vt,d)==1)
                    return 1;
                
                as = (double)as/wt;
                vis[vt] = 0;
                
            }   
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& qry) {
        
        for(int i=0;i<10000;i++)
            adj[i].clear();
        
        mp.clear();
        
        int n = eqn.size();
        vector<double>ans;
       
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(eqn[i][0])==mp.end())
            {
                mp[eqn[i][0]]=k;
                k++;
            }
            if(mp.find(eqn[i][1])==mp.end())
            {
                mp[eqn[i][1]]=k;
                k++;
            }
        }
        int nmb = mp.size();
        
//         for(auto it=mp.begin();it!=mp.end();it++)
//         {
//             cout<<it->first<<" "<<it->second<<endl;
//         }
        
        
        for(int i=0;i<n;i++)
        {
            adj[mp[eqn[i][0]]].push_back({mp[eqn[i][1]],val[i]});
            adj[mp[eqn[i][1]]].push_back({mp[eqn[i][0]],(double)(1/val[i])});
            
        }
        
        int m = qry.size();
        
        
        for(int i=0;i<m;i++)
        {
            for(int k=0;k<nmb;k++) vis[k]=0;
            
            string src = qry[i][0];
            string dst = qry[i][1];
            
            if(mp.find(src)==mp.end() || mp.find(dst)==mp.end())
            {
                ans.push_back(-1.0);
                continue;
            }
            
            int sc = mp[qry[i][0]];
            int dt = mp[qry[i][1]];
            
            as = 1;
            vis[sc]=1;
            if(dfs(sc,dt)==1)
                ans.push_back((double)as);
            else
                ans.push_back(-1.0);
            
        }
        
        
        return ans;
    }
};