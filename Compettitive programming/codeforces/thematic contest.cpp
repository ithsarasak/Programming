#include <bits/stdc++.h>

using namespace std;
long long n;
vector<long long> ans;
long long check[20], ma;
vector<int> num, num2;
int main()
{
	scanf("%lld",&n);
	for( int i = 0 ; i < n ; i++ ){
		long long nn;
		scanf("%lld",&nn);
		num.push_back( nn );
	}
	sort( num.begin(), num.end() );
	int cc = 1;
	for( int i = 1 ; i < num.size() ; i++ ){
		if( num[i] != num[i-1] ){
			ans.push_back( cc );
			cc = 1;
		}
		else cc++;
	}
	ans.push_back( cc );
	sort( ans.begin(), ans.end() );
	long long ro = log2( n + 1 );
	for( long long i = 1 ; i <= ro ; i++ ){
		long long l = 0, r = n;
		while( l < r ){
			long long mid = ( l + r + 1 ) / 2;
			long long c = 0, now = mid;
			for( int j = 0 ; j < ans.size() ; j++ ){
				if( now > ans[ans.size()-1] )break;
				if( ans[j] >= now ){
					now *= 2;
					c++;
				}
				if( c >= i )break;
			}
			if( c != i )r = mid - 1;
			else l = mid;
		}
		check[i] = l;
	}
	for( long long i = 1 ; i <= ro ; i++ ){
		//cout << check[i] << endl;
		ma = max( ma, check[i] * ( ( 1 << ( long long )i ) - 1 ) );
	}
	printf("%lld",ma);
	return 0;
}