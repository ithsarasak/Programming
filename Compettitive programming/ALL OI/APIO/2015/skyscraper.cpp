#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 3e4 + 10;
const int M = 2e3 + 5;
int n, m, d[N], st, en, inf = 1e9;
bool chk[N][M];
vector<int> g[N];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main()
{
    fill( d, d+N, inf );
    scanf("%d %d",&n,&m);
    for( int i = 0, a, b ; i < m ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b );
        if( i == 0 ) st = a;
        else if( i == 1 ) en = a;
    }
    for( int i = 0 ; i < n ; i++ ) {
        sort( g[i].begin(), g[i].end() );
        g[i].resize(unique(g[i].begin(), g[i].end())-g[i].begin());
    } 
    q.emplace( d[st] = 0, st );
    while( !q.empty() ) {
        pii now = q.top(); q.pop();
        if( d[now.y] != now.x ) continue;
        for( int p : g[now.y] ) {
            for( int i = now.y + p, cnt = 1 ; i < n ; i += p, cnt++ ) {
                if( p < M && chk[i][p] ) break ;
                if( d[i] > d[now.y] + cnt ) {
                    q.emplace( d[i] = d[now.y] + cnt, i );
                    if( p < M ) chk[i][p] = true;
                }
            }
            for( int i = now.y - p, cnt = 1 ; i >= 0 ; i -= p, cnt++ ) {
                if( p < M && chk[i][p] ) break ;
                if( d[i] > d[now.y] + cnt ) {
                    q.emplace( d[i] = d[now.y] + cnt, i );
                    if( p < M ) chk[i][p] = true;
                }
            }
        }
    }
    printf("%d",d[en]==inf?-1:d[en]);
    return 0;
}