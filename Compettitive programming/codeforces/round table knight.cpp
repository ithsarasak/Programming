#include <bits/stdc++.h>

using namespace std;
vector<int> prime = { 1, 2, 3, 4, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401};
int n;
const int maxn = 1e5 + 100;
int num[maxn], sum[maxn];
int sq;
int check( int pri )
{
	memset( sum, 0 ,sizeof sum );
	int fac = n / pri, ch = 0;
	for( int i = 1 ; i <= n ; i++ ){
		if( i <= fac ){
			sum[i] = num[i];
		}
		else{
			sum[i] = num[i] + sum[i-fac];
		}
		if( sum[i] == pri ){
			ch = 1;
			break;
		}
	}
	if( ch == 1 )return 1;
	else return 0;
}
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i]);
	}
	sq = sqrt( n );
	int now = 0;
	while( prime[now] <= sq ){
		if( n % prime[now] == 0 ){
			int ans = 0;
			if( prime[now] >= 3 ){
				ans |= check( prime[now] );
			}
			if( n / prime[now] >= 3 ){
				ans |= check( n / prime[now] );
			}
			if( ans ){
				printf("YES");
				return 0;
			}
		}
		now++;
	}
	printf("NO");
	return 0;
}