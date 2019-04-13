#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 9;
int n, m, k, cnt;

struct mm {
	long long mat[150][150];
	friend mm operator*( const mm &a, const mm &b ) {
		mm c;
		memset( c.mat, 0, sizeof c.mat );
		for( int k = 1 ; k < 150 ; k++ ) for( int i = 1 ; i < 150 ; i++ ) for( int j = 1 ; j < 150 ; j++ ) {	
			c.mat[i][j] = ( c.mat[i][j] + a.mat[i][k] * b.mat[k][j] ) % mod;
		}
		return c;
	}
}st, mul;

void power( int k ) {
	for( ; k ; k >>= 1 ) {
		if( k & 1 ) st = st * mul;
		mul = mul * mul;
	}
}

int main()
{
	for( int i = 1 ; i < 150 ; i++ ) for( int j = 1 ; j < 150 ; j++ ) if( i == j ) st.mat[i][j] = 1;
	scanf("%d %d %d",&n,&m,&k);
	cnt = n;
	for( int i = 0, u, v, d, d2, st, en ; i < m ; i++ ) {
		scanf("%d %d %d",&u,&v,&d);
		st = u, d2 = d;
		while( d2 > 0 ) {
			if( d2 == 1 ) en = v;
			else en = ++cnt;
			mul.mat[st][en]++;
			st = en;
			d2--;
		}
		st = v;
		while( d > 0 ) {
			if( d == 1 ) en = u;
			else en = ++cnt;
			mul.mat[st][en]++;
			st = en;
			d--;
		}
	}
	power( k );
	for( int i = 1 ; i <= n ; i++ ) printf("%lld\n",st.mat[1][i]);
	return 0;
}