#include <bits/stdc++.h>

using namespace std;

int n, k, ans, pv;
vector<int> v;

int main()
{
    scanf("%d %d",&n,&k);
    scanf("%d",&pv);
    for( int i = 2, t ; i <= n ; i++ ) {
        scanf("%d",&t);
        v.emplace_back( t - pv - 1 );
        pv = t;
    }
    sort( v.begin(), v.end() );
    for( int i = 0 ; i < n - k ; i++ ) ans += v[i];
    printf("%d",ans + n);
    return 0;
}