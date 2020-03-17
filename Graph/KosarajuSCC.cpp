#include<bits/stdc++.h>
using namespace std;
vector<int>adj[20];
vector<int>rev[20];
int vis[20],n,m;
stack<int>s;
vector<int>val;

void dfs1(int v)
{
    vis[v]=1;
    for(auto x:adj[v])
    {
        if(!vis[x])
            dfs1(x);
    }
    s.push(v);
}

void dfs2(int v)
{
    vis[v]=1;
    val.push_back(v);
    for(auto x:rev[v])
    {
        if(!vis[x])
            dfs2(x);
    }
}

int main()
{
    s.empty();
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }
    
    for(int i=0;i<n;i++) vis[i]=0;
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    
    for(int i=0;i<n;i++) vis[i]=0;
    
    int od=0,ev=0;
    while(!s.empty())
    {
        val.clear();
        int a = s.top();
        // cout<<a<<" ";
        s.pop();
        if(!vis[a])
        {
            dfs2(a);
            if(val.size()%2)
                od += val.size();
            else
                ev += val.size();
        }
    }
    
    cout<<od-ev;
    
}