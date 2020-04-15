#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
int t, ma[N][N], cnt[N];
int main()
{
    scanf("%d",&t);
    for( int rou = 1 ; rou <= t ; rou++ ) {
        int n, ans = 0, row = 0, col = 0;
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ) {
            for( int j = 1 ; j <= n ; j++ ) {
                scanf("%d",&ma[i][j]);
            }
        }
        for( int i = 1 ; i <= n ; i++ ) ans += ma[i][i];
        for( int i = 1 ; i <= n ; i++ ) {
            memset( cnt, 0, sizeof cnt );
            for( int j = 1 ; j <= n ; j++ ) {
                if( cnt[ma[i][j]] ) {
                    row++;
                    break;
                }
                cnt[ma[i][j]]++;
            }
        }
        for( int j = 1 ; j <= n ; j++ ) {
            memset( cnt, 0, sizeof cnt );
            for( int i = 1 ; i <= n ; i++ ) {
                if( cnt[ma[i][j]] ) {
                    col++;
                    break;
                }
                cnt[ma[i][j]]++;
            }
        }
        printf("Case #%d: %d %d %d\n",rou,ans,row,col);
    }
    return 0;
}