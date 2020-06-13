#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n;
long long c[N], ans;
priority_queue<long long> q;

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        long long a, b;
        scanf("%lld %lld",&a,&b);
        c[i] = c[i-1] + a - b;
    }
    for( int i = 1 ; i <= n ; i++ ) {
        if( c[i] > c[n] ) ans += c[i] - c[n], c[i] = c[n];
        if( c[i] < 0 ) ans -= c[i], c[i] = 0;
        q.emplace( c[i] );
        if( q.top() != c[i] ) {
            ans += q.top() - c[i];
            q.pop();
            q.emplace( c[i] );
        }
    }
    printf("%lld",ans);
    return 0;
}