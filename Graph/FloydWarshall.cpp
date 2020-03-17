using namespace std;
#define INF 10000000
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=a[i][j];
            }
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                
                    if(dp[i][j]>dp[i][k]+dp[k][j] )
                        dp[i][j]=dp[i][k]+dp[k][j];
                
                }
            }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]!=INF)
                    cout<<dp[i][j]<<" ";
                else 
                    cout<<"INF"<<" ";
            }
            cout<<endl;
        }
        
    
    }
	return 0;
}