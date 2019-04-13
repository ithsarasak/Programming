#include<bits/stdc++.h>

using namespace std;
int seg[400100];
int n, q;
void up( int l, int r, int idx, int now, int va)
{
    if( l > idx || r < idx || l > r )return ;
    if( l == r ){
        seg[now] = va;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, now * 2, va );
    up( mid + 1, r, idx, now * 2 + 1, va );
    seg[now] = max( seg[now*2], seg[now*2+1] );
    return ;
}
int query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return -1e9;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l + r ) / 2;
    return max( query( l, mid, ll, rr, now * 2 ) , query( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int main()
{
    char ch;
    scanf("%d %d",&n,&q);
    while( q-- ){
        scanf(" %c",&ch);
        if( ch == 'U' ){
            int p, z;
            scanf("%d %d",&p,&z);
            up( 1, n, p, 1, z );
        }
        else{
            int a, b;
            scanf("%d %d",&a,&b);
            printf("%d\n",query( 1, n, a, b, 1 ));
        }
    }
    return 0;
}
