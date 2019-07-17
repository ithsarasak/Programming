#include <bits/stdc++.h>

using namespace std;
struct ee{
	int a, b, d;
};
struct gg{
    int t, d;
};
vector<ee> e;
vector<gg> g[100100];
int n;
map<int,long long> dp[100100];
map<int,long long>::iterator it;
vector<long long> ans;
vector<int> op;
int st[100100];
int par[100100];
int findroot( int num )// union find
{
	if( par[num] == num )return num;
	else return par[num] = findroot( par[num] );
}
void dfs( int now, int p, int sum )
{
    st[now] = sum;
    for( int i = 0 ; i < g[now].size() ; i++ ){
        if( g[now][i].t == p )continue;
        dfs( g[now][i].t, now, sum ^ g[now][i].d );
    }
}
void sol( int pos )// sol
{
    int a = findroot( e[pos].a ), b = findroot( e[pos].b );
    long long pp = 0;
    if( dp[a].size() < dp[b].size() )swap( a, b );
    for( it = dp[b].begin() ; it != dp[b].end(); it++ ){
        pp += dp[a][it->first] * it->second;
        dp[a][it->first] += it->second;
    }
    par[b] = a;
    ans.push_back( ans[ans.size()-1] + pp );
}
int main()
{
	for( int i = 1 ; i <= 100000 ; i++ )par[i] = i;
	scanf("%d",&n);
	for( int i = 1 ; i < n ; i++ ){
		int a, b, d;
		scanf("%d %d %d",&a,&b,&d);
		g[a].push_back({ b, d });
		g[b].push_back({ a, d });
		e.push_back({ a, b, d });// all edge
	}
	for( int i = 1 ; i < n ; i++ ){
		int o;
		scanf("%d",&o);
		op.push_back( o - 1 );// order op
	}
	dfs( 1, 1, 0 );
	for( int i = 1 ; i <= n ; i++ ){
        dp[i][st[i]] = 1;
	}
	ans.push_back( 0 );
	for( int i = op.size()-1 ; i >= 0 ; i-- ){
		sol( op[i] );
	}
	for( int i = ans.size()-1 ; i >= 0 ; i-- ){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
