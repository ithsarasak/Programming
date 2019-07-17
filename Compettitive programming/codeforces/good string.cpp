#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+50;
int t, n;
char s[N];
int main()
{
	scanf("%d",&t);
	while( t-- ) {
		int mx = 0, cnt = 0;
		scanf("%d",&n);
		scanf("%s",s+1);
		for( int i = 1 ; i <= n ; i++ ) {
			if( s[i] == '>' ) break;
			cnt++;
		}
		mx = cnt;
		cnt = 0;
		for( int i = n ; i >= 1 ; i-- ) {
			if( s[i] == '<' ) break;
			cnt++;
		}
		mx = min( mx, cnt );
		printf("%d\n",mx);
	}
	return 0;
}