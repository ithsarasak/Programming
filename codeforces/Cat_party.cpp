#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
multiset<int> s; 
int cnt[N], n, ans = 1;
int main()
{
    scanf("%d",&n);
    for( int i = 1, c ; i <= n ; i++ ) {
        scanf("%d",&c);
        auto it = s.find( cnt[c] );
        if( it != s.end() ) s.erase( it );
        s.insert( ++cnt[c] );
        auto it1 = s.begin();
        auto it2 = s.rbegin();
        if( s.size() == 1 ) ans = i;
        if( s.size() == 2 ) {
            if( *it1 == 1 ) ans = i;
            if( *it1 + 1 == *it2 ) ans = i;
        }
        if( *it1 == 1 && *next( it1 ) == *it2 ) ans = i;
        if( *it1 + 1 == *it2 && *it1 == *next( it2 ) ) ans = i;
    }
    printf("%d",ans);
    return 0;
}