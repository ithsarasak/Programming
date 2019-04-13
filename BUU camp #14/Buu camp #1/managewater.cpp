#include<bits/stdc++.h>

using namespace std;

int n, q, x, y ,c, x1, x2, y3, y2, sum;
int fenwick[2020][2020];
int main()
{
    scanf("%d %d",&q,&n);
    while( 1 ){
        cin >> q;
        if( q == 3 ){
            break;
        }
        if( q == 1 ){
            scanf("%d %d %d",&x,&y,&c);
            x++, y++;
            for( int i = x ; i <= n ; i += ( i & -i ) ){
                for( int j = y ; j <= n ; j += ( j & -j ) ){
                    fenwick[i][j] += c;
                }
            }
        }
        else if( q == 2 ){
            sum = 0;
            scanf("%d %d %d %d",&x1,&y3,&x2,&y2);
            x2++, y2++;
            for( int i = x2 ; i > 0 ; i -= ( i & -i) ){
                for( int j = y2 ; j > 0 ; j -= ( j & -j ) ){
                    sum += fenwick[i][j];
                }
            }
            for( int i = x1 ; i > 0 ; i -= ( i & -i) ){
                for( int j = y2 ; j > 0 ; j -= ( j & -j ) ){
                    sum -= fenwick[i][j];
                }
            }
            for( int i = x2 ; i > 0 ; i -= ( i & -i) ){
                for( int j = y3 ; j > 0 ; j -= ( j & -j ) ){
                    sum -= fenwick[i][j];
                }
            }
            for( int i = x1 ; i > 0 ; i -= ( i & -i) ){
                for( int j = y3 ; j > 0 ; j -= ( j & -j ) ){
                    sum += fenwick[i][j];
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}
