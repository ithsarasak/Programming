#include<bits/stdc++.h>

using namespace std;
struct op{
    long long ch, f, t;
    long long va;
}qu[100100];
long long seg[800100], lz[800100];
vector<long long> key;
long long n, q, ma;
void up( long long l, long long r, long long ll, long long rr, long long now, long long va )
{
    if( lz[now] > -1000000001 ){
        seg[now] = lz[now] * ( long long )( key[r+1] - key[l] );
        if( l != r ){
            lz[now*2] = lz[now];
            lz[now*2+1] = lz[now];
        }
        lz[now] = -1000000001;
    }
    if( l > rr || r < ll || l > r )return ;
    if( l >= ll && r <= rr ){
        seg[now] = va * ( key[r+1] - key[l] );
        if( l != r ){
            lz[now*2] = va;
            lz[now*2+1] = va;
        }
        return ;
    }
    long long mid = ( l + r ) / 2;
    up( l, mid, ll, rr, now*2, va );
    up( mid + 1, r, ll, rr, now*2+1, va );
    seg[now] = seg[now*2] + seg[now*2+1];
    return ;
}
long long query( long long l, long long r, long long ll, long long rr, long long now )
{
    if( lz[now] > -1000000001 ){
        seg[now] = lz[now] * ( key[r+1] - key[l] );
        if( l != r ){
            lz[now*2] = lz[now];
            lz[now*2+1] = lz[now];
        }
        lz[now] = -1000000001;
    }
    if( l > rr || r < ll || l > r )return 0;
    if( l >= ll && r <= rr )return seg[now];
    long long mid = ( l + r ) / 2;
    return query( l, mid, ll, rr, now*2 ) + query( mid + 1, r, ll, rr, now*2+1 );
}
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&q);
    for( long long i = 0 ; i < q ; i++ ){
        scanf("%lld %lld %lld",&qu[i].ch,&qu[i].f,&qu[i].t);
        if( qu[i].ch == 0 )scanf("%lld",&qu[i].va);
        key.push_back( qu[i].f );
        key.push_back( qu[i].t );
    }
    key.push_back( -1 );
    sort( key.begin(), key.end() );
    key.resize( unique( key.begin(), key.end()) - key.begin() );
    for( long long i = 0 ; i < q ; i++ ){
        qu[i].f = lower_bound( key.begin(), key.end(), qu[i].f ) - key.begin();
        qu[i].t = lower_bound( key.begin(), key.end(), qu[i].t ) - key.begin() - 1;
    }
    for( long long i = 0 ; i < q ; i++ ){
        if( qu[i].ch == 0 ) up( 1, key.size()-1, qu[i].f, qu[i].t, 1, qu[i].va );
        else printf("%lld\n",query( 1, key.size()-1, qu[i].f, qu[i].t, 1 ) );
    }
    return 0;
}
