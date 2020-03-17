#include <bits/stdc++.h>
using namespace std;

int a[510][510],vis[510][510],dist[510][510];
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
#define pii pair<int,int>
#define F first
#define S second
queue<pair<pii,int>>q;

bool check(int a,int b)
{
    return (a>=0 && a<n && b>=0 && b<m );
}

void bfs()
{
    while(!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        
        for(int k=0;k<4;k++)
        {
            int x1 = tmp.F.F + x[k];
            int y1 = tmp.F.S + y[k];
            
            if(check(x1,y1) && !vis[x1][y1])
            {
                dist[x1][y1] = tmp.S+1;
                vis[x1][y1] = 1;
                q.push({{x1,y1},dist[x1][y1]});
            }
        }
    }
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                vis[i][j]=0;
                dist[i][j]=INT_MAX;
                if(a[i][j])
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dist[i][j]=0;
                }
                
            }
        }
        
        bfs();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}