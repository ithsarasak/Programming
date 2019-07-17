#include<bits/stdc++.h>

using namespace std;
struct ss{
    int bit[2][25];
}seg[400100], t, zero;
int n, m;
int lz[400100];
int num[100100];
void build( int l, int r, int now )
{
    if( l == r ){
        int t = num[l];
        for( int i = 0 ; i <= 21 ; i++ ){
            seg[now].bit[t%2][i]++;
            t /= 2;
        }
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    for( int i = 0 ; i < 2 ; i++ ){
        for( int j = 0 ; j <= 21 ; j++ ){
            seg[now].bit[i][j] = seg[now*2].bit[i][j] + seg[now*2+1].bit[i][j];
        }
    }
    return ;
}
void up( int l, int r, int ll, int rr, int now, int va )
{
    if( lz[now] ){
        if( l != r ){
            lz[now*2] ^= lz[now];
            lz[now*2+1] ^= lz[now];
        }
        for( int i = 0 ; i <= 21 ; i++ ){
            if( lz[now] % 2 == 1 ){
                swap( seg[now].bit[0][i], seg[now].bit[1][i] );
            }
            lz[now] /= 2;
        }
    }
    if( l > rr || r < ll || l > r )return ;
    if( l >= ll && r <= rr ){
        if( l != r ){
            lz[now*2] ^= va;
            lz[now*2+1] ^= va;
        }
        for( int i = 0 ; i <= 21 ; i++ ){
            if( va % 2 == 1 ){
                swap( seg[now].bit[0][i], seg[now].bit[1][i] );
            }
            va /= 2;
        }
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, ll, rr, now * 2, va );
    up( mid + 1, r, ll, rr, now * 2 + 1, va );
    for( int i = 0 ; i < 2 ; i++ ){
        for( int j = 0 ; j <= 21 ; j++ ){
            seg[now].bit[i][j] = seg[now*2].bit[i][j] + seg[now*2+1].bit[i][j];
        }
    }
    return ;
}
ss query( int l, int r, int ll, int rr, int now )
{
    if( lz[now] ){
        if( l != r ){
            lz[now*2] ^= lz[now];
            lz[now*2+1] ^= lz[now];
        }
        for( int i = 0 ; i <= 21 ; i++ ){
            if( lz[now] % 2 == 1 ){
                swap( seg[now].bit[0][i], seg[now].bit[1][i] );
            }
            lz[now] /= 2;
        }
    }
    if( l > rr || r < ll || l > r )return zero;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l + r ) / 2;
    ss le = query( l, mid, ll, rr, now * 2 );
    ss ri = query( mid + 1, r, ll, rr, now * 2 + 1 );
    ss re;
    for( int i = 0 ; i < 2 ; i ++ ){
        for( int j = 0 ; j <= 21 ; j++ ){
            re.bit[i][j] = le.bit[i][j] + ri.bit[i][j];
        }
    }
    return re;

}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
    }
    build( 1, n, 1 );
    scanf("%d",&m);
    while( m-- ){
        int op;
        scanf("%d",&op);
        if( op == 1 ){
            int f, t;
            scanf("%d %d",&f,&t);
            ss ans = query( 1, n, f, t, 1 );
            long long an = 0;
            for( int i = 0 ; i <= 21 ; i++ ){
                //printf("%d ",ans.bit[1][i]);
                an += ( long long )ans.bit[1][i] * ( long long )( 1 << i );
            }
            printf("%lld\n",an);
        }
        else{
            int f, t, x;
            scanf("%d %d %d",&f,&t,&x);
            up( 1, n, f, t, 1, x );
        }
    }
    return 0;
}
