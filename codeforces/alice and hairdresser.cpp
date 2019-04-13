#include <bits/stdc++.h>

using namespace std;
struct ss{
	long long lvl, lvr, b;
}seg[400100];
long long n, m;
long long le, hair[100100];
void build( int l, int r, int now )
{
	if( l == r ){
		seg[now].lvl = hair[l];
		seg[now].lvr = hair[l];
		if( hair[l] > le )seg[now].b = 1;
		else seg[now].b = 0;
		return ;
	}
	int mid = ( l + r ) /2;
	build( l, mid, now * 2 );
	build( mid + 1, r, now * 2 + 1 );
	seg[now].lvl = seg[now*2].lvl, seg[now].lvr = seg[now*2+1].lvr;
	seg[now].b = seg[now*2].b + seg[now*2+1].b;
	if( seg[now*2].lvr > le && seg[now*2+1].lvl > le )seg[now].b -= 1;
	return ;
}
void up( int l, int r,int idx, int now, long long va )
{
	if( l > idx || r < idx || l > r )return ;
	if( l == r ){
		seg[now].lvl += va;
		seg[now].lvr += va;
		if( seg[now].lvl > le )seg[now].b = 1;
		else seg[now].b = 0;
		return ;
	}
	int mid = ( l + r ) / 2;
	up( l, mid, idx,  now*2, va );
	up( mid + 1, r, idx, now*2+1, va );
	seg[now].lvl = seg[now*2].lvl, seg[now].lvr = seg[now*2+1].lvr;
	seg[now].b = seg[now*2].b + seg[now*2+1].b;
	if( seg[now*2].lvr > le && seg[now*2+1].lvl > le )seg[now].b -= 1;
	//printf("%d %d %lld %lld %lld %d\n",l,r,seg[now*2].b,seg[now*2+1].b,seg[now].b,now);
	return ;
}
int main()
{
	scanf("%d %d %lld",&n,&m,&le);
	for( int i = 1 ; i <= n ; i++ )scanf("%lld",&hair[i]);
	build( 1, n, 1 );
	while( m-- ){
		int c, a;
		long long va;
		scanf("%d",&c);
		if( c ){
			scanf("%d %lld",&a,&va);
			up( 1, n, a, 1, va );
		}
		else{
			printf("%d\n",seg[1].b);
		}
	}
	return 0;
}