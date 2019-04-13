#include <bits/stdc++.h>

using namespace std;
struct gg{
	long long pos, tim, i;
	bool operator<( const gg &k )const{
		if( pos == k.pos )return i < k.i;
		else return pos < k.pos;
	}
};
vector<gg> all, survive, all2, all3;
long long ans[100100];
long long l;
long long n;
int check1( int i )
{
	if( all[i].tim >= all3[i+1].tim ){
		if(( all[i].pos ==  all3[i+1].pos - all[i].tim + all3[i+1].tim  && all[i].i < all3[i+1].i ) || ( all[i].pos < all3[i+1].pos - all[i].tim + all3[i+1].tim ) ){
			return 1;
		}
		else return 0;
	}
	else{
		return 1;
	}
}
int check2( int i )
{
	if( all[i].tim >= all2[i-1].tim ){
		if(( all[i].pos ==  all2[i-1].pos - all2[i-1].tim + all[i].tim && all[i].i < all2[i-1].i ) || ( all[i].pos > all2[i-1].pos  - all2[i-1].tim + all[i].tim ) ){
			return 1;
		}
		else return 0;
	}
	else{
		return 1;
	}
}
long long calf( int i )
{
	if( survive[i].tim > survive[i-1].tim ){
		long long ene = min( l, survive[i-1].pos - survive[i-1].tim  + survive[i].tim );
		if( ene == survive[i].pos )return survive[i].pos;
		if(( survive[i].pos - ene - ( long long )1 ) % ( long long )2 ){
			if( survive[i].i < survive[i-1].i )return max( ( long long )0, survive[i].pos - ( survive[i].pos - ene - ( long long )1 )/( long long )2 - ( long long )1 );
			else return max( ( long long )0, survive[i].pos - ( survive[i].pos - ene - ( long long )1 )/( long long )2 );
		}
		else return max( ( long long )0, survive[i].pos - ( survive[i].pos - ene - ( long long )1 )/( long long )2 )	;
	}
	else{
		long long ene = max( ( long long )0, survive[i].pos - survive[i-1].tim + survive[i].tim );
		if( ene == survive[i-1].pos )return min( l, ene + ( long long )1 );
		if(( ene - survive[i-1].pos - ( long long )1 ) % ( long long )2 ){
			if( survive[i].i < survive[i-1].i )return max( ( long long )0, ene - ( ene - survive[i-1].pos - ( long long )1 )/( long long )2 - ( long long )1 );
			else return max( ( long long )0, ene - ( ene - survive[i-1].pos - ( long long )1 )/( long long )2 );
		}
		else return max( ( long long )0, ene - ( ene - survive[i-1].pos - ( long long )1 )/( long long )2 );
	}
}
long long calt( int i )
{
	if( survive[i].tim > survive[i+1].tim ){
		long long ene = max( ( long long )0, survive[i+1].pos - survive[i].tim + survive[i+1].tim );
		if( ene == survive[i].pos )return survive[i].pos;
		if(( ene - survive[i].pos - ( long long )1 ) % ( long long )2 ){
			if( survive[i].i < survive[i+1].i )return min( l, survive[i].pos + ( ene - survive[i].pos - ( long long )1 )/( long long )2 + ( long long )1 );
			else return min( l, survive[i].pos + ( ene - survive[i].pos - ( long long )1 )/( long long )2 );
		}
		else return min( l, survive[i].pos + ( ene - survive[i].pos - ( long long )1 )/( long long )2 );
	}
	else{
		long long ene = min( l, survive[i].pos - survive[i].tim +  survive[i+1].tim  );
		if( ene == survive[i+1].pos )return max( ( long long )0, ene - ( long long )1 );
		if(( survive[i+1].pos - ene - ( long long )1 ) % ( long long )2 ){
			if( survive[i].i < survive[i+1].i )return min( l, ene + ( survive[i+1].pos - ene - ( long long )1 )/( long long )2 + ( long long )1 );
			else return min( l, ene + ( survive[i+1].pos - ene - ( long long )1 )/( long long )2 );
		}
		else return min( l, ene + ( survive[i+1].pos - ene - ( long long )1 )/( long long )2 );
	}
}
int main()
{
	scanf("%lld %lld",&n,&l);
	for( long long i = 1 ; i <= n ; i++ ){
		long long x, y;
		scanf("%lld %lld",&x,&y);
		all.push_back({ x, i+y, i });
		all2.push_back({ x, i+y, i });
		all3.push_back({ x, i+y, i });
	}
	sort( all.begin(), all.end() );
	sort( all2.begin(), all2.end() );
	sort( all3.begin(), all3.end() );
	/*for( int i = 0 ; i < all.size() ; i++ ){
		printf("%lld %lld %lld\n",all2[i].pos,all2[i].tim,all2[i].i);
	}*/
	for( int i = 1 ; i < all.size() ; i++ ){
		if( !check2( i ) )all2[i] = all2[i-1];
	}
	for( int i = all.size() - 2 ; i > 0 ; i-- ){
		if( !check1( i ) )all3[i] = all3[i+1];
	}
	/*for( int i = 0 ; i < all.size() ; i++ ){
		printf("%lld %lld %lld\n",all2[i].pos,all2[i].tim,all2[i].i);
	}*/
	for( int i = 0 ; i < all.size() ; i++ ){
		if( i == 0 ){
			if( check1( i ) )survive.push_back( all[i] );
		}
		else if( i == all.size() - 1 ){
			if( check2( i ) )survive.push_back( all[i] );
		}
		else{
			if( check1( i ) && check2( i ) )survive.push_back( all[i] );
			if( !check2( i ) )all[i] = all[i-1];
		}
	}
	for( int i = 0 ; i < survive.size() ; i++ ){
		long long f, t;
		if( i == 0 )f = ( long long )0;
		else{
			f = calf( i );
		}
		if( i == survive.size() - 1 )t = l;
		else{
			t = calt( i );
		}
		ans[survive[i].i] = t - f + ( long long )1;
	}
	for( int i = 1 ; i <= n ; i++ )printf("%lld\n",ans[i]);
	return 0;
}