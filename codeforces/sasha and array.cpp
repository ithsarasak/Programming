#include <bits/stdc++.h>

long long mod = 1e9+7;
long long lz[(1<<18)+444];
struct mm{
	long long mat[2][2];
	mm operator*( const mm &b ){
		mm c;
		for( int i = 0 ; i < 2 ; i++ ){
			for( int j = 0 ; j < 2 ; j++ ){
				long long sum = 0;
				for( int k = 0 ; k < 2 ; k++ )sum = ( sum + mat[i][k] * b.mat[k][j] ) % mod;
				c.mat[i][j] = sum;
			}
		}
		return c;
	}
	mm operator+( const mm &b ){
		mm c;
		for( int i = 0 ; i < 2 ; i++ ){
			for( int j = 0 ; j < 2 ; j++ ){
				c.mat[i][j] = ( mat[i][j] + b.mat[i][j] ) % mod;
			}
		}
		return c;
	}
}seg[(1<<18)+444], mul[50], st, t, pi, expo, temp, help;
int n, m;
long long arr[100100];
mm cal( long long x )
{
	mm tt = temp;
	for( long long i = 48 ; i >= 0 ; i-- ){
		if( x & (( long long )1 << i ) ){
			tt = tt * mul[i];
		}
	}
	return tt;
}
inline void build( int s, int e, int now )
{
	if( s == e ){
		t = st;
		seg[now] = t*cal( arr[s] - 1 );
		return ;
	}
	int le = now*2, ri = now*2+1;
	int mid = ( s + e ) >> 1;
	build( s, mid, le );
	build( mid + 1, e, ri );
	seg[now] = seg[le] + seg[ri];
	return ;
} 
inline void up( int s, int e, int ss, int ee, int val, int now )
{
	int le = now*2, ri = now*2+1;
	if( lz[now] ){
		seg[now] = seg[now]*cal( lz[now] );
		if( s != e ){
			lz[le] += lz[now];
			lz[ri] += lz[now];
		}
		lz[now] = 0;
	}
	if( s > ee || e < ss || s > e )return ;
	if( s >= ss && e <= ee ){
		seg[now] = seg[now]*help;
		if( s != e ){
			lz[le] += val;
			lz[ri] += val;
		}
		return ;
	}
	int mid = ( s + e ) >> 1;
	up( s, mid, ss, ee, val, le), up( mid + 1, e, ss, ee, val, ri );
	seg[now] = seg[le] + seg[ri];
	return ;
}
inline long long query( int s, int e, int ss, int ee, int now )
{
	int le = now*2, ri = now*2+1;
	if( lz[now] ){
		seg[now] = seg[now]*cal( lz[now] );
		if( s != e ){
			lz[le] += lz[now];
			lz[ri] += lz[now];
		}
		lz[now] = 0;
	}
	if( s > ee || e < ss || s > e )return 0;
	if( s >= ss && e <= ee ){
		return seg[now].mat[0][0];
	}
	int mid = ( s + e ) >> 1;
	return ( query( s, mid, ss, ee, le ) + query( mid + 1, e, ss, ee, ri ) ) % mod;
}
int main()
{
	st.mat[0][0] = 1, st.mat[0][1] = 0, st.mat[1][0] = 0, st.mat[1][1] = 0;
	temp.mat[0][0] = 1, temp.mat[0][1] = 0, temp.mat[1][0] = 0, temp.mat[1][1] = 1;
	expo.mat[0][0] = 1, expo.mat[0][1] = 1, expo.mat[1][0] = 1, expo.mat[1][1] = 0;
	mul[0] = expo;
	for( int i = 1 ; i <= 48 ; i++ )mul[i] = mul[i-1]*mul[i-1];
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )scanf("%lld",&arr[i]);
	build( 1, n, 1 );
	while( m-- ){
		int op, l, r;
		long long x;
		scanf("%d %d %d",&op,&l,&r);
		if( op == 1 ){
			scanf("%lld",&x);
			help = cal( x );
			up( 1, n, l, r, x, 1 );
		}
		else{
			printf("%lld\n",query( 1, n, l, r, 1 ));
		}
	}
	return 0;
}