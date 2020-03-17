#include <bits/stdc++.h>
using namespace std;

struct trie
{
	trie *child[26];
	bool end;
	int weight;

	trie(int wt)
	{
		for(int i=0;i<26;i++)
			child[i] = NULL;
		weight = wt;
		end = false;
	}
};

void add(trie *head, string s, int wt)
{
	trie *curr = head;
	for(int i=0;i<s.length();i++)
	{
		int ind = s[i]-'a';
		if(!curr->child[ind])
		{
			curr->child[ind] = new trie(wt);
		}
		
		curr = curr->child[ind];
		// if(curr->weight < wt)
		// 	curr->weight = wt;
	}
	curr->end = true;
}

int search(trie *head, string p)
{
	trie *curr = head;
	for(int i=0;i<p.length();i++)
	{
		int ind = p[i]-'a';
		if(!curr->child[ind])
			return -1;
		
		curr = curr->child[ind];
		
	}
	return curr->weight;
}

void display(trie *head, string s, int lvl)
{
	if(head->end)
	{
		s[lvl] = '\0';
		cout<<s<<endl;
		return;
	}
	for(int i=0;i<26;i++)
	{
		if(head->child[i])
		{
			s[lvl] = i+'a';
			display(head->child[i],s,lvl+1);
		}
	}
}

int main()
{
	int n,q;
	cin>>n>>q;
	trie *head = new trie(-1);

	while(n--)
	{
		string s;
		int wt;
		cin>>s>>wt;
		add(head,s,wt);
	}

	string tmp;
	int lvl=0;
	display(head,tmp,lvl);

	// while(q--)
	// {
	// 	string p;
	// 	cin>>p;
	// 	cout<<search(head,p)<<endl;
	// }
}


/*
input
8 2
the 2
a 5
there 4 
answer 5
any 5
by 7
bye 9
their 7
*/