#include<bits/stdc++.h>

using namespace std;
struct ss{
    long long sum, mi;
}seg[400100], zero;
long long num[100100];
int n, p, q;
void build( int l, int r, int now )
{
    if( l == r ){
        seg[now].mi = num[l];
        seg[now].sum = num[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    seg[now].mi = min( seg[now*2].mi, seg[now*2+1].mi );
    seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
    return ;
}
void up( int l, int r, int idx, int now, int va )
{
    if( l > idx || r < idx || l > r )return ;
    if( l == r ){
        seg[now].mi += va;
        seg[now].sum += va;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, now * 2, va );
    up( mid + 1, r, idx, now * 2 + 1, va );
    seg[now].mi = min( seg[now*2].mi, seg[now*2+1].mi );
    seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
    return ;
}
ss query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return zero;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l + r ) / 2;
    ss le = query( l, mid, ll, rr, now * 2 );
    ss ri = query( mid + 1, r, ll ,rr, now * 2 + 1 );
    ss temp;
    temp.mi = min( le.mi, ri.mi );
    temp.sum = le.sum + ri.sum;
    return temp;
}
int main()
{
    zero.mi = 1e18;
    zero.sum = 0;
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&num[i]);
    }
    scanf("%d",&q);
    build( 1, n, 1 );
    while( q-- ){
        int f, t;
        string op;
        cin >> op;
        scanf("%d %d",&f,&t);
        t++;
        if( op == "COUNT" ){
            f++;
            ss ans = query( 1, n, f, t, 1 );
            printf("%lld\n",ans.sum - ans.mi);
        }
        else if( op == "GROW" ){
            up( 1, n, t, 1, f );
        }
        else{
            up( 1, n, t, 1, -1*f );
        }
    }
}
