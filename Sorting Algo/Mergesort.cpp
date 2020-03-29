#include <bits/stdc++.h>

#define ONLINE_JUDGE  freopen("input","r",stdin); freopen("output","w",stdout);
#define MAX 		100001
#define ll          long long
#define ld          long double
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define lol         1000000007
#define endl        '\n'
#define debug(x)    cerr << #x << " = " << x << endl;

using namespace std;

ll merge(vi &a, int st, int mid, int ed, vi &v)
{
	int i = st, j = mid+1, k=st;
	ll ct=0;

	while(i<=mid && j<=ed)
	{
		if(a[i]<=a[j])
			v[k++] = a[i++];
		else
		{
			v[k++] = a[j++];
			ct += (mid-i+1);
		}
	}

	while(i<=mid)
		v[k++] = a[i++];
	while(j<=ed)
		v[k++] = a[j++];

	for(int i=st;i<=ed;i++)
		a[i] = v[i];

	return ct;
}

ll _mergesort(vi &a, int st,int ed, vector<int> &v)
{
	ll inv=0;
	if(st<ed)
	{
		ll mid = st + (ed-st)/2;
		inv = _mergesort(a,st,mid,v);
		inv += _mergesort(a,mid+1,ed,v);
		inv += merge(a,st,mid,ed,v);
	}

	return inv;
}


void solve()
{
	int n;
	cin>>n;
	vi a(n);

	rep(i,0,n)
		cin>>a[i];

	vector<int> v(n);
	cout<< _mergesort(a,0,n-1,v)<<endl;
	
}


int main()
{
	// ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}