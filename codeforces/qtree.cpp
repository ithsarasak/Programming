#include <bits/stdc++.h>

using namespace std;

struct gg{
	int t, d;
};
vector<gg> g[10100];
vector<int> ind[10100];
int chainnum, chainhead[10100], chainInd[10100], pos[10100], to[10100], basearray[10100], seg[40400], pa[15][10100], lv[10100], cnt, sub[10100], n;
void build( int s, int e, int cur )
{
	if( s == e ){
		seg[cur] = basearray[s];
		return ;
	}
	int mid = ( s + e ) / 2;
	build( s, mid, cur * 2 );
	build( mid + 1, e, cur * 2 + 1 );
	seg[cur] = max( seg[cur*2], seg[cur*2+1] );
	return ;
}
void update( int s, int e, int idx, int val, int cur )
{
	if( s > idx || e < idx || s > e )return;
	if( s == e ){
		seg[cur] = val;
		return ;
	}
	int mid = ( s + e ) / 2;
	update( s, mid, idx, val, cur*2 );
	update( mid + 1, e, idx, val, cur*2+1 );
	seg[cur] = max( seg[cur*2], seg[cur*2+1] );
	return ;  
}
int lca( int a, int b )
{
    long long ma = 0;
    if ( lv[a] < lv[b] )swap( a, b );
    for( int i = 13 ; i >= 0 ; i-- ){
        if( lv[pa[i][a]] >= lv[b] )a  = pa[i][a];
    }
    if( a == b ){
        return a;
    }
    for( int i = 13 ; i >= 0 ; i-- ){
        if( pa[i][a] != pa[i][b] ){
            a = pa[i][a];
            b = pa[i][b];
        }
    }
    return pa[0][a];
}
int query_tree( int s, int e, int ss, int ee, int cur )
{
	if( ss > e || ee < s )return -1e9;
	if( ss >= s && e <= ee )return seg[cur];
	int mid = ( s + e ) / 2;
	return max( query_tree( s, mid, ss, ee, cur*2 ), query_tree( mid + 1, e, ss, ee, cur*2+1 ) );
}
int query_up( int a, int b )
{
	if( a == b )return 0;
	int achain, bchain = chainInd[b], ans = -1;
	while( 1 ){
		achain = chainInd[a];
		if( achain == bchain ){
			if( a == b )break;
			//printf("a %d b %d posa %d posb %d\n",a,b,pos[a],pos[b]);
			ans = max( ans, query_tree( 1, cnt, pos[b], pos[a], 1 ) );
			break;
		}
		ans = max( ans, query_tree( 1, cnt, pos[chainhead[achain]], pos[a], 1 ) );
		a = chainhead[achain];
		a = pa[0][a];
	}
	return ans;
}
void query( int a, int b )
{
	int lc = lca( a, b );
	printf("%d\n",max( query_up( a, lc ), query_up( b, lc ) ) );
	return ;
}
void change( int idx, int val )
{
	update( 1, cnt, pos[to[idx]], val, 1 );
}
void HLD( int no, int cost, int p )
{
	if( chainhead[chainnum] == -1 )chainhead[chainnum] = no;
	chainInd[no] = chainnum;
	cnt++;
	pos[no] = cnt;
	basearray[cnt] = cost;

	int sc = -1, ccost;
	for( int i = 0 ; i < g[no].size() ; i++ ){
		if( g[no][i].t != p && ( sc == -1 || sub[sc] < sub[g[no][i].t] ) ){
			sc = g[no][i].t;
			ccost = g[no][i].d;
		}
	}
	if( sc != -1 )HLD( sc, ccost, no );
	for( int i = 0 ; i < g[no].size() ; i++ ){
		if( g[no][i].t != p && g[no][i].t != sc ){
			chainnum++;
			HLD( g[no][i].t , g[no][i].d, no );
		}
	}
}

void dfs( int no, int p, int dep )
{
	pa[0][no] = p;
	lv[no] = dep;
	sub[no] = 1;
	for( int i = 0 ; i < g[no].size() ; i++ ){
		if( g[no][i].t != p ){
			to[ind[no][i]] = g[no][i].t;
			dfs( g[no][i].t, no, dep + 1 );
			sub[no] += sub[g[no][i].t];
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while( t-- ){
		cnt = 0;
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ ){
			g[i].clear();
			ind[i].clear();
			chainhead[i] = -1;
			for( int j = 0 ; j < 14 ; j++ )pa[j][i] = 0;
		}
		for( int i = 1 ; i <= n ; i++ ){
			int u, v, c;
			scanf("%d %d %d",&u,&v,&c);
			g[v].push_back({ u, c });
			ind[v].push_back( i );
			g[u].push_back({ v, c });
			ind[u].push_back( i ); 
		}
		chainnum = 0;
		dfs( 1, 0, 1 );
		HLD( 1, -1, -1 );
		build( 1, cnt, 1 );
		for( int i = 1 ; i < 14 ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				pa[i][j] = pa[i-1][pa[i-1][j]];
		while( 1 ){
			char ss[10];
			scanf("%s",ss);
			if( ss[0] == 'D' )break;
			int a, b;
			scanf("%d %d",&a,&b);
			if( ss[0] == 'Q' ){
				query( a, b );
			}
			else{
				change( a, b );
			}
		}
	}
}