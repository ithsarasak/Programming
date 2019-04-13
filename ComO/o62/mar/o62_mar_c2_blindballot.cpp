#include <bits/stdc++.h>

using namespace std;

const int N = 2e4+10;
struct qq{
	int now, lv;
}t;
int n, w, visit1[N], visit2[N], cnt, ind[N];
stack<int> s;
queue<qq> q;
unordered_map<int, int> m[N], m2[N];
vector<int> g[N], g2[N], g3[N], ans[N], col[N];


void dfs( int now ) {
	visit1[now] = true;
	for( int i  : g[now] ) if( !visit1[i] ) dfs( i );
	s.push( now );
}

void dfs2( int now ) {
	visit2[now] = cnt;
	col[cnt].emplace_back( now );
	for( int i  : g2[now] ) if( !visit2[i] ) dfs2( i );
}

int main()
{
	scanf("%d %d",&n,&w);
	for( int i = 0, t, a, b, c ; i < w ; i++ ) {
		scanf("%d %d %d %d",&t,&a,&b,&c);
		if( t == 1 ) {
			if( a != b && m[a][b] == 0 ) g[a].emplace_back( b ), g2[b].emplace_back( a ), m[a][b] = 1;
			if( a != c && b != c && m[a][c] == 0 ) g[a].emplace_back( c ), g2[c].emplace_back( a ), m[a][c] = 1;
		}
		else if( t == 2 ) {
			if( b != a && m[b][a] == 0 ) g[b].emplace_back( a ), g2[a].emplace_back( b ), m[b][a] = 1;
			if( c != a && b != c && m[c][a] == 0 ) g[c].emplace_back( a ), g2[a].emplace_back( c ), m[c][a] = 1;
		}
		else {
			if( a != b && m[a][b] == 0 ) g[a].emplace_back( b ), g[b].emplace_back( a ), g2[a].emplace_back( b ), g2[b].emplace_back( a ), m[a][b] = 1, m[b][a] = 1;
			if( b != c && m[b][c] == 0 ) g[b].emplace_back( c ), g[c].emplace_back( b ), g2[b].emplace_back( c ), g2[c].emplace_back( b ), m[b][c] = 1, m[c][b] = 1;
			if( a != c && m[a][c] == 0 ) g[a].emplace_back( c ), g[c].emplace_back( a ), g2[a].emplace_back( c ), g2[c].emplace_back( a ), m[a][c] = 1, m[c][a] = 1;
		}
	}
	for( int i = 1 ; i <= n ; i++ ) {
		if( !visit1[i] ) {
			visit1[i] = true;
			dfs( i );
		}
	}
	while( !s.empty() ) {
		int t = s.top();
		s.pop();
		if( visit2[t] == 0 ) {
			cnt++;
			dfs2( t );
		}
	}
	for( int i = 1 ; i <= n ; i++ ) for( int j : g[i] ) {
		if( m2[visit2[i]][visit2[j]] == 0 && visit2[i] != visit2[j] ) {
			ind[visit2[j]]++;
			g3[visit2[i]].emplace_back( visit2[j] );
			m2[visit2[i]][visit2[j]] = 1;
		}
	}
	for( int i = 1 ; i <= cnt ; i++ ) if( ind[i] == 0 && col[i].size() != 0 ) q.push({ i, 1 });
	while( !q.empty() ) {
		t = q.front();
		q.pop();
		ans[t.lv].emplace_back( t.now );
		for( int i : g3[t.now] ) {
			ind[i]--;
			if( ind[i] == 0 ) q.push({ i, t.lv + 1 });
		}
	}
	int cntt = 0;
	for( int i = 2e4 ; i >= 1 ; i-- ) if( ans[i].size() != 0 ) cntt++;
	printf("%d\n",cntt);
	for( int i = 20000 ; i >= 1 ; i-- ) {
		if( ans[i].size() == 0 ) continue;
		vector<int> temp;
		for( int j : ans[i] ) for( int k = 0 ; k < col[j].size() ; k++ ) {
				temp.emplace_back( col[j][k] );
		}
		if( temp.size() == 0 ) continue;
		printf("%d ",temp.size());
		sort( temp.begin(), temp.end() );
		for( int j : temp ) printf("%d ",j);
		printf("\n");
	}
	return 0;
}