#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
 
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD		1000000007
#define EPS		1E-10
 
const LL maxval = MOD;
const int maxn = 300005;
vector<int> owner[maxn];
LL reqd[maxn];
int ql[maxn],qr[maxn];
LL qa[maxn];
int lo[maxn], hi[maxn];
vector<int> tocheck[maxn];
 
long long tree[maxn];
int n,m;
int k;
long long maxi=0;
void update(int x, long long val){
	while(x<=m){
		tree[x]+=val;
		//[x]=min(tree[x],maxi);
		x+=(x&-x);
 
	}
}
long long read(int x){
	long long s=0;
	while(x>0){
		s+=tree[x];
		//s=min(tree[x],maxi);
		x-=(x&-x);
	}
	return s;
}
 
void apply(int x){
	if(ql[x]<=qr[x])
		update(ql[x],qa[x]),update(qr[x]+1,-qa[x]);
	else{
		update(1,qa[x]);
		update(qr[x]+1,-qa[x]);
		update(ql[x],qa[x]);
	}
}
 
int main()
{
	cin(n);
	cin(m);
	for(int i = 1; i <= m; i++)
	{
		int x;
		cin(x);
		owner[x].pb(i);
	}
	for(int i = 1; i <= n; i++)
		scanf("%lld",&reqd[i]);
	cin(k);
	for(int i = 1; i <= k; i++)
	{
		cin(ql[i]);
		cin(qr[i]);
		scanf("%lld",&qa[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		lo[i] = 1;
		hi[i] = k + 1;
	}
	bool changed = true;
	while(changed)
	{
		changed = false;
 
		// clean up mess.
		for(int a = 0; a <= m; a++)
			tree[a] = 0;
		for(int i = 1; i <= n; i++)
			if(lo[i] != hi[i])
				tocheck[ (lo[i] + hi[i]) >> 1 ].pb(i);
		// end of cleaning up
 
		for(int q = 1; q <= k; q++)
		{
			apply(q);
 
			while(sz(tocheck[q]))
			{
				changed = true;
				int id = tocheck[q].back();
				tocheck[q].pop_back();
 
				LL sum = 0;
				for(auto sectors: owner[id])
				{
					sum += read(sectors);
					if(sum >= reqd[id]) break;
				}
				if(sum >= reqd[id])
					hi[id] = q;
				else
					lo[id] = q + 1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		assert(lo[i] == hi[i]);		
		if(lo[i] <= k)
			printf("%d\n",lo[i]);
		else
			printf("NIE\n");
	}
	return 0;
}