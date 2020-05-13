#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;
int n, m, edge[N][N], inv[N];

int main()
{
    fill( inv, inv + N, 1 );
    scanf("%d %d",&n,&m);
    for( int i = 1, a, b ; i <= m ; i++ ) {
        scanf("%d %d",&a,&b);
        edge[a][b] = edge[b][a] = 1;
    }
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = i + 1 ; j <= n ; j++ ) {
            if( !edge[i][j] && inv[i] && inv[j] ) inv[i] = inv[j] = 0;
        }
    }
    int cnt = 0;
    for( int i = 1 ; i <= n && cnt < n / 3 ; i++ ) {
        if( inv[i] ) {
            printf("%d ",i);
            cnt++;
        }
    }
    return 0;
}