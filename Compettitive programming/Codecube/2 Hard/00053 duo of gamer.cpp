#include <bits/stdc++.h>
using namespace std ;
const int N = 109;
int dp[2][N][N][69];
/// row A B K
main()
{
    int Q,n,A,B,k,i,j,x,d,in,a,b,l,r,xp ;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d %d %d",&n,&A,&B,&k);
        for(i=1;i<=A;i++)
            for(j=1;j<=B;j++)for(d=1;d<=60;d++)dp[0][i][j][d]=-INT_MAX;
        dp[0][A][B][30]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&l,&r,&xp);
            x=i&1;
            ///A
            for(a=1;a<=A;a++)for(b=1;b<=B;b++)
                for(d=1;d<=60;d++)dp[x][a][b][d]=dp[x^1][a][b][d];
            for(a=l+1;a<=A;a++)
            {
                for(b=1;b<=B;b++)
                {
                    for(d=1;d<=60;d++)
                    {
                        if(dp[x^1][a][b][d]>-1)
                        dp[x][a-l][b][d+1]=
                        max(dp[x^1][a][b][d]+xp,dp[x][a-l][b][d+1]);
                    }
                }
            }
            ///b
            for(a=1;a<=A;a++)
            {
                for(b=r+1;b<=B;b++)
                {
                    for(d=1;d<=60;d++)
                    {
                        if(dp[x^1][a][b][d]>-1)
                        dp[x][a][b-r][d-1]=
                        max(dp[x^1][a][b][d]+xp,dp[x][a][b-r][d-1]);
                    }
                }
            }
        }
        ///ans
        int ans=0;
        for(a=1;a<=A;a++)
        {
            for(b=1;b<=B;b++)
            {
                for(d=30-k;d<=30+k;d++)ans=max(ans,dp[n&1][a][b][d]);
            }
        }
        printf("%d\n",k==0?0:ans);
    }
}
