#include<bits/stdc++.h>

using namespace std;
int n, k, mi = 1e9;
int permu[25], c[25][25];
void play( int idx, int num, int none , int nze )
{
    permu[idx] = num;
    if( idx == n ){
        int zero[25], one[25], sz = 0 , so = 0;
        for( int i = 1 ; i <= n ; i++ ){
            printf("%d ",permu[i]);
            if( permu[i] ){
                one[so] = i;
                so++;
            }
            else{
                zero[sz] = i;
                sz++;
            }
        }
        printf("\n");
        int sum = 0;
        for( int i = 0 ; i < sz ; i++ ){
            int minn = 1e9;
            for( int j = 0 ; j < so ; j++ ){
                minn = min( minn, c[zero[i]][one[j]] );
            }
            sum += minn;
        }
        mi = min( mi, sum );
    }
    if( nze < n - k ){
        play( idx + 1, 0, none, nze + 1 );
    }
    if( none < k ){
        play( idx + 1, 1, none + 1, nze );
    }
    return ;
}
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            scanf("%d",&c[i][j]);
        }
    }
    if( n > k ) play( 1, 0, 0, 1 );
    play( 1, 1, 1, 0 );
    printf("%d",mi);
    return 0;
}
*/
