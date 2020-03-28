#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int t[N][30], n, ptr, sub[N], hv[N];
bool leaf[N];
vector<char> c;
void dfs( int u ) {
    sub[u] = 0;
    for( int i = 0 ; i < 26 ; i++ ) {
        int v = t[u][i];
        if( v == -1 ) continue ;
        dfs( v );
        if( sub[v] + 1 > sub[u] ) hv[u] = i, sub[u] = sub[v] + 1;
    }
}

void solve( int u ) {
    if( leaf[u] ) c.emplace_back('P');
    for( int i = 0 ; i < 26 ; i++ ) {
        int v = t[u][i];
        if( v == -1 || i == hv[u] ) continue ;
        c.emplace_back( i + 'a' );
        solve( v );
    }
    if( hv[u] != -1 ) {
        c.emplace_back( hv[u] + 'a' );
        solve( t[u][hv[u]] );
    }
    c.emplace_back( '-' );
}

int main()
{
    memset( t, -1, sizeof t );
    memset( hv, -1, sizeof hv );
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        char s[30];
        scanf(" %s",s+1);
        int cptr = 0;
        for( int j = 1 ; j <= strlen( s+1 ) ; j++ ) {
            int &pos = t[cptr][s[j]-'a'];
            if( pos == -1 ) pos = ++ptr;
            cptr = pos;
        }
        leaf[cptr] = true;
    }
    dfs( 0 );
    solve( 0 );
    while( !c.empty() && c.back() == '-' ) c.pop_back();
    printf("%d\n",c.size());
    for( int i = 0 ; i < ( int )c.size() ; i++ ) printf("%c\n",c[i]);
    return 0;
}