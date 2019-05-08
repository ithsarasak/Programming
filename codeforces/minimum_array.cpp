#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
multiset<int> b;

int main() 
{
	scanf("%d",&n);
	for( int i = 0, t ; i < n ; i++ ) {
		scanf("%d",&t);
        a.emplace_back( t );
	}
	for( int i = 0, t ; i < n ; i++ ) {
		scanf("%d",&t);
        b.insert( t );
    }
	for( int i = 0 ; i < n ; i++ ) {
		auto it = b.lower_bound( n - a[i] );
		if( it == b.end() ) it = b.begin();
	    printf("%d ",( a[i] + *it ) % n );
		b.erase( it );
	}
	return 0;
}