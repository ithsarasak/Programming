#include<bits/stdc++.h>

using namespace std;
struct ss{
    long long ma, sum;
}seg[400100], zero;
int n, qe, z;
long long num[100100], ans[100100];
void build( int l,int r, int now )
{
    if( l == r ){
        seg[now].ma = num[l];
        seg[now].sum = num[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
    seg[now].ma = max( seg[now*2].ma,seg[now*2+1].ma );
    return ;
}
void up( int l, int r, int idx, int now )
{
    if( l > idx || r < idx || l > r )return ;
    if( seg[now].ma == 1 )return ;
    if( l == r ){
        seg[now].ma = sqrt( seg[now].ma );
        seg[now].sum = sqrt( seg[now].sum );
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, now * 2 );
    up( mid + 1, r, idx, now * 2 + 1 );
    seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
    seg[now].ma = max( seg[now*2].ma,seg[now*2+1].ma );
    return ;
}
ss query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return zero;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l + r ) / 2;
    ss le = query( l, mid, ll, rr, now * 2 );
    ss ri = query( mid + 1, r, ll, rr, now * 2 + 1 );
    ss temp;
    temp.sum = le.sum + ri.sum;
    temp.ma = max( le.ma, ri.ma );
    return temp;
}
int main()
{
    zero.sum = 0;
    zero.ma = -1e9;
    while( scanf("%d",&n) != EOF ){
        z++;
        int si = 0;
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%lld",&num[i]);
        }
        build( 1, n, 1 );
        scanf("%d",&qe);
        for( int i = 0 ; i < qe ; i++ ){
            int c, x, y;
            scanf("%d %d %d",&c,&x,&y);
            if( c == 0 ){
                for( int i = x ; i <= y ; i++ ){
                    up( 1, n, i, 1 );
                }
            }
            else{
                ss ans2 = query( 1, n, x, y, 1 );
                ans[si] = ans2.sum;
                si++;
            }
        }
        printf("Case #%d:\n",z);
        for( int i = 0 ; i < si ; i++ ){
            printf("%lld\n",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
