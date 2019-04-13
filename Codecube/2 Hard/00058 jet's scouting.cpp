#include <bits/stdc++.h>
#define iii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

struct qq {
	int x, y, d, lv;
}t;

iii walk[10] = { iii( -1, 0, 0 ), iii( 0, 1, 1 ), iii( 1, 0, 2 ), iii( 0, -1, 3 ), iii( -1, -1, 4 ), iii( -1, 1, 5 ), iii( 1, 1, 6 ), iii( 1, -1, 7 ) };
pii gi[1010];
int r, c, n, ans[350][350][10], sx, sy;
char ma[350][350];
queue<qq> q;
	
int main()
{
	memset( ans, 127, sizeof ans );
	scanf("%d %d %d",&r,&c,&n);
	for( int i = 1 ; i <= r ; i++ ) scanf("%s",&ma[i][1]);
	for( int i = 0, x, y ; i < n ; i++ ) {
		scanf("%d %d",&x,&y);
		gi[i] = pii( x, y );
	}
	for( int i = 1 ; i <= r ; i++ ) for( int j = 1 ; j <= c ; j++ ) if( ma[i][j] == 'J' ) sx = i, sy = j;
	for( int i = 0 ; i < 8 ; i++ ) {
		int gx = sx + get<0>( walk[i] ), gy = sy + get<1>( walk[i] );
		if( gx >= 1 && gx <= r && gy >= 1 && gy <= c && ma[gx][gy] != '#' ) q.push({ gx, gy, get<2>( walk[i] ), 0 });
	}
	for( int i = 0 ; i < 10 ; i++ ) ans[sx][sy][i] = 0;
	while( !q.empty() ) {
		t = q.front();
		q.pop();
		ans[t.x][t.y][t.d] = t.lv;
		for( int i = 0 ; i < 4 ; i++ ) {
			int di = t.d / 4 * 4 + i;	
			if( abs( di - t.d ) == 2 ) continue ;
			int gx = t.x + get<0>( walk[di] ), gy = t.y + get<1>( walk[di] ), tgo = t.lv + ( ( di == t.d ) ? 0 : 1 );
			if( gx >= 1 && gx <= r && gy >= 1 && gy <= c && ans[gx][gy][di] > tgo && ma[gx][gy] != '#' ) {
				ans[gx][gy][di] = tgo;
				q.push({ gx, gy, di, tgo });
			}
		}
	}
	for( int i = 0 ; i < n ; i++ ) {
		int mi = 1e9;
		for( int j = 0 ; j < 8 ; j++ ) mi = min( mi, ans[gi[i].x][gi[i].y][j] );
		printf("%d\n",mi != 1000000000 ? mi : -1 );
	}
	return 0;
}