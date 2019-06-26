#include <bits/stdc++.h>
#define pii pair<long long, int>
#define x first
#define y second

using namespace std;

const int N = 7e5 + 10;
const long long inf = 1e18 + 10;
int m, k, now;
long long sum[N];
vector<long long> bad;
vector<pii> query;
long long ans[N];
int main()
{
    scanf("%d %d",&m,&k);
    for( int i = 1 ; i <= m ; i++ ) {
        long long a;
        scanf("%lld",&a);
        bad.emplace_back( a );
    } 
    query.emplace_back( pii( -1, -1 ) ), bad.emplace_back( 0 );
    for( int i = 1 ; i <= k ; i++ ) {
        long long a;
        scanf("%lld",&a);
        query.emplace_back( pii( a, i ) );
    }
    sort( bad.begin(), bad.end() );
    sort( query.begin(), query.end() );
    for( int i = 1 ; i < bad.size() ; i++ ) sum[i] = sum[i-1] + bad[i] - bad[i-1] - 1;
    sum[bad.size()] = inf;
    for( int i = 1 ; i < query.size() ; i++ ) {
    while( sum[now] < query[i].x ) now++;
        ans[query[i].y] = query[i].x - sum[now-1] + bad[now-1];
    }
    for( int i = 1 ; i <= k ; i++ ) printf("%lld ",ans[i]);
    return 0;
}