#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m, ao, ae, bo, be;

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1, nu ; i <= n ; i++ ) {
        scanf("%d",&nu);
        if( nu % 2 ) ao++;
        else ae++;
    }
    for( int i = 1, nu ; i <= m ; i++ ) {
        scanf("%d",&nu);
        if( nu % 2 ) bo++;
        else be++;
    }
    printf("%d",min( ao, be ) + min( ae, bo) );
    return 0;
}