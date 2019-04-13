#include<bits/stdc++.h>
using namespace std;
struct no{
    int t, d, bm;
    bool operator<( const no &k )const{
        return d > k.d;
    }
}te;
int fw[210][210];
int n, m, k;
int va[210];
int mark[210][32100];
int dis[210][32100];
int fri[210], s;
priority_queue< no > pq;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    fri[s] = 1;
    s++;
    for( int i = 0 ; i < k ; i++ ){
        int w;
        scanf("%d",&w);
        va[w] = 1 << i;
        fri[s] = w;
        s++;
    }
    fri[s] = n;
    s++;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( i == j )fw[i][j] = 0;
            else fw[i][j] = 1e9;
        }
    }
    for( int i = 0 ; i < m ; i++ ){
        int f, t, w;
        scanf("%d %d %d",&f,&t,&w);
        fw[f][t] = min( fw[f][t], w );
        fw[t][f] = min( fw[t][f], w );
    }
    for( int l = 1 ; l <= n ; l++ ){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                fw[i][j] = min( fw[i][j] , fw[i][l] + fw[l][j] );
            }
        }
    }
    pq.push({1,0,0});
    while( !pq.empty() ){
        te = pq.top();
        pq.pop();
        if( mark[te.t][te.bm] )continue;
        mark[te.t][te.bm] = 1;
        if( te.t == n && te.bm == ( 1 << k ) - 1 ){
            printf("%d",te.d);
            return 0;
        }
        for( int i = 0 ; i < s ; i++ ){
            if( te.t == fri[i] )continue;
            if( !mark[fri[i]][te.bm|va[fri[i]]] ){
                if( dis[fri[i]][te.bm|va[fri[i]]] == 0 || dis[fri[i]][te.bm|va[fri[i]]] > te.d + fw[te.t][fri[i]] ){
                    dis[fri[i]][te.bm|va[fri[i]]] = te.d + fw[te.t][fri[i]];
                    pq.push({ fri[i], te.d + fw[te.t][fri[i]] , te.bm|va[fri[i]] });
                }
            }
        }
    }
    return 0;
}
/*
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
*/
