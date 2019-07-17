#include <bits/stdc++.h>
#include "crocodile.h"
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int N = 1e5 + 10;
int cnt[N];
vector<pii> g[N];
priority_queue< pii, vector<pii>, greater<pii> > q; 

int travel_plan( int n, int m, int r[][2], int l[], int k, int p[] ) 
{
    for( int i = 0 ; i < m ; i++ ) {
        g[r[i][0]].emplace_back( l[i], r[i][1] );
        g[r[i][1]].emplace_back( l[i], r[i][0] );
    }
    for( int i = 0 ; i < k ; i++ ) {
        cnt[p[i]]++;
        q.push( pii( 0, p[i] ) );
    }
    while( !q.empty() ) {
        pii te = q.top(); q.pop();
        //printf("%d %d\n",te.y,te.x);
        cnt[te.y]++;
        if( cnt[te.y] != 2 ) continue ;
        if( te.y == 0 ) return te.x;
        for( pii i : g[te.y] ) if( cnt[i.y] < 2 ) q.push( pii( i.x + te.x, i.y ) );
    }
}       

// int main() 
// {
//     int n, m, r[N][2], l[N], k, p[N];
//     scanf("%d %d",&n,&m);
//     for( int i = 0 ; i < m ; i++ ) scanf("%d %d",&r[i][0],&r[i][1]);
//     for( int i = 0 ; i < m ; i++ ) scanf("%d",&l[i]);
//     scanf("%d",&k);
//     for( int i = 0 ; i < k ; i++ ) scanf("%d",&p[i]);
//     printf("%d",travel_plan( n, m, r, l, k, p ) );
//     return 0;
// }