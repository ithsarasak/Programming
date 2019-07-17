#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+100;
struct qq{
	int r, va, ty, pos;
	bool operator<( const qq &k )const {
		return r < k.r; 
	}
};
int fw1[N], fw2[N], n, he[N], ans[N];
long long sum ;
vector<qq> query1, query2;

void up1( int idx ) { for( int i = idx ; i < N ; i += ( i & -i ) ) fw1[i] += 1; }
void up2( int idx ) { for( int i = idx ; i < N ; i += ( i & -i ) ) fw2[i] += 1; }

int qfw1( int idx ) {
	int ret1 = 0, ret2 = 0;
	for( int i = N - 1 ; i > 0 ; i -= ( i & -i ) ) ret2 += fw1[i];
	for( int i = idx ; i > 0 ; i -= ( i & -i ) ) ret1 += fw1[i];
	return ret2 - ret1;
}

int qfw2( int idx ) {
	int ret = 0;
	for( int i = idx - 1 ; i > 0 ; i -= ( i & -i ) ) ret += fw2[i];
		return ret;
}

int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) scanf("%d",&he[i]);
	for( int i = 1, d ; i <= n ; i++ ) {
		scanf("%d",&d);
		query1.push_back({ max( 0, i-1-d ), he[i], -1, i });
		query1.push_back({ i-1, he[i], 1, i });
		query2.push_back({ i, he[i], -1, i });
		query2.push_back({ min( n, i+d ), he[i], 1, i });
	}
	sort( query1.begin(), query1.end() ), sort( query2.begin(), query2.end() );
	int x = 1;
	for( int i = 0 ; i < query1.size() ; i++ ) {
		while( x <= query1[i].r ) {
			up1( he[x] );
			x++;
		}
		ans[query1[i].pos] += query1[i].ty * qfw1( query1[i].va );
	}
	x = 1;
	for( int i = 0 ; i < query2.size() ; i++ ) {
		while( x <= query2[i].r ) {
			up2( he[x] );
			x++;
		}
		ans[query2[i].pos] += query2[i].ty * qfw2( query2[i].va );
	}
	for( int i = 1 ; i <= n ; i++ ) sum += ( long long )ans[i];
	printf("%lld",sum);
	return 0;
}