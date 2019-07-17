#include <bits/stdc++.h>
using namespace std;
struct no{
    int t, d, bm;
    bool operator<( const no &k )const{
        return d > k.d;
    }
}t;
struct gg{
    int t, d;
};
vector<gg> g[19];
int fw[210][210];
int n, m, k;
int va[19];
int dis[19][33000];
vector<int> fri, fri2;
priority_queue< no > pq;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    fri.emplace_back( 1 );
    fri2.emplace_back( 1 );
    for( int i = 0 ; i < k ; i++ ){
        int w;
        scanf("%d",&w);
        fri.emplace_back( w );
        fri2.emplace_back( w );
    }
    fri.emplace_back( n );
    fri2.emplace_back( n );
    sort( fri2.begin(), fri2.end() );
    for( int i = 0 ; i < fri.size() ; i++ )fri[i] = lower_bound( fri2.begin(), fri2.end(), fri[i] ) - fri2.begin();
    for( int i = 1 ; i < fri.size() - 1 ; i++ )va[i+1] = 1 << ( i - 1 );
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
    for( int i = 0 ; i < fri.size() ; i++ ){
        for( int j = 0 ; j < fri.size() ; j++ ){
            if( i == j )continue;
            g[i+1].push_back({ j+1, fw[fri2[fri[i]]][fri2[fri[j]]] });
            //printf("%d %d %d\n",i+1,j+1,fw[fri2[fri[i]]][fri2[fri[j]]]);
        }
    }
    // for( int i = 0 ; i < fri.size() ; i++ ){
    //     printf("%d %d\n",fri[i],fri2[fri[i]]);
    // }
    // for( int i = 1 ; i <= fri.size() ; i++ ){
    //     for( int j = 0 ; j < g[i].size() ; j++ ){
    //         printf("%d %d %d\n",fri2[i-1],fri2[g[i][j].t-1],g[i][j].d);
    //     }
    // }
    for( int i = 0 ; i < 19 ; i++ )for( int j = 0 ; j < 33000 ; j++ )dis[i][j] = 1e9;
    pq.push({1,0,0});
    dis[1][0] = 0;
    while( !pq.empty() ){
        t = pq.top();
        pq.pop();
        //printf("%d %d %d %d\n",t.t,t.d,t.bm,va[t.t]);
        for( int i = 0 ; i < g[t.t].size() ; i++ ){
            if( dis[g[t.t][i].t][t.bm|va[g[t.t][i].t]] > t.d + g[t.t][i].d ){
                dis[g[t.t][i].t][t.bm|va[g[t.t][i].t]] = t.d + g[t.t][i].d;
                pq.push({ g[t.t][i].t, t.d + g[t.t][i].d, t.bm | va[g[t.t][i].t] });
            }
        }
    }
    printf("%d",dis[fri.size()][(1<<k)-1]);
    return 0;
}
/*
7 9 1
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
*/