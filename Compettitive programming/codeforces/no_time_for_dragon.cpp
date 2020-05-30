#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

vector<pii> v;
int n;
long long ans, now;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        long long a, b;
        scanf("%lld %lld",&a,&b);
        v.emplace_back(pii( a, b ));
    }
    sort( v.begin(), v.end(), [&]( const pii &a, const pii &b ){
        return a.y - a.x < b.y - b.x;
    });
    for( pii i : v ) {
        //printf("%lld %lld\n",i.x,i.y);
        if( now <= i.x ) {
            ans += i.x - now;
            now = i.x;
        }
        now -= i.y;
    }
    printf("%lld",ans);
    return 0;
}