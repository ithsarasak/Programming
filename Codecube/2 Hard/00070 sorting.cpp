#include <bits/stdc++.h>

using namespace std;
int n, ans;
int num[200100], mark[200100], fen[200100];
int query( int idx )
{
	int sum = 0;
	for( int i = idx ; i > 0 ; i -= ( i &-i ) )sum += fen[i];
	return sum;
}
void up( int idx )
{
	for( int i = idx ; i <= n ; i += ( i & -i ) )fen[i] += 1;
	return ;
} 
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i]);
	}
	for( int i = 1 ; i <= n ; i++ ){
		int nu;
		scanf("%d",&nu);
		mark[nu] = i;
	}
	for( int i = 1 ; i <= n ; i++ ){
		num[i] = mark[num[i]];
	}
	ans = n + 1;
	for( int i = n ; i >= 1 ; i-- ){
		int move = query( num[i] - 1 );
		if( i + move != num[i] )ans = i;
		up( num[i] );
	}
	printf("%d",n-ans+1);
	return 0;
}
