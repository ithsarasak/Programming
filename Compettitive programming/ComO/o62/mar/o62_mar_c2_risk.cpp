#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

int n, m, ans;
pii st;
vector<pii> a, b, hull, hull2;

int bad( pii a, pii b, pii c ) {
	pii one( b.x - a.x, b.y - a.y ), two( c.x - a.x, c.y - a.y );
	if( one.x * two.y - one.y * two.x < 0 ) return 1;
	else if( one.x * two.y - one.y * two.x == 0 ) return 0;
	return 2;
}

long long d( pii a, pii b ) { return ( long long )( a.x - b.x ) * ( long long )( a.x - b.x ) + ( long long )( a.y - b.y ) * ( long long )( a.y - b.y ); }

void make_hull( bool type ) {
	vector<pii> temp;
	if( type ) temp = a;
	else temp = b;
	sort( temp.begin(), temp.end(), [&]( const pii &a, const pii &b ) {
		if( a.y != b.y ) return a.y > b.y;
		return a.x > b.x;
	});
	st = temp.back(), temp.pop_back();
	sort( temp.begin(), temp.end(), [&]( const pii &a, const pii &b ) {
		int o = bad( st, a, b );
		if( o == 0 ) return d( st, a ) < d( st, b );
		return o == 2;
	});
	if( type ) hull.emplace_back( st ), hull.emplace_back( temp[0] );
	else hull2.emplace_back( st ), hull2.emplace_back( temp[0] );
	for( int i = 1 ; i < ( int )temp.size() ; i++ ) {
		if( type ) {
			while( hull.size() > 2 && bad( hull[hull.size()-2], hull[hull.size()-1], temp[i] ) != 2 ) hull.pop_back();
			hull.emplace_back( temp[i] );
		}
		else {
			while( hull2.size() > 2 && bad( hull2[hull2.size()-2], hull2[hull2.size()-1], temp[i] ) != 2 ) hull2.pop_back();
			hull2.emplace_back( temp[i] );
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		long long x, y;
		scanf("%lld %lld",&x,&y);
		a.emplace_back( pii( x, y ) );
	}
	for( int i = 1 ; i <= m ; i++ ) {
		long long x, y;
		scanf("%lld %lld",&x,&y);
		b.emplace_back( pii( x, y ) );
	}
	make_hull( true ), make_hull( false );
	for( int i = 0 ; i < n ; i++ ) {
		int check = -1, check2, cc = 0;
		for( int j = 0 ; j < hull2.size() ; j++ ) {
			check2 = bad( hull2[j], hull2[(j+1)%(int)(hull2.size())], a[i] );
			// printf("%d %d %d %d\n",check,check2,i,j);
			if( !check2 ) continue;
			else if( check == -1 ) check = check2;
			else if( check != check2 ) {
				cc = 1;
				break;
			}
		}
		if( !cc ) ans++;
	}
	for( int i = 0 ; i < m ; i++ ) {
		int check = -1, check2, cc = 0;
		for( int j = 0 ; j < hull.size() ; j++ ) {
			check2 = bad( hull[j], hull[(j+1)%(int)(hull.size())], b[i] );
			if( !check2 ) continue;
			else if( check == -1 ) check = check2;
			else if( check != check2 ) {
				cc = 1;
				break;
			}
		}
		if( !cc ) ans++;
	}
	printf("%d",ans);
	return 0;
}