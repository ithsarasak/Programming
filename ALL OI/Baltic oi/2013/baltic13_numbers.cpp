#include <bits/stdc++.h>

using namespace std;

long long a, b, dp[20][2][15][15][2];
vector<int> num;
long long solve( int pos = 0, int st1 = 0, int di1 = 10, int di2 = 10, int st2 = 0 ) {
    if( !num[pos] ) return 1LL;
    if( dp[pos][st1][di1][di2][st2] != -1 ) return dp[pos][st1][di1][di2][st2];
    if( pos >= num.size() ) return 1LL;
    int mx, ret  = 0;
    if( !st1 ) mx = num[pos];
    else mx = 9;
    for( int dgt = 0 ; dgt <= mx ; dgt++ ) {  
        if( dgt == di1 || dgt == di2 ) continue;
        int boi = st1;
        if( st1 == 0 && dgt < mx )boi = 1;
        if( !st2 && !dgt )ret += solve( pos + 1, boi, 10, 10, 0 );
        else ret += solve( pos + 1, boi, di2, dgt, 1 );
    }
    return dp[pos][st1][di1][di2][st2] = ret;
}

long long bef( long long x ) {
    num.clear();
    while( x > 0 ){
        num.emplace_back( x%10 );
        x /= 10;
    }
    reverse( num.begin(), num.end() );
    memset( dp, -1, sizeof dp );
    return solve();
}

int main()
{
    scanf("%lld %lld",&a,&b);
    printf("%lld",bef( b ) - bef( a - 1 ) );
    return 0;
}