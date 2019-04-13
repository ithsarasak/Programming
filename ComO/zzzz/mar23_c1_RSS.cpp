#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 1e5+100;
const long base = 1e9+7;
int n, q;
long hashnow, mul = 1;
char s[N];
unordered_map<long,int> m;
int main() 
{
	scanf("%s",s+1);
	n = strlen( &s[1] );
	scanf("%d",&q);
	while( q-- ) {
		int len;
		scanf("%d",&len);
		hashnow = 0, m.clear(),mul = 1;
		for( int i = 1 ; i <= len ; i++ ) {
			hashnow = ( hashnow + s[i]-'a'+1 )*base;
			mul *= base;
		}
		int mx = ++m[hashnow];
		for( int i = len+1 ; i <= n ; i++ ) {
			hashnow = ( ( hashnow-(s[i-len]-'a'+1)*mul )+ s[i]-'a'+1 ) * base ;
			mx = max( mx, ++m[hashnow] ); 
		}
		printf("%d\n",mx);
	}
	return 0;
}