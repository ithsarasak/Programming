#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 100;
pii pole[N];
int n, h, l, fw[N], L = 1, R = 1, ans;
vector<int> coor;
deque<pii> q;

int get( int x ){ return lower_bound( coor.begin(), coor.end(), x ) - coor.begin() + 1; }

int upd( int x ){ return upper_bound( coor.begin(), coor.end(), x ) - coor.begin() + 1; }

void update( int idx, int va ) {
	for( int i = idx ; i <= 1e5 + 50 ; i += ( i & -i ) )fw[i] += va;
}

int query( int l, int r ) {
	int sum = 0;
	for( int i = r ; i > 0 ; i -= ( i & -i ) )sum += fw[i];
	for( int i = l - 1 ; i > 0 ; i -= ( i & -i ) )sum -= fw[i];
	return sum;
}
	
int main()
{
	scanf("%d %d %d",&n,&h,&l);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d %d",&pole[i].x,&pole[i].y);
		pole[i].x++, pole[i].y++;
		coor.emplace_back( pole[i].y );
	}
	sort( coor.begin(), coor.end() );
	coor.resize( unique( coor.begin(), coor.end() ) - coor.begin() );
	while( L <= n ) {
		while( R <= n && pole[R].x - pole[L].x <= h ){
			update( get( pole[R].y ), 1 );
			R++;
		}
		for( int j = 0 ; j <= l ; j++ ) {
			ans = max( ans, query( get( pole[L].y - j ) , upd( pole[L].y - j + l ) - 1 ) );
		}
		update( get( pole[L].y ), -1 );
		L++;
	}
	printf("%d",ans);
	return 0;
}