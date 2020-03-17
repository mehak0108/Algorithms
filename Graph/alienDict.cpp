#include <bits/stdc++.h>
using namespace std;


int vis[27];

stack<int>s;

void dfs(int x,vector<int>adj[])
{
    vis[x]=1;
    for(int v:adj[x])
    {
        if(!vis[v])
            dfs(v,adj);
    }
    s.push(x);
}

string printOrder(string dict[], int N, int k)
{
   //Your code here
   vector<int>adj[27];
   string ans;
   for(int i=0;i<k;i++) vis[i]=0;
   // cout<<dict->length();

   for(int i=0;i<N-1;i++)
   {
       for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++)
       {
           if(dict[i][j]==dict[i+1][j])
                continue;
            else
            {
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                cout<<dict[i][j]-'a'<<" -> "<<dict[i+1][j]-'a';
                break;
            }
       }

   }
   
   // for(int i=0;i<adj->size();i++)
   // {
   //     for(int j=0;j<adj[i].size();j++)
   //     {
   //         cout<<i<<"->"<<adj[i][j]<<" ";
   //     }
   //     cout<<endl;
   // }
   
   for(int i=0;i<k;i++)
   {
        if(!vis[i])
            dfs(i,adj);
   }
   
   while(!s.empty())
   {
       int t=s.top();
       s.pop();
       ans.push_back(t+'a');
   }
   // cout<<ans;
  return ans;
   
}

int main()

{
    string dict[5] = { "baa", "abcd", "abca", "cab", "cad" };
    cout<<printOrder( dict,5,4);
}