#include<bits/stdc++.h>

using namespace std;
int red[1000010], green[1000010], blue[1000010], n, m, c;
char iz[1000010], rgb[3] = { 'R', 'G', 'B' };
int findsum( int a, int b , int fenwick[] )
{
    int sum1 = 0;
    while( b > 0 ){
        sum1 += fenwick[b];
        b -= ( b & -b );
    }
    while( a > 0 ){
        sum1 -= fenwick[a];
        a -= ( a & -a );
    }
    return sum1;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        if( i % 3 == 1 ){
            int t = i;
            while( t <= n ){
                red[t] += 1;
                t += ( t & -t );
            }
            iz[i] = 'R';
        }
        else if( i % 3 == 2 ){
            int t = i;
            while( t <= n ){
                green[t] += 1;
                t += ( t & -t );
            }
            iz[i] = 'G';
        }
        else{
            int t = i;
            while( t <= n ){
                blue[t] += 1;
                t += ( t & -t );
            }
            iz[i] = 'B';
        }
    }
    /*int sumx = findsum( 0, n , red );
    int sumy = findsum( 0, n , green );
    int sumz = findsum( 0, n , blue );
    printf("r %d g %d b %d\n",sumx,sumy,sumz);*/
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d",&c);
        if( c == 1 ){
            int idx;
            char to;
            scanf("%d %c",&idx,&to);
            if( iz[idx] == 'R' ){
                int t = idx;
                while( t <= n ){
                    red[t] -= 1;
                    t += ( t & -t );
                }
            }
            else if( iz[idx] == 'G' ){
                int t = idx;
                while( t <= n ){
                    green[t] -= 1;
                    t += ( t & -t );
                }
            }
            else{
                int t = idx;
                while( t <= n ){
                    blue[t] -= 1;
                    t += ( t & -t );
                }
            }
            if( to == 'R' ){
                int t = idx;
                while( t <= n ){
                    red[t] += 1;
                    t += ( t & -t );
                }
            }
            else if( to == 'G' ){
                int t = idx;
                while( t <= n ){
                    green[t] += 1;
                    t += ( t & -t );
                }
            }
            else{
                int t = idx;
                while( t <= n ){
                    blue[t] += 1;
                    t += ( t & -t );
                }
            }
            iz[idx] = to;
        }
        else{
            int f, t;
            scanf("%d %d",&f,&t);
            int sumx = findsum( f - 1, t , red );
            int sumy = findsum( f - 1, t , green );
            int sumz = findsum( f - 1, t , blue );
            //printf("r %d g %d b %d\n",sumx,sumy,sumz);
            int m = 0;
            m = max( max( sumx, sumy ), sumz );
            int cc = 0, color;
            if( m == sumx ){
                color = 0;
                cc++;
            }
            if( m == sumy ){
                color = 1;
                cc++;
            }
            if( m == sumz ){
                color = 2;
                cc++;
            }
            if( cc > 1 ){
                printf("None\n");
            }
            else{
                printf("%c\n",rgb[color]);
            }
        }
    }
    return 0;
}
