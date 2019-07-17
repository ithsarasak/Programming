#include<bits/stdc++.h>

using namespace std;
int n, c;
long long seg[400400], lz[400100];
void up( int l, int r, int ll, int rr, long long va, int now )
{
    //printf("%d %d %lld\n",l,r,seg[now]);
    if( lz[now] ){
        seg[now] += lz[now] * (long long)( r - l + 1 );
        if( l != r ){
            lz[now*2] += lz[now];
            lz[now*2+1] += lz[now];
        }
        lz[now] = 0;
    }
    if( l > rr || r < ll || l > r )return ;
    if( l >= ll && r <= rr ){
        seg[now] += va * (long long)( r - l + 1 );
        if( l != r ){
            lz[now*2] += va;
            lz[now*2+1] += va;
        }
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, ll, rr, va, now * 2 );
    up( mid + 1, r, ll, rr, va, now * 2 + 1 );
    seg[now] = seg[now*2] + seg[now*2+1];
    return ;
}
long long query( int l, int r, int ll, int rr, int now )
{
    //printf("%d %d %lld\n",l,r,seg[now]);
    if( lz[now] ){
        seg[now] += lz[now] * (long long)( r - l + 1 );
        if( l != r ){
            lz[now*2] += lz[now];
            lz[now*2+1] += lz[now];
        }
        lz[now] = 0;
    }
    if( l > rr || r < ll || l > r )return 0;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l + r ) / 2;
    return query( l, mid, ll, rr, now * 2 ) + query( mid + 1, r, ll, rr, now * 2 + 1 );
}
int main()
{
    int te;
    scanf("%d",&te);
    while( te-- ){
        memset( seg, 0, sizeof seg );
        memset( lz, 0, sizeof lz );
        scanf("%d %d",&n,&c);
        while( c-- ){
            int ch;
            scanf("%d",&ch);
            if( ch == 0 ){
                int f, t;
                long long va;
                scanf("%d %d %lld",&f,&t,&va);
                up( 1, n, f, t, va, 1 );
            }
            else{
                int f, t;
                scanf("%d %d",&f,&t);
                printf("%lld\n",query(1,n,f,t,1));
            }
        }
    }
    return 0;
}
