#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>adj[20];
int vis[20],disc[20],low[20],timer,Apct,bridge;
bool AP[20];
vector<pair<int,int>>vec;

void dfs(int u,int par)
{
	vis[u] = 1;
	disc[u] = low[u] = timer++;
	int child = 0;

	for(auto v:adj[u])
	{
		if(!vis[v])
		{
			child++;
			dfs(v,u);
			low[u] = min(low[u],low[v]);

			//AP
			if(par==-1 && child>1) AP[u] = true,Apct++;
			if(par!=-1 && low[v]>=disc[u]) AP[u] = true, Apct++;

			//bridge
			if(low[v]>disc[u]) 
			{
				// bridge++;
				vec.push_back({u,v});
			}

		}
		else if(par!=v)
			low[u] = min(low[u],disc[v]);
 	}

}

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i=0;i<n;i++) 
	{
		vis[i]=0;
		disc[i] = 0;
		low[i] = INT_MAX;
		AP[i] = false;
	}

	timer=0;
	Apct=0;
	// bridge=0;

	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i,-1);

	// int ct=0;
	cout<<Apct<<endl;
	for(int i=0;i<n;i++)
	{
		if(AP[i]==true)
			cout<<i<<" ";
	}

	cout<<endl<<vec.size()<<endl;
	sort(vec.begin(),vec.end());

	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}
	
}
