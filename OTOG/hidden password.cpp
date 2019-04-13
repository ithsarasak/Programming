#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+100;
int n, mark[N], shift, mx, ans[N];
int main()
{
	scanf("%d",&n);
	for( int i = 1, t ; i <= n ; i++ ) {
		scanf("%d",&t);
		mark[t] = i;
	}
	for( int i = 1, t ; i <= n ; i++ ) {
		scanf("%d",&t);
		ans[(i-mark[t]+n)%n]++;
	}
	for( int i = 0 ; i <= n ; i++ ) {
		if( ans[i] > mx ) {
			mx = ans[i];
			shift = i;
		}
	}
	printf("%d %d",mx,shift);
	return 0;
}