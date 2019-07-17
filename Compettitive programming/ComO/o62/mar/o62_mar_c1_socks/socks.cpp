#include <bits/stdc++.h>
#include "sockslib.h"
#define pii pair<int, int>
using namespace std;
int n, mark[2010], all, temp;
vector<int> v, le;

int solve( int l, int r ) {
	le.clear();
	if( l == r )return l;
	int mid = ( l + r ) >> 1;
	for( int i = l ; i <= mid ; i++ ) {
		le.emplace_back( v[i] );
	}
	int bef = ask( le );
	le.emplace_back( temp );
	int aft = ask( le );
	if( bef == aft ) return solve( l, mid );
	else return solve( mid + 1, r );
}
int main()
{
	n = num();
	all = n*2;
	for( int i = 1 ; i <= all ; i++ ) v.emplace_back( i );
	while( v.size() > 0 ) {
		temp = v[v.size()-1];
		int ans = solve( 0, v.size()- 2 );
		match( temp, v[ans] );
		v.pop_back();
		v.erase( v.begin() + ans );
	}
	return 0;
}

