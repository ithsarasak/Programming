#include<bits/stdc++.h>

using namespace std;
struct ee{
   int f, t;
}e[100100];
int n, m, ind[100010], mark[100010], va, mem[100010], mark2[100010];
queue<int> q;
vector<int> g1[100010], g2[100010];
int mic( int node , int lv )
{
    int su;
    mark[node] = lv;
    if( node == n + 1 )su = va;
    else su = 1;
    for( int i = 0 ; i < g2[node].size() ; i++ ){
        if( mark[g2[node][i]] == 0 )
            su += mic( g2[node][i], lv + 1 );
    }
    return mem[node] = su;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d",&e[i].f,&e[i].t);
        ind[e[i].f]++;
        ind[e[i].t]++;
        g1[e[i].f].push_back( e[i].t );
        g1[e[i].t].push_back( e[i].f );
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( ind[i] == 1 ){
            q.push( i );
        }
    }
    while( !q.empty() ){
        int tt = q.front();
        q.pop();
        for( int i = 0 ; i < g1[tt].size() ; i++ ){
            ind[g1[tt][i]]--;
            if( ind[g1[tt][i]] == 1 ){
                q.push( g1[tt][i] );
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( ind[i] > 1 )va++;
    }
    for( int i = 0 ; i < m ; i++ ){
        int fr = e[i].f, to = e[i].t;
        if( ind[e[i].f] > 1 ){
            fr = n + 1;
        }
        if( ind[e[i].t] > 1 ){
            to = n + 1;
        }
        if( fr != n + 1 || to != n + 1 ){
            g2[fr].push_back( to );
            g2[to].push_back( fr );
        }
    }
    mic( n + 1 , 1 );
    for( int i = 0 ; i < m ; i++ ){
        if( ind[e[i].f] > 1 && ind[e[i].t] > 1 ) printf("0 ");
        else{
            int sm;
            if( mark[e[i].f] < mark[e[i].t] ){
                sm = e[i].t;
            }
            else{
                sm = e[i].f;
            }
            printf("%lld ",( long long )(n-mem[sm])*( long long )mem[sm]);
        }
    }
    return 0;
}
/*
13 13
1 2
2 3
3 4
4 5
5 6
6 1
4 7
7 8
7 9
9 10
3 11
12 11
13 11
*/
/*
9 9
1 2
2 3
3 1
3 4
3 5
4 6
4 7
5 8
5 9
*/

