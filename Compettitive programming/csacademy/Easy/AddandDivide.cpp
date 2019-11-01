#include <bits/stdc++.h>

using namespace std;

int n, ans;

void solve( int n ) {
    if( n == 1 ) return ;
    if( n % 2 ) {
        ans ++;
        solve( n + 1 );
    }
    else {
        ans ++;
        solve( n >> 1 );
    }
    return ;
}
int main()
{
    scanf("%d",&n);
    solve( n );
    printf("%d",ans);
    return 0;
}