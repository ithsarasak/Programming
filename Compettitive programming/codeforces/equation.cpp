#include <bits/stdc++.h>

using namespace std;
long long s, x, d, che, ans = 1, ch;
int bitx[50], bitd[50];
int main()
{
	cin >> s >> x;
	che = x;
	if( ( s - x ) % 2 || s < x ){
		printf("0");
		return 0;
	}
	d = ( s - x ) / ( long long )2;
	int cnt = 0;
	while( x > 0 ){
		bitx[cnt] = x % 2;
		x /= 2;
		cnt++;
	}
	cnt = 0;
	while( d > 0 ){
		bitd[cnt] = d % 2;
		d /= 2;
		cnt++;
	}
	for( int i = 0 ; i <= 45 ; i++ ){
		//printf("%d %d\n",bitx[i],bitd[i]);
		if( bitx[i] && !bitd[i] ){
			ans *= 2;
		}
		else if( bitx[i] && bitd[i] ){
			ch = 1;
			break;
		}
	}
	if( ch ){
		printf("0");
		return 0;
	}
	if( 0^s == che )ans -= 2;
	cout << ans;
	return 0;
}