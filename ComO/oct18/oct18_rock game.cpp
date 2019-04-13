#include <bits/stdc++.h>

using namespace std;
int n, rock[60], mem[60][60];
int play( int l, int r )
{
	if( l + 1 == r )return mem[l][r] = max( rock[l],rock[r] );
	else if( l == r )return mem[l][r] = rock[l];
	if( mem[l][r] != -1 )return mem[l][r];
	int ans = 0;
	ans = max( ans, rock[l] + play( l+1, r-1 ) );
	ans = max( ans, rock[r] + play( l+1, r-1 ) );
	ans = max( ans, rock[l] + play( l+2, r ) );
	ans = max( ans, rock[r] + play( l, r-2 ));
	return mem[l][r] = ans;
}
int main()
{
	memset( mem, -1, sizeof mem );
	scanf("%d",&n);
	for( int i = 1 ; i <= 2*n ; i++ ){
		scanf("%d",&rock[i]);
	}
	play( 1, 2*n );
	printf("%d",mem[1][2*n]);
	return 0;
}