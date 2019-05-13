#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m, master[N], par[N], mic[20][N], visit[N], lv[N], chk, a[3*N], b[3*N], op[3*N];
vector<int> g[N];
queue<int> q;

void dfs( int now, int p ) {
    lv[now] = lv[p] + 1, mic[0][now] = p, visit[now] = 1;
    for( int i : g[now] ) if( i != p ) dfs( i, now );
}

int lca( int a, int b ) {
    if( lv[a] < lv[b] ) swap( a, b );
    for( int i = 17 ; i >= 0 ; i-- ) if( lv[mic[i][a]] >= lv[b] ) a = mic[i][a];
    if( a == b ) return a;
    for( int i = 17 ; i >= 0 ; i-- ) if( mic[i][a] != mic[i][b] ) a = mic[i][a], b = mic[i][b];
    return mic[0][a];
}

int findroot( int num ) {
    if( num == par[num] ) return num;
    else return par[num] = findroot( par[num] );
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) par[i] = i, master[i] = i;
    for( int i = 0 ; i < m ; i++ ) {
        scanf("%d %d",&op[i],&a[i]);
        if( op[i] == 1 ) {
            scanf("%d",&b[i]);
            g[a[i]].emplace_back( b[i] ), g[b[i]].emplace_back( a[i] );
        }
        else if( op[i] == 3 ) scanf("%d",&b[i]);
    }
    for( int i = 1 ; i <= n ; i++ ) if( !visit[i] ) dfs( i, 0 );
    for( int i = 1 ; i <= 17 ; i++ ) for( int j = 1 ; j <= n ; j++ ) mic[i][j] = mic[i-1][mic[i-1][j]];
    for( int i = 0 ; i < m ; i++ ) {
        if( op[i] == 1 ) par[findroot( a[i] )] = b[i];
        else if( op[i] == 2 ) master[findroot( a[i] )] = a[i]; 
        else {
            int rt = master[findroot( a[i] )];
            if( lv[a[i]] < lv[b[i]] ){
                if( lca( b[i], rt ) == b[i] ) printf("%d\n",b[i]);
                else printf("%d\n",a[i]);
            }
            else {
                if( lca( a[i], rt ) == a[i] ) printf("%d\n",a[i]);
                else printf("%d\n",b[i]);
            }
        }
    }
    return 0;
}