#include<bits/stdc++.h>

using namespace std;
struct bb{
    int p, va;
}book[100010];
int n, k, s, x, a, seg[400010], si;
int con[100010], mark[100010], ans = 0, con2[100010];
map< int , int > dp;
void build( int l, int r , int now )
{
    if( l == r ){
        seg[now] = -1e9;
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    seg[now] = -1e9;
}
void up( int l, int r, int idx, int val, int now )
{
    if( l > idx || r < idx ){
        return ;
    }
    if( l == r ){
        seg[now] = val;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, val, 2 * now );
    up( mid + 1, r, idx, val, 2 * now + 1 );
    seg[now] = max( seg[now * 2], seg[now * 2 + 1] );
    return ;
}
int query( int l, int r, int ll, int rr, int now ){
    if( con[l] > rr || con[r] < ll ){
        return -1e9;
    }
    if( con[l] >= ll && con[r] <= rr ){
        return seg[now];
    }
    int mid = ( l + r ) / 2;
    return max( query( l, mid, ll, rr, 2 * now ), query( mid + 1, r, ll, rr, 2 * now + 1 ) );
}
int main()
{
    scanf("%d %d %d",&n,&k,&s);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&book[i].p,&book[i].va);
        con2[i + 1] = book[i].p;
    }
    con2[n + 1] = s;
    sort( con2 + 1, con2 + n + 2 );
    con[1] = con2[1];
    si = 1;
    for( int i = 2 ; i <= n + 1 ; i++ ){
        if( con2[i] != con[si] ){
            si++;
            con[si] = con2[i];
        }
    }
    build( 1, n + 1, 1 );
    for( int i = 0 ; i < n ; i++ ){
        book[i].p = lower_bound( con + 1, con + si + 1, book[i].p ) - con;
    }
    int tp = lower_bound( con + 1, con + si + 1, s ) - con;
    up( 1, si, tp, 0, 1 );

    for( int i = 0 ; i < n ; i++ ){
        dp[con[book[i].p]] = query( 1, si, con[book[i].p] - k, con[book[i].p] + k, 1 ) + book[i].va ;
        up( 1, si, book[i].p, dp[con[book[i].p]], 1 );
    }
    for( auto it = dp.begin() ; it != dp.end() ; it++ ){
        if( ans < it -> second  ){
            ans = it -> second;
        }
    }
    printf("%d",ans);
    return 0;
}
