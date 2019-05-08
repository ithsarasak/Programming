#include <bits/stdc++.h>

using namespace std;
double n, a, b, ans;
int dp[2][2];
int main()
{
    scanf("%lf %lf %lf",&n,&a,&b);
    for( double i = 1 ; i <= n ; i += 1.0 ){
        int x = ((int)ceil(i/a))%2, y = ((int)ceil(i/b))%2;
        if( !dp[x][y] ){
            for( double j = 1 ; j <= n ; j += 1.0 )
                if( x == ((int)ceil(j/a))%2 || y == ((int)ceil(j/b))%2 )dp[x][y]++;
        }
        ans += dp[x][y];
    }
    printf("%.0lf",ans);
    return 0;
}
