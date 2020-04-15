#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
char s[N], ans[N];
int n, last[N][30];

void solve( int l, int r ) {
    if( l > r ) return ;
    if( l % 2 == r % 2 ) {
        printf("-1");
        exit( 0 );
    }
    int idx = last[r][s[l]-'a'];
    ans[l] = '(', ans[idx] = ')';
    solve( l + 1, idx-1 ), solve( idx+1, r );
}

int main()
{
    scanf("%s",&s[1]);
    n = strlen( &s[1] );
    for( int i = 0 ; i < 26 ; i++ ) last[0][i] = 1;
    for( int i = 1 ; i <= n ; i++ ) {
        int now = s[i] - 'a';
        for( int j = 0 ; j < 26 ; j++ ) {
            if( j == now ) last[i][j] = i;
            else last[i][j] = last[last[i-1][now]-1][j];
        }
    }
    solve( 1, n );
    for( int i = 1 ; i <= n ; i++ ) printf("%c",ans[i]);
    return 0;
}