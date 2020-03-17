#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define ONLINE_JUDGE  freopen("input","r",stdin); freopen("output","w",stdout);
const ll MAX = 100001;
pair<ll,pair<ll,ll>> p[MAX];
ll id[MAX], n,m;

void initialise(){
	for(int i=0;i<MAX;i++)
		id[i]=i;
}

ll root(ll x){
	while(id[x]!=x){
		id[x]=id[id[x]];
		x = id[x];
	}
	return x;
}

void union1(ll x,ll y){
	ll p = root(x);
	ll q = root(y);
	id[p] = id[q];
}

ll kruskal(){
	ll minCost=0,x,y,cost;
	for(int i=0;i<m;i++){
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x)!=root(y)){
			minCost += cost;
			union1(x,y);
		}
	}
	return minCost;
}


int main(){

	//ONLINE_JUDGE

	ll cost,x,y,minCost;
	initialise();

	//n nodes; m edges
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		cin>>x>>y>>cost;
		p[i] = make_pair(cost,make_pair(x,y));
	}
	sort(p,p+m);
	minCost = kruskal();
	cout<<minCost<<endl;

}

/*
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

Ans - 19
*/