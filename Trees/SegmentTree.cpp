#include <bits/stdc++.h>
using namespace std;
int a[100005],tree[2000005];

void build(int st,int ed,int i)
{
	if(st==ed)
	{
		tree[i] = a[st];
	}
	else
	{
		int mid = (st+ed)/2;
		build(st,mid,2*i+1);
		build(mid+1,ed,2*i+2);
		tree[i] = min(tree[2*i+1],tree[2*i+2]);
	}
}

int query(int l,int r,int st,int ed,int i)
{
	if(l>ed || r<st)
		return INT_MAX;
	
	if(st>=l && r>=ed)
		return tree[i];
	int mid = (st+ed)/2;
	int p1 = query(l,r,st,mid,2*i+1);
	int p2 = query(l,r,mid+1,ed,2*i+2);
	return min(p1,p2);
}

void update(int x,int y,int st,int ed,int i)
{
	if(st==ed)
	{
		tree[i] = y;
		a[x] = y;
	}
	else 
	{
		int mid = (st+ed)/2;
		if(x<=mid && x>=st)
			update(x,y,st,mid,2*i+1);
		else
			update(x,y,mid+1,ed,2*i+2);
		tree[i] = min(tree[2*i+1],tree[2*i+2]);
	}
}


int main()
{
	int n,q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	build(0,n-1,0);
	int ans;
	while(q--)
	{
		char ch;
		int x,y;
		cin>>ch>>x>>y;
		if(ch=='q')
		{
			x--;y--;
			cout<<query(x,y,0,n-1,0)<<endl;
		}
		else
		{
			x--;
			update(x,y,0,n-1,0);
		}
	}
}
