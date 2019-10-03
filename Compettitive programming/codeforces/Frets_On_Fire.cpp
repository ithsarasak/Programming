#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
long long n, q, f, t, qs[N], len;
vector<long long> fret, diff;

int main()
{
    scanf("%lld",&n);
    for( long long i = 1, te ; i <= n ; i++ ) {
        scanf("%lld",&te);
        fret.emplace_back( te );
    }
    sort( fret.begin(), fret.end() );
    fret.resize( unique( fret.begin(), fret.end() ) - fret.begin() );
    for( int i = 1 ; i < fret.size() ; i++ ) diff.emplace_back( fret[i] - fret[i-1] );
    sort( diff.begin(), diff.end() );
    for( int i = 1 ; i <= diff.size() ; i++ ) qs[i] = qs[i-1] + diff[i-1];
    scanf("%lld",&q);
    while( q-- ) {
        scanf("%lld %lld", &f, &t);
        len = t - f + 1;
        int idx = upper_bound( diff.begin(), diff.end(), len ) - diff.begin();
        printf("%lld\n",len * ( ( long long )fret.size() - idx ) + qs[idx] );
    }
    return 0;
}