#include <bits/stdc++.h>

using namespace std;
int n;
int mic[100100];
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		int num;
		scanf("%d",&num);
		if( i < 3 )continue;
		mic[i] = max( mic[i-1], num + mic[i-3] );
	}
	printf("%d",mic[n]);
	return 0;
}