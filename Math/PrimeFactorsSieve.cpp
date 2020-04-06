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


// takes O(logn) in worst case
int spf[MAX];

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}

void sieve()
{
	spf[1] = 1; 
    for (int i=2; i<MAX; i++) 
        spf[i] = i; 
  
    for (int i=4; i<MAX; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAX; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAX; j+=i)
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

void solve()
{
	int x;
	cin>>x;

	vector<int> ans = getFactorization(x);

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	
}


int main()
{
	//ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;

	sieve();
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}