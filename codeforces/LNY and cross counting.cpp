#include <bits/stdc++.h>

using namespace std;
int n, cnt;
char ma[510][510];
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )scanf("%s",&ma[i][1]);
	for( int i = 2 ; i < n ; i++ ){
		for( int j = 2 ; j < n ; j++ ){
			if( ma[i-1][j-1] == 'X' && ma[i-1][j+1] == 'X' && ma[i][j] == 'X' && ma[i+1][j-1] == 'X' && ma[i+1][j+1] == 'X' )cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}