#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[100100], mark[100100], qs[100100];
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )scanf("%d",&a[i]);
	for( int i = 1 ; i <= n ; i++ ){
		if( !mark[a[i]] )mark[a[i]] = i;
		else{
			qs[mark[a[i]]] = 1;
			mark[a[i]] = i;
		} 
	}
	for( int i = 1 ; i <= n ; i++ )qs[i] += qs[i-1];
	while( m-- ){
		int l;
		scanf("%d",&l);
		printf("%d\n",n-l+1-qs[n]+qs[l-1]);
	}
	return 0;
}