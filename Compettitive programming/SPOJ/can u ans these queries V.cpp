#include<bits/stdc++.h>

using namespace std;

struct ss{
    long long maxr, maxl, sum, maxc;
}seg[401100], zero;
long long num[101000], sum[101000];
long long t, n, q;
void build( long long l,long long r, long long now )
{
    if( l == r ){
        seg[now].maxr = num[l];
        seg[now].maxl = num[l];
        seg[now].maxc = num[l];
        seg[now].sum = num[l];
        return ;
    }
    long long mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    seg[now].maxr = max( seg[now*2].maxr + seg[now*2+1].sum, seg[now*2+1].maxr );
    seg[now].maxl = max( seg[now*2].maxl, seg[now*2+1].maxl +seg[now*2].sum );
    seg[now].maxc = max( seg[now*2].maxc, max( seg[now*2+1].maxc, seg[now*2].maxr + seg[now*2+1].maxl ) );
    seg[now].sum = seg[now*2+1].sum + seg[now*2].sum;
    return ;
}

ss query( long long l, long long r, long long ll, long long rr, long long now )
{
    //printf("%lld %lld %lld %lld %lld\n",l,r,ll,rr,now);
    if( l > rr || r < ll || l > r )return zero;
    if( l >= ll && r <= rr )return seg[now];
    long long mid = ( l + r ) / 2;
    ss lef = query( l, mid, ll, rr, now*2 );
    ss righ = query( mid + 1, r, ll, rr, now*2+1 );
    ss temp;
    temp.maxr = max( lef.maxr + righ.sum, righ.maxr );
    temp.maxl = max( lef.maxl ,lef.sum + righ.maxl );
    temp.maxc = max( lef.maxc, max( righ.maxc, lef.maxr + righ.maxl ) );
    temp.sum = lef.sum + righ.sum;
    return temp;
}
int main()
{
    zero.maxr = -1e9;
    zero.maxl = -1e9;
    zero.maxc = -1e9;
    zero.sum = 0;
    cin >> t;
    while( t-- ){
        memset( sum, 0, sizeof sum );
        for( long long i = 0 ; i < 400100 ; i++ ){
            seg[i].maxr = 0;
            seg[i].maxl = 0;
            seg[i].maxc = 0;
            seg[i].sum = 0;
        }
        cin >> n;
        for( long long i = 1 ; i <= n ; i++ ){
            cin >> num[i];
            sum[i] = sum[i-1] + num[i];
        }
        build( 1, n, 1 );
        cin >> q;
        while( q-- ){
            long long x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if( y1 <= x2 ){
                ss lef = query( 1, n, x1, y1, 1 );
                ss righ = query( 1, n, x2, y2, 1 );
                cout << lef.maxr+righ.maxl+sum[x2-1]-sum[y1] << endl;
            }
            else{
                ss lef  = query( 1, n, x1, x2, 1 );
                ss righ  = query( 1, n, x2, y2, 1 );
                long long ma = lef.maxr + righ.maxl - num[x2];
                lef = query( 1, n, x1, y1, 1 );
                righ = query( 1, n, y1, y2, 1 );
                ma = max( ma, lef.maxr + righ.maxl - num[y1] );
                lef = query( 1, n, x2, y1, 1 );
                ma = max( ma, lef.maxc );
                cout << ma << endl;
            }
        }
    }
    return 0;
}
