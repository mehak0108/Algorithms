#include <bits/stdc++.h>
using namespace std;
int a[1005],sze[1005];
int root(int i)
{
	while(a[i]!=i)
	{
		i = a[i];
	}
	return i;
}

bool find(int A,int B)
{
	if(a[A]==a[B])
		return true;
	return false;
}

void Union(int A,int B)
{
	int root_a = root(A);
	int root_b = root(B);

	if(sze[root_a]<sze[root_b])
	{
		a[root_a] = root_b;
		sze[root_b] += sze[root_a];
	}
	else
	{
		a[root_b] = root_a;
		sze[root_a] += sze[root_b];	
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	priority_queue<int,vector<int>,greater<int>>q;

	for(int i=0;i<n;i++)
	{
		a[i]=i;
		sze[i]=1;
	}
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		Union(x,y);
		for(int i=0;i<n;i++)
		{
		    if(a[i]==i)
			    q.push(sze[i]);
		}
		while(!q.empty())
		{
			cout<<q.top()<<" ";
			q.pop();
		}
		cout<<endl;
	}
}
