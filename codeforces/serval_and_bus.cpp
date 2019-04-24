#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, t;
vector<int> v2;
vector<pii> v;
int main()
{
    scanf("%d %d",&n,&t);
    for( int i = 1, x, y ; i <= n ; i++ ) {
        scanf("%d %d",&x,&y);
        while( x < t ) x += y;
        v.emplace_back( pii( x, i ) ), v2.emplace_back( x );
    }
    sort( v.begin(), v.end() ), sort( v2.begin(), v2.end() );
    int idx = lower_bound( v2.begin(), v2.end(), t ) - v2.begin();
    printf("%d",v[idx].y);
    return 0;
}