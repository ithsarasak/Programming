#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int n, m, k, tart[N];
int usel[N], user[N];

bool check( int mid ) {
	int mx = 0, sumnow = 1e9, cnt = 0, cnt2 = 0;
	memset( usel, 0, sizeof usel );
	memset( user, 0, sizeof user );
	for( int i = 1 ; i <= n ; i++ ) {
		if( tart[i] > mid ) cnt = 1e9;
		else if( sumnow + tart[i] > mid ) cnt++, sumnow = 0, cnt2 = 0;
		else if( cnt2 == m ) sumnow = 0, cnt++, cnt2 = 0; 
		sumnow += tart[i];
		cnt2++;
		usel[i] = cnt;
	}
	cnt = 0, sumnow = 1e9, cnt2 = 0;
	for( int i = n ; i >= 1 ; i-- ) {
		if( tart[i] > mid ) cnt = 1e9;
		else if( sumnow + tart[i] > mid ) cnt++, sumnow = 0, cnt2 = 0;
		else if( cnt2 == m ) sumnow = 0, cnt++, cnt2 = 0;
		sumnow += tart[i];
		cnt2++;
		user[i] = cnt;
	}
	for( int i = m ; i <= n ; i++ ) {
		if( usel[i-m] + user[i+1] <= k - 1 ) return true;
	}
	return false;
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for( int i = 1 ; i <= n ; i++ ) scanf("%d",&tart[i]);
	int l = 0, r = 1e9;
	while( l < r ) {
		int mid = ( l + r ) >> 1;
		if( check( mid ) ) r = mid;
		else l = mid + 1;
	}
	printf("%d",l);
	return 0;
}