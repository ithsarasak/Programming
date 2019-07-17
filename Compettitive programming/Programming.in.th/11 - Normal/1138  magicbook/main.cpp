#include<bits/stdc++.h>

using namespace std;
struct book{
    int p, va;
}bo[100010];
int n, k, s, x, a, seg[400010], si;
int id[100010], mark[100010], ans = 0, id2[100010];
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
    if( id[l] > rr || id[r] < ll ){
        return -1e9;
    }
    if( id[l] >= ll && id[r] <= rr ){
        return seg[now];
    }
    int mid = ( l + r ) / 2;
    return max( query( l, mid, ll, rr, 2 * now ), query( mid + 1, r, ll, rr, 2 * now + 1 ) );
}
int main()
{
    scanf("%d %d %d",&n,&k,&s);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&bo[i].p,&bo[i].va);
        id2[i + 1] = bo[i].p;
    }
    id2[n + 1] = s;
    sort( id2 + 1, id2 + n + 2 );
    id[1] = id2[1];
    si = 1;
    for( int i = 2 ; i <= n + 1 ; i++ ){
        if( id2[i] != id[si] ){
            si++;
            id[si] = id2[i];
        }
    }
    build( 1, n + 1, 1 );
    for( int i = 0 ; i < n ; i++ ){
        bo[i].p = lower_bound( id + 1, id + si + 1, bo[i].p ) - id;
    }
    int tp = lower_bound( id + 1, id + si + 1, s ) - id;
    up( 1, si, tp, 0, 1 );

    for( int i = 0 ; i < n ; i++ ){
        dp[id[bo[i].p]] = query( 1, si, id[bo[i].p] - k, id[bo[i].p] + k, 1 ) + bo[i].va ;
        up( 1, si, bo[i].p, dp[id[bo[i].p]], 1 );
    }
    for( auto it = dp.begin() ; it != dp.end() ; it++ ){
        if( ans < it -> second  ){
            ans = it -> second;
        }
    }
    printf("%d",ans);
    return 0;
}
