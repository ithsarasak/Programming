#include <bits/stdc++.h>
#define pic pair<int, char>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 10;

int n;
string res;

int main() 
{
    ios_base::sync_with_stdio( false ), cin.tie( NULL );
	scanf("%d",&n);
	vector<int> a( n );
	for( int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
	int l = 0, r = n - 1;
	int lst = 0;
	while( l <= r ) {
		vector<pic> cur;
		if( lst < a[l] ) cur.push_back( pic( a[l], 'L' ) );
		if( lst < a[r] ) cur.push_back( pic( a[r], 'R' ) );
		sort( cur.begin(), cur.end() );
		if( int( cur.size() ) == 2 && cur[0].x != cur[1].x ) cur.pop_back();
		if( int( cur.size() ) == 1 ) {
			if( cur[0].y == 'L' ) res += 'L', lst = a[l++];
            else res += 'R', lst = a[r--];
		} 
        else if( int( cur.size() ) == 2 ) {
			int cl = 1, cr = 1;
			while( l + cl <= r && a[l+cl] > a[l+cl-1] ) cl++;
			while( r - cr >= l && a[r-cr] > a[r-cr+1] ) cr++;
			if( cl > cr ) res += string( cl, 'L' );
			else res += string( cr, 'R' );
			break;
		} 
        else break;
	}
	cout << res.size() << endl << res;
    return 0;
}