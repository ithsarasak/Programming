#include <bits/stdc++.h>

using namespace std;
const int N = 1e6;
int a, b, c, d, masum, ans, ansx, ansy;
int dp[N+10];
int main()
{
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for( int i = 2 ; i <= N ; i++ )if( !dp[i] ){
		dp[i] = 1;
		for( int j = i + i ; j <= N ; j += i ){
			if( dp[j/i] )dp[j] = dp[j/i]+1;
		}
	}
	//printf("hh");
	for( int i = 2 ; i <= N ; i++ ){
		int a1 = b / i, a2 = d / i;
		if( a1 * i >= a and a2 * i >= c ){ 
			if( dp[i] > ans ){
				ans = dp[i];
				ansx = a1*i, ansy = a2*i;
				masum = ansx + ansy;
			}
			else if( dp[i] == ans ){
				if( a1*i + a2*i > masum ){
					ansx = a1*i,ansy = a2*i;
					masum = ansx + ansy;
				} 
				else if( a1*i + a2*i == masum ){
					if( ansx < a1*i ){
						ansx = a1*i, ansy = a2*i;
						masum = ansx + ansy;
					}
				}
			}
		}
	}
	printf("%d %d",ansx,ansy);
	return 0;
} 