#include<bits/stdc++.h>

using namespace std;
int n;
int m1h[100100], m2h[100100], m1b[100100], m2b[100100];
int seg1[400100], seg2[400100];
void build1( int l, int r, int now )
{
    if( l == r ){
        seg1[now] = m2h[l] + m2b[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build1( l, mid, now * 2 );
    build1( mid + 1, r, now * 2 + 1 );
    seg1[now] = max( seg1[now*2], seg1[now*2+1] );
    return ;
}
void build2( int l, int r, int now )
{
    if( l == r ){
        seg2[now] = m2b[l] - m2h[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build2( l, mid, now * 2 );
    build2( mid + 1, r , now * 2 + 1 );
    seg2[now] = max( seg2[now*2], seg2[now*2+1] );
    return ;
}
int query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r || ll > rr )return -1e9;
    if( l >= ll && r <= rr )return seg1[now];
    int mid = ( l + r ) / 2;
    return max( query( l, mid, ll, rr, now * 2 ), query( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int query2( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r || ll > rr )return -1e9;
    if( l >= ll && r <= rr )return seg2[now];
    int mid = ( l + r ) / 2;
    return max( query2( l, mid, ll, rr, now * 2 ), query2( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d %d",&m1h[i],&m1b[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d %d",&m2h[i],&m2b[i]);
    }
    build1( 1, n, 1 );
    build2( 1, n, 1 );
    //printf("%d %d\n",seg1[1],seg2[1]);
    for( int i = 1 ; i <= n ; i++ ){
        int idx;
        if( m1h[i] >= m2h[n] )idx = n + 1;
        else idx = upper_bound( m2h + 1, m2h + 1 + n, m1h[i] ) - m2h;
        int ans1 = m1b[i] - m1h[i] + query( 1, n, 1, idx - 1, 1 );
        int ans2 = m1b[i] + m1h[i] + query2( 1, n, idx, n, 1 );
        //printf("%d %d %d %d %d\n",ans1,ans2,idx,m1b[i],m1h[i]);
        printf("%d\n",max( ans1, ans2 ) );

    }
    return 0;
}
