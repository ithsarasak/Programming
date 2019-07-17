#include <bits/stdc++.h>

using namespace std;

const int N = 129;
long long mod = 1e9 + 7, ans;
int r, c;

struct mm{
	long long mat[N][N];
	friend mm operator*( const mm &a, const mm &b ) {
		mm c;
		memset( c.mat, 0, sizeof c.mat );
		for( int k = 0 ; k < N ; k++ ) for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ) {
			c.mat[i][j] = ( c.mat[i][j] + a.mat[i][k] * b.mat[k][j] ) % mod;
		}
		return c;
	}
}st, mul;

void permute( int now, int mark, int pro ) {
    if( now == r ){
        for( int i = 0 ; i < ( 1<<r ) ; i++ ) if( !( i&pro ) ) mul.mat[mark][i]++;
        return ;
    }
    if( !( mark & ( 1<<now ) ) ) {
        permute( now + 1 , mark|( 1<<now ), pro|( 1<<now ) );
        if( now + 1 != r ) permute( now + 1, mark|( 1<<now ) | ( 1<<( now + 1 ) ), pro );
    }
    permute( now + 1, mark, pro );
    return ;
}

void permute2( int now, int mark ) {
    if( now == r ) {
        st.mat[mark][0]++;
        return ;
    }
    if( !( mark & ( 1<<now ) ) && now + 1 != r ) permute2( now + 1, mark | ( 1<<now )| ( 1<<( now + 1 ) ) );
    permute2( now + 1, mark );
    return ;
}

void power( int po ) {
	for( ; po ; po >>= 1 ) {
		if( po & 1 ) st = mul * st;
		mul = mul * mul;
	}
	return ;
}

int main()
{
	scanf("%d %d",&r,&c);
	permute( 0, 0, 0 ), permute2( 0, 0 );
	power( c - 1 );
	for( int i = 0 ; i < ( 1<<r ) ; i++ ) ans = ( ans + st.mat[i][0] ) % mod;
	printf("%lld",ans); 
	return 0;
}