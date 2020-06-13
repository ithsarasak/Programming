#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct peo {
    int a, b;
}p[N];
int n;
long long ans;

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d %d",&p[i].a,&p[i].b);
    sort( p + 1, p + 1 + n, [&]( const peo &a, const peo &b ){
        return a.b - a.a < b.b - b.a;
    });
    for( int i = 1 ; i <= n ; i++ ) 
        ans += ( 1LL * ( i-1 ) * p[i].a ) + ( 1LL * ( n-i ) * p[i].b );
    printf("%lld",ans);
    return 0;
}