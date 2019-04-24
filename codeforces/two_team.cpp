#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first 
#define y second

using namespace std;

const int N = 2e5 + 100;
int n, k;
vector<pii> a(N);
queue<int> q;
set<int> idx;
char ans[N];

int main() 
{
	scanf("%d %d",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&a[i].x);
		a[i].y = i;
	}
	sort( a.begin(), a.end(), greater<pii>() );
	for( int i = 0 ; i < n ; i++ ) q.push( a[i].second );
	for( int i = 0 ; i < n ; i++ ) idx.insert( i );
	int who = 0;
	while ( !idx.empty() ) {
		while ( !idx.count( q.front() ) ) q.pop();
		int pos = q.front();
		q.pop();
		vector<int> add;
		auto it = idx.find( pos );
		for( int i = 0 ; i <= k ; i++ ) {
			add.push_back( *it );
			if( it == idx.begin() ) break;
			--it;
		}
		it = next( idx.find( pos ) );
		for( int i = 0 ; i < k ; i++ ) {
			if( it == idx.end() ) break;
			add.push_back( *it );
			++it;
		}
		for( auto it : add ) {
			idx.erase( it );
			ans[it] = '1' + who;
		}
		who ^= 1;
	}
	printf("%s",ans);
	return 0;
}