#include <bits/stdc++.h>

using namespace std;

struct item{
	int d;
	item* l;
	item* r;
	item() { }
	item( int d, item*l, item* r ) : d( d ), l( l ), r ( r ) { }
};

const int N = 1e5 + 100;
int n, m, cnt = 1, wei[N], mark[N], lv[N], mic[20][N], pos[N];
vector<int> g[N], all;
item* ver[N];

item* newleaf( int va ) {
	return new item( va, nullptr, nullptr );
}

item* newpar( item* l, item* r ) {
	return new item( l->d+r->d, l, r );
}

item* build( int l = 1, int r = all.size() ) {
	if( l == r )return newleaf( 0 );
	int mid = ( l + r ) >> 1;
	return newpar( build( l, mid ), build( mid + 1, r ) );
}

item* update( item* p, int idx, int l = 1, int r = all.size() ) {
	if( l == r ) return newleaf( p->d + 1 );
	int mid = ( l + r ) >> 1;
	if( idx <= mid ) return newpar( update( p->l, idx, l, mid ), p->r );
	else return newpar( p->l, update( p->r, idx, mid+1, r ) );
}

int query( item* a, item* b, item*c, item*d, int k, int l = 1, int r = all.size() ) {
	if( l == r )return l;
	int mid = ( l + r ) >> 1;
	int diff = a->l->d + b->l->d - c->l->d - d->l->d;
	//cout << diff << endl;
	if( diff >= k )return query( a->l, b->l, c->l, d->l, k, l, mid );
	else return query( a->r, b->r, c->r, d->r, k-diff, mid+1, r );
}

int get( int x ){ return lower_bound( all.begin(), all.end(), x ) - all.begin() + 1; }

void dfs( int now, int p, int dep ) {
	mark[now] = 1;
	pos[now] = cnt;
	//printf("%d %d %d %d %d %d\n",now,p,dep,cnt,wei[now],get(wei[now]));
	ver[cnt] = update( ver[pos[p]], get( wei[now] ) );
	cnt++;
	lv[now] = dep;
	mic[0][now] = p;
	for( int i = 0 ; i < g[now].size() ; i++ ) {
		if( g[now][i] != p && !mark[g[now][i]] )dfs( g[now][i], now, dep + 1 );
	}
	return ;
}

int lca( int a, int b ) {
	if( lv[a] > lv[b] )swap( a,b );
	for( int i = 17 ; i >= 0 ; i-- ) {
		if( lv[mic[i][b]] < lv[a] )continue;
		b = mic[i][b];
	}
	if( a == b )return a;
	for( int i = 17 ; i >= 0 ; i-- ){
		if( mic[i][a] == mic[i][b] )continue;
		a = mic[i][a], b = mic[i][b];
	}
	return mic[0][a];
}
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&wei[i]);
		all.emplace_back( wei[i] );
	}
	sort( all.begin(), all.end() );
	all.resize( unique( all.begin(), all.end() ) - all.begin() );
	for( int i = 0, u, v ; i < n - 1 ; i++ ) {
		scanf("%d %d",&u,&v);
		g[u].emplace_back( v ), g[v].emplace_back( u );
	}
	ver[0] = build();
	dfs( 1, 0, 1 );
	for( int i = 1 ; i <= 17 ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			mic[i][j] = mic[i-1][mic[i-1][j]];
		}
	}
	for( int i = 0, u, v, k ; i < m ; i++ ) {
		scanf("%d %d %d",&u,&v,&k);
		int lc = lca( u, v );
		printf("%d\n",all[query( ver[pos[u]], ver[pos[v]], ver[pos[lc]], ver[pos[mic[0][lc]]], k )-1]);
	}
	return 0;
}