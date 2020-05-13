#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int n, x[N], y[N];
map<int, long long> m1, m2;
long long ans;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d %d",&x[i],&y[i]);
        m1[x[i]]++, m2[y[i]]++;
    }
    for( int i = 1 ; i <= n ; i++ ) ans += ( m1[x[i]] - 1 ) * ( m2[y[i]] - 1 );
    printf("%lld",ans);
    return 0;
}