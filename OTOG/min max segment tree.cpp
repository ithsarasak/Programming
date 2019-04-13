#include<bits/stdc++.h>

using namespace std;
int seg[400100], seg2[400100];
int n, num[100100];
void build( int l, int r, int now )
{
    if( l == r ){
        seg[now] = num[l];
        seg2[now] = num[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1 , r, now * 2 + 1 );
    seg[now] = min( seg[now*2], seg[now*2+1] );
    seg2[now] = max( seg2[now*2], seg2[now*2+1] );
    return ;
}
int query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return 1e9;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l + r ) / 2;
    return min( query( l, mid, ll, rr, now * 2 ), query( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int query2( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return -1e9;
    if( l >= ll && r <= rr )return seg2[now];
    int mid = ( l + r ) / 2;
    return max( query2( l, mid, ll, rr, now * 2 ), query2( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
void up( int l, int r, int idx, int va, int now )
{
    if( l > idx || r < idx || l > r )return ;
    if( l == r ){
        seg[now] = va;
        seg2[now] = va;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, va, now * 2 );
    up( mid + 1, r, idx, va, now * 2 + 1 );
    seg[now] = min( seg[now*2], seg[now*2+1] );
    seg2[now] = max( seg2[now*2], seg2[now*2+1] );
    return ;
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
    }
    build( 1, n, 1 );
    int ch;
    while( scanf(" %c",&ch) != EOF ){
        int l, r;
        scanf("%d %d",&l,&r);
        if( ch == 'U' ){
            l++;
            up( 1, n, l, r, 1 );
        }
        else{
            l++, r++;
            printf("%d %d\n",query( 1, n, l, r, 1 ), query2( 1, n, l, r, 1 ) );
        }
    }
    return 0;
}
