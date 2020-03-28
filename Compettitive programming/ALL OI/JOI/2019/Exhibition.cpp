#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int n, m, ans, now;
vector<int> fra;
vector<pii> pic;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        pic.emplace_back( pii( b, a ) );
    }
    for( int i = 0, a ; i < m ; i++ ) {
        scanf("%d",&a);
        fra.emplace_back( a );
    }
    sort( pic.begin(), pic.end(), greater<pii>() ), sort( fra.begin(), fra.end(), greater<int>() );
    for( int i = 0 ; i < m ; i++ ) {
        while( pic[now].y > fra[i] && now < n ) now++;
        if( now == n ) break;
        ans++, now++;
    }
    printf("%d",ans);
    return 0;
}