#include "traffic.h"
#include <bits/stdc++.h>
#define iii tuple< int, int, int, int >
#define mt make_tuple

using namespace std;
int n, k;
vector<iii> ans;
int main()
{
	traffic_init( &n, &k );
	for( int i = 1 ; i <= n ; i++ ){
		if( traffic_query( i, 1, i, n ) > n - 1 ){
			int l = 1, r = n, st = 1;
			while( l < r ){
				int mid = ( l + r + 1 ) >> 1;
				if( traffic_query( i, st, i, mid ) > mid - st )r = mid - 1;
				else l = mid;
			}
			ans.push_back( mt( i, l, i, l + 1 ) );
			if( traffic_query( i, l + 1, i, n ) > n - l - 1 ){
				int le = l + 1, ri = n;
				st = l + 1;
				while( le < ri ){
					int mid = ( le + ri + 1 ) >> 1;
					if( traffic_query( i, st, i, mid ) > mid - st )ri = mid - 1;
					else le = mid;
				}
				ans.push_back( mt( i, le, i, le + 1 ) );
			}
		} 
	}
	for( int i = 1 ; i <= n ; i++ ){
		if( traffic_query( 1, i, n, i ) > n - 1 ){
			int l = 1, r = n, st = 1;
			while( l < r ){
				int mid = ( l + r + 1 ) >> 1;
				if( traffic_query( st, i, mid, i ) > mid - st )r = mid - 1;
				else l = mid;
			}
			ans.push_back( mt( l, i, l + 1, i ) );
			if( traffic_query( l + 1, i, n, i ) > n - l - 1 ){
				int le = l + 1, ri = n;
				st = l + 1;
				while( le < ri ){
					int mid = ( le + ri + 1 ) >> 1;
					if( traffic_query( st, i, mid, i ) > mid - st )ri = mid - 1;
					else le = mid;
				}
				ans.push_back( mt( le, i, le + 1, i ) );
			}
		} 
	}
	int a, b, c, d, a2, b2, c2, d2;
	tie( a, b, c, d ) = ans[0];
	if( k == 2 )tie( a2, b2, c2, d2 ) = ans[1];
	if( k == 1 )traffic_report( a, b, c, d, 0, 0, 0, 0 );
	else traffic_report( a, b, c, d, a2, b2, c2, d2 );
	return 0;
}