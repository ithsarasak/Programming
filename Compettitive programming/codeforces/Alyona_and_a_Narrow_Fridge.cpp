#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 100;
long long n, h, bot[N];

bool check( int mid ) {
    vector<long long> v;
    for( int i = 1 ; i <= mid ; i++ ) v.emplace_back( bot[i] );
    sort( v.begin(), v.end(), greater<int>() );
    long long he = 0;
    for( int i = 0 ; i < v.size() ; i += 2 ) he += v[i];
    if( he <= h ) return true;
    else return false;
}

int main()
{
    scanf("%lld %lld",&n,&h);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&bot[i]);
    int l = 0, r = n;
    while( l < r ) {
        int mid = ( l + r + 1 ) >> 1;
        if( check( mid ) ) l = mid;
        else r = mid - 1;
    }
    printf("%d",l);
    return 0;
}