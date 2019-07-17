#include <bits/stdc++.h>

using namespace std;
string s;
int l;
int main()
{
	scanf("%d",&l);
	cin >> s;
	for( int i = 0 ; i < l - 1 ; i++ ){
		if( s[i] > s[i+1] ){
			s.erase( s.begin() + i );
			break;
		}
	}
	if( l == s.length() )s.erase( s.begin() + l - 1 );
	cout << s;
	return 0;
}