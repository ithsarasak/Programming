#include <bits/stdc++.h>
using namespace std;
int q, ch, n;
int deg[100010];
long long sum, r[100010], l[100010];
int main()
{
    scanf("%d",&q);
    while( q-- ){
        sum = 0, ch = 0;
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&deg[i]);
            sum += ( long long )deg[i];
        }
        sort( deg + 1, deg + 1 + n, greater<int>() );
        for( int i = 1 ; i <= n ; i++ ){
            l[i] = l[i-1] + ( long long )deg[i];
        }
        for( int i = n ; i >= 1 ; i-- ){
            r[i] = r[i+1] + ( long long )deg[i];
        }
        for( int i = 1 ; i <= n ; i++ ){
            int le = i + 1, ri = n;
            if( deg[le] < i ){
                if( l[i] > r[i+1] + ( long long )i*( long long )(i-1) ){
                    ch = 1;
                    break;
                }
            }
            else if( deg[ri] >= i ){
                if( l[i] > ( long long )i*( long long )( n - 1 ) ){
                    ch = 1;
                    break;
                }
            }
            else{
                while( le < ri ){
                    int mid = ( le + ri + 1 ) / 2;
                    if( deg[mid] >= i ){
                        le = mid;
                    }
                    else ri = mid - 1;
                }
                if( l[i] > ( long long )i*( long long )(i-1) + ( long long )i*( long long )(le-i) + r[le+1] ){
                    ch = 1;
                    break;
                }
            }
        }
        if( sum%2 == 1 || ch ) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
