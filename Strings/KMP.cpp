#include <bits/stdc++.h>
using namespace std;
int lps[10];

void buildlps(string pat,int m)
{
	int i=0,len=0;
	lps[0]=0;

	i=1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
				len = lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}

	for(int i=0;i<m;i++)
		cout<<lps[i]<<" ";
}

void KMP(string txt, string pat)
{
	int n = txt.length();
	int m = pat.length();

	// cout<<n<<" "<<m;
	buildlps(pat,m);

	int i=0,j=0;
	while(i<n)
	{
		if(txt[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"ok: "<<i-j<<endl;
			j = lps[j-1];
		}
		
		else if(i<n && pat[j]!=txt[i])
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
		
	}
}

int main()
{
	string txt = "ABABDABACDABABCABAB"; 
    string pat = "ABABCABAB"; 

    // KMP(txt, pat);
    buildlps("ababa",5);
    // return 0; 
}
