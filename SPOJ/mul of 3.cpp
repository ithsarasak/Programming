#include<bits/stdc++.h>

using namespace std;
struct ss{
    int no[3];
}seg[400100], zero;
int n, q, lz[400100];
void build( int l, int r, int now )
{
    if( l == r ){
        seg[now].no[0] = 1;
        seg[now].no[1] = 0;
        seg[now].no[2] = 0;
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    for( int i = 0 ; i < 3 ; i++ ){
        seg[now].no[i] = seg[now*2].no[i] + seg[now*2+1].no[i];
    }
    return ;
}
void up( int l, int r, int ll, int rr, int now )
{
    lz[now] %= 3;
    if( lz[now] ){
        int t[3];
        for( int i = 0 ; i < 3 ; i++ ){
            t[i] = seg[now].no[i];
        }
        for( int i = 0 ; i < 3 ; i++ ){
            seg[now].no[i] = t[(i-(lz[now]%3)+3)%3];
        }
        if( l != r ){
            lz[now*2] += lz[now];
            lz[now*2+1] += lz[now];
            lz[now*2] %= 3;
            lz[now*2+1] %= 3;
        }
        lz[now] = 0;
    }
    if( l > rr || r < ll || l > r )return ;
    if( l >= ll && r <= rr ){
        int t[3];
        for( int i = 0 ; i < 3 ; i++ ){
            t[i] = seg[now].no[i];
        }
        for( int i = 0 ; i < 3 ; i++ ){
            seg[now].no[i] = t[(i+2)%3];
        }
        if( l != r ){
            lz[now*2] += 1;
            lz[now*2+1] += 1;
            lz[now*2] %= 3;
            lz[now*2+1] %= 3;
        }
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, ll, rr, now * 2 );
    up( mid + 1, r , ll , rr, now * 2 + 1 );
    for( int i = 0 ; i < 3 ; i++ ){
        seg[now].no[i] = seg[now*2].no[i] + seg[now*2+1].no[i];
    }
    return ;
}
ss query( int l, int r, int ll, int rr, int now )
{
    lz[now] %= 3;
    if( lz[now] ){
        int t[3];
        for( int i = 0 ; i < 3 ; i++ ){
            t[i] = seg[now].no[i];
        }
        for( int i = 0 ; i < 3 ; i++ ){
            seg[now].no[i] = t[(i-(lz[now]%3)+3)%3];
        }
        if( l != r ){
            lz[now*2] += lz[now];
            lz[now*2+1] += lz[now];
            lz[now*2] %= 3;
            lz[now*2+1] %= 3;
        }
        lz[now] = 0;
    }
    if( l > rr || r < ll || l > r )return zero;
    if( l >= ll && r <= rr )return seg[now];
    int mid = ( l + r ) / 2;
    ss le = query( l, mid, ll, rr, now * 2 );
    ss ri = query( mid + 1, r, ll, rr, now * 2 + 1 );
    ss re;
    for( int i = 0 ; i < 3 ; i++ )re.no[i] = le.no[i] + ri.no[i];
    return re;
}
int main()
{
    int c, a, b;
    scanf("%d %d",&n,&q);
    build( 1, n, 1 );
    while( q-- ){
        scanf("%d %d %d",&c,&a,&b);
        a++,b++;
        if( c == 0 ){
            up( 1, n, a, b, 1 );
        }
        else{
            ss ans = query( 1, n, a, b, 1 );
            printf("%d\n",ans.no[0]);
        }
    }
    return 0;
}
