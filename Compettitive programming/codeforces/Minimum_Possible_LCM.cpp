#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ppp pair<pll, pll>
#define x first
#define y second 
using namespace std;

const int N = 1e6 + 100;
const int bound = 1e7 + 10;
int n, num[N], mark[bound], cnt[bound];
vector<int> m[bound];
long long ans, one, two;
ppp sol[bound], mi( pll( 1e9, 1e9 ), pll( 1e9, 1e9 ) );
vector<pii> fac[N];

void sieve() {
    for( int i = 2 ; i < bound ; i++ ) if( !mark[i] ) 
        for( int j = i ; j < bound ; j += i ) {
            mark[j] = 1;
            for( int k = 0 ; k < m[j].size() ; k++ ) fac[m[j][k]].emplace_back( pll( i, 0 ) );
        }
    return ;
}

void gen( int i, int idx, int pro ) {
    //cout << i << " " << idx << " " << pro << " " << fac[i].size() << endl;
    for( int j = 0, mul = 1 ; j <= fac[i][idx].y ; j++, mul *= fac[i][idx].x ) {
        //cout << " mul " << mul << " " << pro << " " << endl;
        if( idx != ( int )fac[i].size() - 1 ) gen( i, idx + 1, pro * mul );
        else {
            //cout << " hh " << pro << " " << i << " " << num[i] << endl; 
            pll x( ( long long )num[i], ( long long )i );
            if( x.x < sol[pro*mul].x.x ) swap( x, sol[pro*mul].x );
            if( x.x < sol[pro*mul].y.x ) swap( x, sol[pro*mul].y );
            //cout << " GG ";
        }
        //cout << " got it " << endl;
    }
    if( idx == ( int )fac[i].size() - 1 ) return ;
}

int main()
{
    fill( sol, sol + bound, ppp( pll( 1e9, 1e9 ), pll( 1e9, 1e9 ) ) );
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&num[i]);
        cnt[num[i]]++;
        if( cnt[num[i]] <= 2 ) m[num[i]].emplace_back( i );
        pll temp( ( long long )num[i], ( long long )i );
        if( temp.x < mi.x.x ) swap( temp, mi.x );
        if( temp.x < mi.y.x ) swap( temp, mi.y );
    }
    ans = mi.x.x * mi.y.x, one = mi.x.y, two = mi.y.y;
    sieve();
    memset( cnt, 0, sizeof cnt );
    for( int i = 1 ; i <= n ; i++ ) for( int t = 0 ; t < fac[i].size() ; t++ ) for( int temp = num[i] ; temp % fac[i][t].x == 0 ; fac[i][t].y++ ) temp /= fac[i][t].x;
    for( int i = 1 ; i <= n ; i++ ) if( num[i] != 1 && ++cnt[num[i]] <= 2 ) gen( i, 0, 1 );
    for( int i = 1 ; i <= bound - 10 ; i++ ) if( sol[i].x.x != 1e9 && sol[i].y.x != 1e9 ) {
        if( sol[i].x.x * sol[i].y.x / ( long long )i < ans ) {
            ans = sol[i].x.x * sol[i].y.x / ( long long )i;
            one = sol[i].x.y, two = sol[i].y.y;
        }
    }
    printf("%lld %lld",min( one, two ), max( one, two ) );
    return 0; 
}