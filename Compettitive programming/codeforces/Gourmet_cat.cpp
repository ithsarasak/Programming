#include <bits/stdc++.h>

using namespace std;

int a, b, c, A = 3, B = 2, C = 2;
long long ans;
vector<int> food = { 0, 1, 2, 0, 2, 1, 0 };

int main() 
{
	scanf("%d %d %d",&a,&b,&c);
	int A = 3, B = 2, C = 2;
	for( int i = 0 ; i < 7 ; i++ ) {
		int tmp = min({ a / A, b / B, c / C });
		int X = a - A * tmp, Y = b - B * tmp, Z = c - C * tmp;
		long long day = tmp * 7;
		for( int j = i ; ; j = ( j + 1 ) % 7 ) {
			if( food[j] == 0 and X == 0 ) break;
			if( food[j] == 0 and X != 0 ) X--;
			if( food[j] == 1 and Y == 0 ) break;
			if( food[j] == 1 and Y != 0 ) Y--;
			if( food[j] == 2 and Z == 0 ) break;
			if( food[j] == 2 and Z != 0 ) Z--;
			day++;
		}
		ans = max( ans, day );
	}
	printf("%lld\n", ans);
	return 0;
}