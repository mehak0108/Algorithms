/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method 

Given an adjacency matrix representation of a graph g having 0 based index your task is to complete the function isBipartite which returns true if the graph is a bipartite graph else returns false.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer v denoting the no of vertices of the graph then in the next line are v*v space separated values of the adjacency matrix representation of the graph g.

Output:
For each test case in a new line output will be 1 if the graph is bipartite else 0.

Constraints:
1<=T<=100
1<=v<=15
0<=g[][]<=1

Example(To be used only for expected output):
Input:
2
4
0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 0
3
0 1 0 0 0 1 1 0 0
Output:
1
0


*/
int v;
int vis[20];
int color[20];
bool ans;

void util(int G[][MAX],int s,int col)
{
    vis[s] = true;
    color[s] = col;
    for(int i=0;i<v;i++)
    {
        if(G[s][i])
        {
            if(!vis[i])
                util(G,i,1^color[s]);
            else 
                if(color[i]==color[s])
                    ans=false;
        }
    }
}
bool isBipartite(int G[][MAX],int V)
{
     //Your code here
     ans = true;
     v=V;
     for(int i=0;i<v;i++)
     {
         vis[i]=0;
        //  color[i]=-1;
     }
     for(int i=0;i<v;i++)
     {
         if(!vis[i])
            util(G,i,0);
     }
     return ans;
}