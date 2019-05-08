#include<bits/stdc++.h>

using namespace std;
long long n, k;
long long cnr[51010][1010], mic[110][1010], soldier[50010],qs[110], c[110];
long long mod = 1000000007;
int main()
{
    cnr[0][0] = 1;
    for( int i = 1 ; i <= 50000 ; i++ ){
        for( int j = 0 ; j <= min( i, 1000 ) ; j++ ){
            if( j == 0 ) cnr[i][j] = cnr[i-1][j];
            else cnr[i][j] = cnr[i-1][j-1] + cnr[i-1][j];
            cnr[i][j] %= mod;
        }
    }
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&soldier[i]);
    }
    sort( soldier + 1, soldier + n + 1 );
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(soldier[i]!=soldier[i-1])cnt++;
        c[cnt]++;
    }
    for( int i = 1 ; i <= cnt ; i++ ){
        qs[i] = qs[i-1] + c[i];
    }
    for(int i=0;i<=cnt;i++){
        mic[i][0] = 1;
    }
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=k;j++){
            for(int l=0;l<=min( c[i], k ) ;l++){
                if( j >= l ){
                    mic[i][j] += mic[i-1][j-l] * cnr[qs[i-1]-1+l][l];
                    mic[i][j] %= mod;
                }
            }
        }
    }
    printf("%lld",mic[cnt][k]);
    return 0;
}
