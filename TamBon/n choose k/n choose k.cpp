#include<bits/stdc++.h>
long long b[1010][1010];
int i, j, n, k, q;
int main()
{
    b[0][0] = 1;
    for( i = 1 ; i <= 1000 ; i++ ){
        for( j = 0 ; j <= i ; j++ ){
            if( j == 0 ){
                b[i][0] = 1;
            }
            else{
                b[i][j] = ( b[i - 1][j - 1] + b[i - 1][j] ) % 1000000007;
            }
        }
    }
    scanf("%d",&q);
    for( i = 0 ; i < q ; i++ ){
        scanf("%d %d",&n,&k);
        printf("%d\n",b[n][k]);
    }
    return 0;
}
