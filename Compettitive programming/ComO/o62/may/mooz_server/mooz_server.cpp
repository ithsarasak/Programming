#include "mooz_server.h"
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 305;

vector<int> adj[maxn];
vector<int> path[maxn];
vector<int> subtree[maxn];
int par[maxn];
int mark[maxn];

bool vis[maxn];

int n;

int ecnt = 0;

void search(int u)
{
	vis[u] = true;
	while(true)
	{
		if(ecnt == n-1) return;
		vector<int> poss;
		for(int i = 1; i<= n; i++)
		{
			if(vis[i]) continue;
			poss.pb(i);
		}
		if(poss.empty()) return;
		if(poss.size() == 1)
		{
			vector<int> test;
			test.pb(poss[0]); test.pb(u);
			int x = get_component(test);
			if(x == 1)
			{
				adj[u].pb(poss[0]);
				adj[poss[0]].pb(u);
				search(poss[0]);
				ecnt++;
			}
			return;
		}
		int lo = 0, hi = (int) poss.size();
		while(lo< hi)
		{
			int mid = (lo+hi)/2;
			vector<int> give;
			for(int i = 0; i<= min(mid, (int) poss	.size()-1); i++) give.pb(poss[i]);
			int base = get_component(give);
			give.pb(u);
			int res = get_component(give);
			if(res == base+1) lo = mid+1;
			else hi = mid;
		}
		if(lo == (int) poss.size()) return;
		adj[u].pb(poss[lo]);
		adj[poss[lo]].pb(u);
		ecnt++;
		// printf("edge (%d, %d)\n", u, poss[lo]);
		search(poss[lo]);
	}
}
void dfs(int u, int p, vector<int> vec)
{
	subtree[u].pb(u);	
	path[u] = vec;
	for(int v : adj[u])
	{
		if(v == p) continue;
		vec.pb(v);
		par[v] = u;
		dfs(v, u, vec);
		for(int x : subtree[v])
		{
			subtree[u].pb(x);
		}
		vec.pop_back();
	}
}

vector< pair<int,int> > find_bridge(int N)
{
	n = N;
	search(1);
	dfs(1, 0, vector<int>(1, 1));
	for(int i = 1; i<= n; i++)
	{
		vector<int> cand = path[i];
		cand.pop_back();
		reverse(cand.begin(), cand.end());
		int lo = 0, hi = (int) cand.size()-1;
		while(lo< hi)
		{
			int mid = (lo+hi+1)/2;
			set<int> dontwant;
			vector<int> want;
			want = subtree[i];
			for(int j = mid; j< (int) cand.size(); j++) want.pb(cand[j]);
			// for(int j = 1; j<= n; j++) if(dontwant.find(j) == dontwant.end()) want.pb(j);
			// printf("want: [ ");
			// for(int x : want) printf("%d ", x);
			// printf("]\n");
			int res = get_component(want);
			// printf("res = %d\n", res);
			if(res == 1) lo = mid;
			else hi = mid-1; 
		}
		// printf("%d: [ ", i);
		// for(int x : cand) printf("%d ", x);
		// printf("]\n");
		// printf("lo = %d\n", lo);	
		if(lo)
		{
			int cur = i;
			while(cur != cand[lo])
			{
				mark[cur]++;
				cur = par[cur];
			}
		}
	}
	vector< ii > ans;
	for(int i = 2; i<= n; i++)
	{
		if(mark[i] == 0)
		{
			ans.pb(ii(par[i], i));
		}
	}
	return ans;
}