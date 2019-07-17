#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e6 + 10;
int dpl[N], dpr[N], n, x;
vector<int> v;
long long ans;
pii num[N];

bool chk( int l, int r ) {
    int f = lower_bound( v.begin(), v.end(), l ) - v.begin(), t = upper_bound( v.begin(), v.end(), r ) - v.begin() + 1;
    if( dpl[f] && dpr[t] ) {
        if( f == 0 || t == n + 1 ) return true;
        else {
            if( num[f].y < num[t].y ) return true;
            else return false;
        }
    }
    else return false;
}

int main()
{
    scanf("%d %d",&n,&x);
    for( int i = 1, t ; i <= n ; i++ ) {
        scanf("%d",&t);
        num[i] = pii( t, i );
        v.emplace_back( t );
    }
    sort( v.begin(), v.end() );
    sort( num + 1, num + 1 + n );
    dpl[0] = dpl[1] = 1;
    for( int i = 2 ; i <= n ; i++ ) {
        if( dpl[i-1] == 0 ) dpl[i] = 0;
        else if( num[i].y > num[i-1].y ) dpl[i] = 1;
        else dpl[i] = 0;
    }
    dpr[n+1] = dpr[n] = 1;
    for( int i = n - 1 ; i >= 1 ; i-- ) {
        if( dpr[i+1] == 0 ) dpr[i] = 0;
        else if( num[i].y < num[i+1].y ) dpr[i] = 1;
        else dpr[i] = 0;
    }
    for( int i = 1 ; i <= x ; i++ ) {
        int l = i, r = x;
        if( !chk( l, x ) ) continue ;
        while( l < r ) {
            int mid = ( l + r ) >> 1;
            if( chk( i, mid ) ) r = mid;
            else l = mid + 1;
        }
        ans += ( long long )( x - r + 1 );
    }
    printf("%lld",ans);
    return 0;
}