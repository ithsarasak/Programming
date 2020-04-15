#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 1e3 + 10;
int t, n;

int main()
{
    scanf("%d",&t);
    for( int rou = 1 ; rou <= t ; rou++ ) {
        char ans[N];
        vector<iii> work;
        int c = -1, j = -1, chk = 0;
        scanf("%d",&n);
        for( int i = 1, s, e ; i <= n ; i++ ) {
            scanf("%d %d",&s,&e);
            work.emplace_back( s, e, i-1 );
        }
        sort( work.begin(), work.end() );
        for( int i = 0, s, e, p ; i < work.size() ; i++ ) {
            tie( s, e, p ) = work[i];
            if( s >= c ) ans[p] = 'C', c = e;
            else if( s >= j ) ans[p] = 'J', j = e;
            else chk = 1;
        }
        printf("Case #%d: ",rou);
        if( chk ) printf("IMPOSSIBLE");
        else for( int i = 0 ; i < n ; i++ ) printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}