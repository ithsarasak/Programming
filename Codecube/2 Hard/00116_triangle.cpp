#include <bits/stdc++.h>
#define lll tuple<long long,long long,long long>
using namespace std;

int t;
long long s;
vector<lll> ans;

void solve( long long s ) {
    ans.clear();
    for( long long a = 1 ; a < s ; a++ ) {
        if( (s*s/2) % ( s-a ) != 0 ) continue;
        long long b = s - ( ( s*s/2 ) / ( s-a ) );
        long long c = s - a - b;
        if( b <= 0 ) continue ;
        long long temp[] = { a, b, c };
        sort( temp, temp + 3 );
        if( temp[2] * temp[2] == temp[0] * temp[0] + temp[1] * temp[1] ) ans.emplace_back( lll( temp[0], temp[1], temp[2] ) );
    }
    sort( ans.begin(), ans.end() );
    ans.resize( unique( ans.begin(), ans.end() ) - ans.begin() );
    if( ans.size() == 0 ) {
        printf("-1\n");
        return ;
    }
    for( int i = 0 ; i < ans.size() ; i++ ) {
        long long a, b, c;
        tie( a, b, c ) = ans[i];
        printf("%lld %lld %lld\n",a,b,c);
    }
    return ;
}
int main()
{
    scanf("%d",&t);
    for( int i = 1 ; i <= t ; i++ ) {
        scanf("%lld",&s);
        printf("Case #%d:\n",i);
        solve( s );
    }
    return 0;
}