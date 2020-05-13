#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 10;

struct qq {
    int s, e, l, r, id;
    int mx, mn;
    qq( int s, int e, int l, int r, int id ) : s(s), e(e), l(l), r(r), id(id) {}
};

bool cmpl( qq a, qq b ) { return a.l < b.l; }
bool cmpr( qq a, qq b ) { return a.r < b.r; }

int n, par[2*N], va[2*N], m, q, lb[2*N], rb[2*N];
set<int> roots[2*N];
vector<qq> want[2*N], que;
vector<int> ans, tmin[2*N], tmax[2*N], g[2*N], pred;

int findroot( int now ) {
    if( par[now] == now ) return now;
    else return par[now] = findroot( par[now] );
}

void pre( int u = 2*n-2 ) {
    if( u < n ) pred.emplace_back( u );
    for( int v : tmin[u] ) pre( v );
}

void dfs( int u = 2*n-2 ) {
    lb[u] = 1e9, rb[u] = -1;
    if( u < n ) lb[u] = rb[u] = va[u];
    for( int v : tmin[u] ) {
        dfs( v );
        lb[u] = min( lb[u], lb[v] ), rb[u] = max( rb[u], rb[v] );
    }
}

void solve( int u = n*2-2 ) {
    if( u < n ) roots[u].insert( va[u] );
    pii hv( 0, -1 );
    for( int v : tmax[u] ) {
        solve( v );
        hv = max( hv, pii( roots[v].size(), v ) );
    }
    if( hv.y != -1 ) {
        swap( roots[hv.y], roots[u] );
        for( int v : tmax[u] ) {
            for( int x : roots[v] ) roots[u].insert( x );
        }
    }
    for( qq i : want[u] ) ans[i.id] = roots[u].upper_bound( rb[i.mn] ) != roots[u].upper_bound( lb[i.mn] - 1 );
}

vector<int> check_validity( int N, vector<int> X, vector<int> Y, vector<int> S, vector<int> E, vector<int> L, vector<int> R ) {
    n = N, m = X.size(), q = S.size();
    for( int i = 0 ; i < q ; i++ ) que.emplace_back( qq( S[i], E[i], L[i], R[i], i ) );
    for( int i = 0 ; i < m ; i++ ) g[X[i]].emplace_back( Y[i] ), g[Y[i]].emplace_back( X[i] );
    for( int i = 0 ; i <= 2*n ; i++ ) par[i] = i;
    sort( que.begin(), que.end(), cmpr );
    int cnt = n-1, pos = 0;
    for( int i = 0 ; i < n ; i++ ) {
        for( int v : g[i] ) {
            if( v < i ) {
                int a = findroot( i ), b = findroot( v );
                if( a == b ) continue;
                par[a] = par[b] = ++cnt;
                tmin[cnt].emplace_back( a ), tmin[cnt].emplace_back( b );
            }
        }
        while( pos < q && que[pos].r == i ) {
		    que[pos].mn = findroot( que[pos].e );
			pos++;
        } 
    }
    for( int i = 0 ; i <= 2*n ; i++ ) par[i] = i;
    sort( que.begin(), que.end(), cmpl );
    reverse( que.begin(), que.end() );
    cnt = n-1, pos = 0;
    for( int i = n-1 ; i >= 0 ; i-- ) {
        for( int v : g[i] ) {
            if( v > i ) {
                int a = findroot( i ), b = findroot( v );
                if( a == b ) continue;
                par[a] = par[b] = ++cnt;
                tmax[cnt].emplace_back( a ), tmax[cnt].emplace_back( b );
            }
        }
        while( pos < q && que[pos].l == i ) {
		    que[pos].mx = findroot( que[pos].s );
			pos++;
        } 
    }
    pre();
    for( int i = 0 ; i < n ; i++ ) va[pred[i]] = i;
    dfs();
    ans.resize( q );
    for( int i = 0 ; i < q ; i++ ) want[que[i].mx].emplace_back( que[i] );
    solve();
    return ans;
}