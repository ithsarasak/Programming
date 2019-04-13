#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second
using namespace std;	

struct line{
	long long m, c;
	line() {} 
	line( long long m, long long c ) : m( m ), c( c ) {}
	long long f( long long x ){ return m*x + c; }
};

const int N = 5e4+100;
int n, pos;
long long dp[N];
vector<line> l;
vector<pii> v, u;

bool bad( line a, line b, line c ) { return ( ( c.c - a.c ) * ( a.m - b.m ) <= ( b.c - a.c ) * ( a.m - c.m )  ); }

void add( long long x, long long c ) {
	line now( x, c );
	while( l.size() >= 2 && bad( l[l.size()-2], l[l.size()-1], now ) ) l.pop_back();
	l.emplace_back( now );
	return ;
}

long long query( long long x ) {
	while( ( pos <= ( int )( l.size() ) - 2 ) && ( l[pos].f(x) > l[pos+1].f(x) ) ) pos++;
	return l[pos].f(x);  
}
int main()
{
	// fill_n(t, 4*N, line(0, 1e18));
	scanf("%d",&n);
	for( int i = 1; i <= n ; i++ ) {
		long long a, h, z;
		scanf("%lld %lld %lld",&a,&h,&z);
		v.emplace_back( pii( a*h, z ) );
	}
	sort( v.begin(), v.end() );
	u.emplace_back( pii( 0, 1e18 ) ); 
	for( auto i : v ) {
		while( i.y >= ( u.back().y ) ) u.pop_back();
		u.emplace_back( i );
	}
	v = u;
	// for( auto i : v ) printf("%lld %lld\n",i.x,i.y);
	for( int i = 1 ; i < v.size() ; i++ ) {
		add( v[i].y, dp[i-1] );
		dp[i] = query( v[i].x );
		// printf("%lld\n",v[i].x);
	}
	printf("%lld",dp[v.size()-1]);
	return 0;
}