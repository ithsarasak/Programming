#include<bits/stdc++.h>

using namespace std;
int n, m, t;
int ma[1010][1010];
int fen[1010];
int ans = 1e9;
int main()
{
    scanf("%d %d %d",&n,&m,&t);
    for( int i = 0 ; i < n ; i++ ){
        int r, c;
        scanf("%d %d",&r,&c);
        r++, c++;
        ma[r][c] = 1;
    }
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            for( int k = j ; k <= m ; k += ( k & -k ) ){
                fen[k] += ma[i][j];
            }
            int sum = 0;
            for( int k = j ; k > 0 ; k -= ( k & -k ) ){
                sum += fen[k];
            }
            if( sum < t )continue;
            int l = 1, r = j;
            while( l < r ){
                int mid = ( l + r + 1 ) / 2;
                int sum1 = 0;
                for( int k = mid - 1 ; k > 0 ; k -= ( k & -k ) ){
                    sum1 += fen[k];
                }
                if( sum - sum1 < t )r = mid - 1;
                else l = mid;
            }
            //printf("%d %d %d\n",i,j,l);
            ans = min( ans, i*(j-l+1) );
        }
    }
    printf("%d",ans);
    return 0;
}
