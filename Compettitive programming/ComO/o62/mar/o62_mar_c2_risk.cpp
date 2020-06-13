#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

int n, m, ans;
vector<pii> v1, v2, hull1, hull2;

long long d( pii a, pii b ) { return (b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y); }
long long area( pii a, pii b, pii c ) {
	return abs(a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y);
}

int orien( pii a, pii b, pii c ) {
	pii vec1( b.x - a.x, b.y - a.y );
	pii vec2( c.x - a.x, c.y - a.y );
	long long val = ( 1ll * vec1.x * vec2.y ) - ( 1ll * vec1.y * vec2.x );
	if( val == 0 ) return 0;
	else if( val > 0 ) return 2;
	else return 1;
}

void build_hull( vector<pii> v, vector<pii> &hull ) {
	sort( v.begin(), v.end(), [&]( const pii &a, const pii &b ){
		if( a.y != b.y ) return a.y > b.y;
		else return a.x > b.x;
	});
	pii st = v.back(); v.pop_back();
	sort( v.begin(), v.end(), [&]( const pii &a, const pii &b ) {
		int ori = orien( st, a, b );
		if( ori == 0 ) return d( st, a ) < d( st, b );
		else return ori == 2;
	});
	hull.emplace_back( st );
	for( pii i : v ) {
		while( hull.size() > 2 && orien( hull[(int)hull.size()-2], hull.back(), i ) != 2 ) hull.pop_back();
		hull.emplace_back( i );
	}
}

int checktri( pii a, pii b, pii c, pii k ) {
	long long all = area( a, b, c );
	long long one = area( a, b, k );
	long long two = area( b, c, k );
	long long three = area( c, a, k );
	return all == one + two + three;
}

int chk( pii po, vector<pii> &hull ) {
	if( po.y <= hull[0].y ) return po == hull[0];
	int l = 1, r = (int)hull.size() - 2;
	while( l < r ) {
		int mid = l + r + 1 >> 1;
		int ori = orien( hull[0], hull[mid], po );
		if( ori == 2 || ori == 0 ) l = mid;
		else r = mid - 1;
	}
	/*printf("CHECK : %lld %lld %lld %lld\n",hull[l].x,hull[l].y,po.x,po.y);
	printf("%d\n",checktri( hull[0], hull[l], hull[l+1], po ));*/
	return checktri( hull[0], hull[l], hull[l+1], po );
}

int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1, x, y ; i <= n ; i++ ) {
		scanf("%d %d",&x,&y);
		v1.emplace_back( x, y );
	}
	for( int i = 1, x, y ; i <= m ; i++ ) {
		scanf("%d %d",&x,&y);
		v2.emplace_back( x, y );
	}
	build_hull( v1, hull1 ), build_hull( v2, hull2 );
	/*printf("HULL1\n");
	for( pii i : hull1 ) printf("%lld %lld\n",i.x,i.y);
	printf("HULL2\n");
	for( pii i : hull2 ) printf("%lld %lld\n",i.x,i.y);*/
	for( pii i : v1 ) ans += chk( i, hull2 );
	for( pii i : v2 ) ans += chk( i, hull1 );
	printf("%d",ans);
	return 0;
}