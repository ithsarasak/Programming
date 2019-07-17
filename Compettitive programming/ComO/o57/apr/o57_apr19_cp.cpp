#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+100;

int n, m, seg[4*N], suf[N], pos[N], lcp[N];
set<int> red;
char s[N];
void gensuffix() {
	for( int i = 1 ; i <= n ; i++ ) suf[i] = i, pos[i] = s[i];
	for( int k = 1 ; k <= n ; k <<= 1 ) {
		auto chk = [&]( int a, int b ) {
			if( pos[a] != pos[b] ) return pos[a] < pos[b];
			if( a + k <= n && b + k <= n ) return pos[a+k] < pos[b+k];
			else return a > b;
		};
		int tmp[N];tmp[1] = 1;
		sort( suf + 1, suf + 1 + n, chk );
		for( int i = 1 ; i < n ; i++ ) tmp[i+1] = tmp[i] + chk( suf[i], suf[i+1] );
		for( int i = 1 ; i <= n ; i++ ) pos[suf[i]] = tmp[i];
	}	
	return ;
}

void genlcp() {
	for( int i = 1, k = 0;  i <= n ; i++ ) {
		if( pos[i] != n ) {
			for( int j = suf[pos[i]+1] ; s[i+k] == s[j+k] ; k++ );
			lcp[pos[i]] = k;
			if( k )k--;
		}
	}
}

void build( int l = 1, int r = n, int now = 1 ) {
	if( l == r ){
		seg[now] = lcp[l];
		return ;
	}
	int mid = ( l + r ) >> 1;
	build( l, mid, now*2 ), build( mid + 1, r, now*2+1 );
	seg[now] = min( seg[now*2], seg[now*2+1] );
	return ;
}

int query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
	if( ll > rr )swap( ll, rr );
	if( l > rr || r < ll || l > r ) return 1e9;
	if( l >= ll && r <= rr )return seg[now];
	int mid = ( l + r ) >> 1;
	return min( query( ll, rr, l, mid, now*2 ), query( ll ,rr, mid + 1, r, now*2+1 ) );
}

int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	gensuffix();
	genlcp();	
	build();
	red.insert( pos[1] );
	while( m-- ) {
		int op, wood, rb, mid, lb;
		scanf("%d %d",&op,&wood);
		if( op == 1 ) red.insert( pos[wood] );
		else{	
			auto it = red.lower_bound( pos[wood] );
			if( *it == pos[wood] && it != red.end() ){
				printf("%d\n",n-wood+1);
				continue;
			}
			int mx = 0, mid = pos[wood];
			if( it != red.end() ) mx = query( mid, *it - 1 );
			if( it != red.begin() ) {
				it--;
				mx = max( mx, query( *it, mid - 1 ) );
			}
			printf("%d\n",mx);
		}
	}
	return 0;
}