#include <bits/stdc++.h>

using namespace std;
struct pp{
	int x, y;
};
struct qq{
	int x, y, ti;
}t;
int sx, sy, ex, ey;
vector<pp> walk = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
queue<qq> q;
int n, m;
char ma[310][310];
int mi = 1e9;
int tim[310][310][5], mark[310][310][5];
int check( int i, int j, int ti )
{
	if( i >= 1 && i <= n && j >= 1 && j <= m && tim[i][j][ti] != 1 && ( ma[i][j] == '.' || ma[i][j] == 'S' || ma[i][j] == 'E' ) ) return 1;
	else return 0;
} 
void sets( int x, int y, int va, char op )
{
	int i, j;
	tim[x][y][0] = 1, tim[x][y][1] = 1, tim[x][y][2] = 1, tim[x][y][3] = 1;
	if( op == '|' ){
		i = x - 1, j = y;
		while( i >= 1 && ma[i][j] == '.' )tim[i][j][va] = 1, i--;
		i = x + 1, j = y;
		while( i <= n && ma[i][j] == '.' )tim[i][j][va] = 1, i++;
	}
	else if( op == '/' ){
		i = x - 1, j = y + 1;
		while( i >= 1 && j <= m && ma[i][j] == '.' )tim[i][j][va] = 1, i--, j++;
		i = x + 1, j = y - 1;
		while( i <= n && j >= 1 && ma[i][j] == '.' )tim[i][j][va] = 1, i++, j--;
	}
	else if( op == '-' ){
		j = y - 1, i = x;
		while( j >= 1 && ma[i][j] == '.' )tim[i][j][va] = 1, j--;
		j = y + 1, i = x;
		while( j <= m && ma[i][j] == '.' )tim[i][j][va] = 1, j++;
	}
	else{
		i = x - 1, j = y - 1;
		while( i >= 1 && j >= 1 && ma[i][j] == '.' )tim[i][j][va] = 1, i--, j--;
		i = x + 1, j = y + 1;
		while( i <= n && j <= m  && ma[i][j] == '.' )tim[i][j][va] = 1, i++, j++;
	}
}
void setma()
{
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= m ; j++ ){
			if( ma[i][j] == '|' )sets( i, j, 0, '|'), sets( i, j, 1, '/'), sets( i, j, 2, '-'), sets( i, j, 3, 92 );
			else if( ma[i][j] == '/' )sets( i, j, 0, '/'), sets( i, j, 1, '-'), sets( i, j, 2, 92 ), sets( i, j, 3, '|');
			else if( ma[i][j] == '-' )sets( i, j, 0, '-'), sets( i, j, 1, 92 ), sets( i, j, 2, '|'), sets( i, j, 3, '/');
			else if( ma[i][j] == 92 )sets( i, j, 0, 92 ), sets( i, j, 1, '|' ), sets( i, j, 2, '/'), sets( i, j, 3, '-' );
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	memset( tim, 0, sizeof tim );
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%s",&ma[i][1]);
	}
	setma( );
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= m ; j++ ){
			if( ma[i][j] == 'S' )sx = i, sy = j;
			else if( ma[i][j] == 'E' )ex = i, ey = j;
		}
	}
	q.push({ sx, sy, 0 });
	for( int i = 0 ; i < 310 ; i++ )for( int j = 0 ; j < 310 ; j++ )for( int k = 0 ; k < 5 ; k++ )mark[i][j][k] = 1e9 + 1;
	mark[sx][sy][0] = 0;
	while( !q.empty() ){
		t = q.front();
		q.pop();
		for( int i = 0 ; i < 4 ; i++ ){
			int tex = t.x + walk[i].x, tey = t.y + walk[i].y, teti = t.ti + 1;
			if( check( tex, tey, teti % 4 ) && teti < mark[tex][tey][teti%4] ){
				mark[tex][tey][teti%4] = teti;
				q.push({ tex, tey, teti });
			}
		}
	}
	for( int i = 0 ; i < 4 ; i++ ){
		mi = min( mi, mark[ex][ey][i] );
	}
	if( mi == 1e9 )printf("-1");
	else printf("%d",mi);
	return 0;
}