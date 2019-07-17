#include<bits/stdc++.h>

using namespace std;
int s;
long long fen[1200][1200];
int main()
{
    while( 1 ){
        int op;
        scanf("%d",&op);
        if( op == 0 ){
            scanf("%d",&s);
        }
        else if( op == 1 ){
            int x, y;
            long long va;
            scanf("%d %d %lld",&x,&y,&va);
            x++, y++;
            for( int i = x ; i <= s ; i+=(i&-i) ){
                for( int j = y ; j <= s ; j+=(j&-j) ){
                    fen[i][j] += va;
                }
            }
        }
        else if( op == 2 ){
            int l, b, r, t;
            scanf("%d %d %d %d",&l,&b,&r,&t);
            l++,b++,r++,t++;
            long long sum1=0,sum2=0,sum3=0,sum4=0;
            for( int i = r ; i > 0 ; i -= ( i & -i ) ){
                for( int j = t ; j > 0 ; j -= ( j & -j ) ){
                    sum1 += fen[i][j];
                }
            }
            for( int i = l-1 ; i > 0 ; i -= ( i & -i ) ){
                for( int j = t ; j > 0 ; j -= ( j & -j ) ){
                    sum2 += fen[i][j];
                }
            }
            for( int i = r ; i > 0 ; i -= ( i & -i ) ){
                for( int j = b-1 ; j > 0 ; j -= ( j & -j ) ){
                    sum3 += fen[i][j];
                }
            }
            for( int i = l-1 ; i > 0 ; i -= ( i & -i ) ){
                for( int j = b-1 ; j > 0 ; j -= ( j & -j ) ){
                    sum4 += fen[i][j];
                }
            }
            printf("%lld\n",sum1+sum4-sum2-sum3);
        }
        else{
            break;
        }
    }
    return 0;
}
