#include<bits/stdc++.h>

using namespace std;
vector< int > g[100010];
int n, q, indg[100010];
int e[200010], l[200010], h[200010], rmq[20][200010], rt, si, lg;
void dfs( int no, int lv )
{
    e[si] = no;
    l[si] = lv;
    si++;
    for( int i = 0 ; i < g[no].size() ; i++ ){
        dfs( g[no][i] , lv + 1 );
        e[si] = no;
        l[si] = lv;
        si++;
    }
    return ;
}
int main()
{
    memset( h, 127, sizeof h );
    scanf("%d",&n);
    for( int i = 0 ; i < n - 1 ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        indg[t]++;
        g[f].push_back( t );
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( !indg[i] ){
            rt = i;
            break;
        }
    }
    dfs( rt, 0 );
    //cout << si << endl;
    for( int i = 0 ; i < si ; i++ ){
        h[e[i]] = min( h[e[i]], i );
    }
    lg = log2( si );
    for( int i = 0 ; i < si ; i++ ){
        rmq[0][i] = i;
    }
    /*for( int i = 0 ; i < si ; i++ ){
        printf("%d ",e[i]);
    }
    printf("\n");*/
    for( int i = 1 ; i <= lg ; i++ ){
        for( int j = 0 ; j < si ; j++ ){
            if( j + (1<<(i-1)) < si ){
                if( l[rmq[i-1][j]] <= l[rmq[i-1][j+(1<<(i-1))]] ){
                    rmq[i][j] = rmq[i-1][j];
                }
                else{
                    rmq[i][j] = rmq[i-1][j + (1<<(i-1))];
                }
            }
            else{
                rmq[i][j] = rmq[i - 1][j];
            }
        }
    }
    /*for( int i = 0 ; i <= lg ; i++ ){
        for( int j = 0 ; j < si ; j++ ){
            printf("%d ",rmq[i][j]);
        }
        printf("\n");
    }*/
    scanf("%d",&q);
    while( q-- ){
        int f, t;
        scanf("%d %d",&f,&t);
        if( h[f] > h[t] ) swap( f, t );
        int lg2 = log2( h[t] - h[f] + 1 );
        if( l[rmq[lg2][h[f]]] <= l[rmq[lg2][h[t]-(1<<lg2)+1]] ){
            printf("%d\n",e[rmq[lg2][h[f]]] );
        }
        else{
            printf("%d\n",e[rmq[lg2][h[t]-(1<<lg2)+1]]);
        }
    }
}
/*13
1 2
1 3
2 9
2 6
2 8
6 10
6 5
3 7
7 11
7 13
13 4
13 12
5
10 5*/

