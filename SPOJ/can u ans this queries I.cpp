#include<bits/stdc++.h>

using namespace std;
struct ss{
    long long maxr, maxl, maxc, sum;
}seg[200100], zero;
long long num[200100];
long long n, q;
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
    scanf("%lld",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&num[i]);
    }
    build( 1, n, 1 );
    scanf("%lld",&q);
    while(q--){
        long long x, y;
        scanf("%lld %lld",&x,&y);
        ss ans = query( 1, n, x, y, 1 );
        printf("%lld\n",ans.maxc);
    }
    return 0;
}
