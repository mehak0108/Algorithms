/*
Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the square chessboard. The next line contains the X-Y coordinates of the knight. The next line contains the X-Y coordinates of the target. 

Output:
Print the minimum steps the Knight will take to reach the target position.

Constraints:
1<=T<=100
1<=N<=20
1<=knight_pos,targer_pos<=N

Example:
Input:
2
6
4 5
1 1
20
5 7
15 20

Output:
3
9
*/

#include <bits/stdc++.h>
using namespace std;
int x[8] = {1,1,2,2,-1,-1,-2,-2};
int y[8] = {2,-2,1,-1,2,-2,1,-1};
int vis[50][50];
#define pii pair<int,int>
#define F first
#define S second
int n;

bool check(int a,int b)
{
    return (a>=0 && a<n && b>=0 && b<n);
}
int bfs(int sx,int sy,int dx,int dy)
{
    queue<pair<pii,int>>q;
    q.push({{sx,sy},0});
    vis[sx][sy]=1;
    
    while(!q.empty())
    {
        auto tp = q.front();
        q.pop();
        
        if(tp.F.F==dx && tp.F.S==dy)
            return tp.S;
        
        for(int k=0;k<8;k++)
        {
            int x1 = tp.F.F + x[k];
            int y1 = tp.F.S + y[k];
            
            if(check(x1,y1) && !vis[x1][y1])
            {
                q.push({{x1,y1},tp.S+1});
                vis[x1][y1]=1;
            }
        }
    }
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<50;i++) for(int j=0;j<50;j++) vis[i][j]=0;
        int sx,sy,dx,dy;
        cin>>n;
        cin>>sx>>sy>>dx>>dy;
        sx--;sy--;dx--;dy--;
        int ans = bfs(sx,sy,dx,dy);
        cout<<ans<<endl;
    
    }
	return 0;
}

