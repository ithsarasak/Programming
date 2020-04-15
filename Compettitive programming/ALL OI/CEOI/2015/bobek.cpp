#include <bits/stdc++.h>

using namespace std;

int n;
long long m, va[2][25], s[2], ans;
vector<long long> all[2];

void permute( int ty ) {
    //printf("size %d\n",s[ty]);
    for( int i = 0 ; i < ( 1<<s[ty] ) ; i++ ) {
        long long sum = 0;
        for( int j = 0 ; j < s[ty] ; j++ ) if( i & ( 1<<j ) ) sum += va[ty][j];
        all[ty].emplace_back( sum );
    }
}

int main()
{
    scanf("%d %lld",&n,&m);
    s[0] = n/2;
    s[1] = n - s[0];
    for( int i = 0 ; i < s[0] ; i++ ) scanf("%lld",&va[0][i]);
    for( int i = 0 ; i < s[1] ; i++ ) scanf("%lld",&va[1][i]);
    permute( 0 ), permute( 1 );
    sort( all[0].begin(), all[0].end() ), sort( all[1].begin(), all[1].end() );
    for( long long i : all[0] ) {
        long long temp = m - i;
        int idx = upper_bound( all[1].begin(), all[1].end(), temp ) - all[1].begin();
        ans += ( long long )idx;
    }
    printf("%lld",ans);
    return 0;
}