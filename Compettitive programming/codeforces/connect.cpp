#include <bits/stdc++.h>

using namespace std;
struct qq{
	int x, y;
}tt;
queue<qq> q;
vector<qq> all[2510];
int di[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int n;
int sx, sy, ex, ey, visit[55][55], cnt;
int ans = 1e9;
char ma[55][55];
int cal( int a, int b ){
	return a*a + b*b;
}
void bfs( int x, int y )
{
	q.push({ x, y });
	while( !q.empty() ){
		tt = q.front();
		q.pop();
		visit[tt.x][tt.y] = cnt;
		all[cnt].push_back({ tt.x, tt.y });
		for( int i = 0 ; i < 4 ; i++ ){
			int gx = tt.x + di[i][0], gy = tt.y + di[i][1];
			if( gx >= 1 && gx <= n && ma[gx][gy] == '0' && !visit[gx][gy] ){
				visit[gx][gy] = cnt;
				q.push({ gx, gy });
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
	for( int i = 1 ; i <= n ; i++ )scanf("%s",&ma[i][1]);
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			if( !visit[i][j] && ma[i][j] == '0' ){
				cnt++;
				bfs( i, j );
			}
		}
	}
	// printf("\n");
	// for( int i = 1 ; i <= n ; i++ ){
	// 	for( int j = 1 ; j <= n ; j++ ){
	// 		printf("%d ",visit[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	int cf = visit[sx][sy], cg = visit[ex][ey];
	if( cf == cg ){
		printf("0");
		return 0;
	}
	for( int i = 0 ; i < all[cf].size() ; i++ ){
		//printf("%d %d : ",all[cf][i].x,all[cf][i].y);
		for( int j = 0 ; j < all[cg].size() ; j++ ){
			//printf("%d %d ",all[cg][j].x,all[cg][j].y);
			ans = min( ans, cal( all[cf][i].x - all[cg][j].x, all[cf][i].y - all[cg][j].y ) );
		}
		//printf("\n");
	}
	printf("%d",ans);
	return 0;
}