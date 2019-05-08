#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node {
    long long hi, co, plu;
}t;
int n;
long long h[N], d[N], ans;
stack<node> s;

long long cal( long long va ) { return ( va * ( va + 1 ) ) / 2; }

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&h[i]);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&d[i]);
    h[0] = 1, d[0] = 1;
    s.push({ h[n], 1, 0 });
    for( int i = n - 1 ; i >= 0 ; i-- ) {
        int cnt = 1, plu = 0;
        while( !s.empty() && h[i] <= s.top().hi ) {
            t = s.top();
            // cout << t.hi << " " << t.co << " " << t.plu << endl;
            ans += t.co * d[i] * cal( t.hi - 1 - h[i] ) + ( t.co + t.plu )  * ( t.hi - h[i] ) * d[i];
            cnt += t.co, plu += t.plu + ( t.hi - h[i] ) * t.co;
            s.pop();
        // cout << ans << endl; 
        }
        s.push({ h[i], cnt, plu });
    }
    printf("%lld",ans);
    return 0;
}