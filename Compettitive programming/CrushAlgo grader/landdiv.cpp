#include<bits/stdc++.h>

using namespace std;
int n, k;
int sum[110];
int mem[110][110][110][110][110];
int div( int l, int r, int pe, int mi, int ma )
{
    printf("%d %d %d %d %d\n",l,r,pe,mi,ma);
    if( mem[l][r][pe][mi][ma] != -1 )return mem[l][r][pe][mi][ma];
    if( pe == 1 ){
        int mit = min( mi, sum[r] - sum[l-1] );
        int mat = max( ma, sum[r] - sum[l-1] );
        //printf("%d %d %d %d %d\n",l,r,ma,mi,ma-mi);
        return mem[l][r][pe][mi][ma] = mat - mit;
    }
    int m = 1e9, mit = mi, mat = ma;
    for( int i = l ; i <= r && ( r - i ) >= pe - 1 ; i++ ){
        int le = sum[i] - sum[l-1];
        mit = mi, mat = ma;
        mat = max( ma, le );
        mit = min( mi, le );
        int tt = div( i + 1, r, pe - 1, mit, mat );
        m = min( m, tt );
        //printf("%d %d %d %d\n",i,r,tt,m);
    }
    return mem[l][r][pe][mi][ma] = m;
}
int main()
{
    memset( mem, -1, sizeof mem );
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        int tt;
        scanf("%d",&tt);
        sum[i] = sum[i-1] + tt;
    }
    div( 1, n, k, 1e9, 0 );
    printf("%d",mem[1][n][k]);
    return 0;
}
