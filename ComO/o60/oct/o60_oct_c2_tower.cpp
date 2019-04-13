#include <bits/stdc++.h>

using namespace std;
struct ss{
	int lvl, lvr, ma, b;
}seg[800100];
int n, m, lz[800100];
void build( int l, int r, int now )
{
	if( l == r ){
		seg[now].ma = 0;
		seg[now].lvl = 0;
		seg[now].lvr = 0;
		seg[now].b = 1;
		return ;
	}
	int mid = ( l + r ) /2;
	build( l, mid, now * 2 );
	build( mid + 1, r, now * 2 + 1 );
	seg[now].lvl = 0, seg[now].lvr = 0, seg[now].ma = 0, seg[now].b = 1;
	return ;
}
void up( int l, int r,int ll, int rr, int now, int va )
{
	if( lz[now] ){
		seg[now].lvl += lz[now];
		seg[now].lvr += lz[now];
		seg[now].ma += lz[now];
		if( l != r ){
			lz[now*2] += lz[now];
			lz[now*2+1] += lz[now];
		}
		lz[now] = 0;
	}
	if( l > rr || r < ll || l > r )return ;
	if( l >= ll && r <= rr ){
		seg[now].lvl += va;
		seg[now].lvr += va;
		seg[now].ma += va;
		if( l != r ){
			lz[now*2] += va;
			lz[now*2+1] += va;
		}
		return ;
	}
	int mid = ( l + r ) / 2;
	up( l, mid, ll, rr, now*2, va );
	up( mid + 1, r, ll, rr, now*2+1, va );
	seg[now].lvl = seg[now*2].lvl;
	seg[now].lvr = seg[now*2+1].lvr;
	if( seg[now*2].ma == seg[now*2+1].ma ){
		seg[now].b = seg[now*2].b + seg[now*2+1].b;
		if( seg[now*2].lvr == seg[now*2+1].lvl && seg[now*2].lvr == seg[now*2].ma ){
			seg[now].b--;
		}
		seg[now].ma = seg[now*2].ma;
	}
	else if( seg[now*2].ma > seg[now*2+1].ma ){
		seg[now].b = seg[now*2].b;
		seg[now].ma = seg[now*2].ma;
	}
	else{
		seg[now].b = seg[now*2+1].b;
		seg[now].ma = seg[now*2+1].ma;
	}
	return ;
}
int main()
{
	scanf("%d %d",&n,&m);
	build( 1, n, 1 );
	while( m-- ){
		int x, y, va;
		scanf("%d %d %d",&x,&y,&va);
		up( 1, n, x, y, 1, va );
		// for( int i = 1 ; i <= 10 ; i++ ){
		// 	printf("%d %d %d %d %d\n",i,seg[i].lvl,seg[i].lvr,seg[i].ma,seg[i].b);
		// }
		printf("%d %d\n",seg[1].ma,seg[1].b);
	}
	return 0;
}