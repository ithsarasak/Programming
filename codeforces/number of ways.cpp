#include <bits/stdc++.h>

using namespace std;
long long a[500100], sum, part, ans , n;
vector<int> posl, posr;
int main()
{
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%lld",&a[i]);
		sum += a[i];
	}
	if( sum % 3 != 0 ){
		printf("0");
		return 0;
	}
	part = sum/3;
	sum = 0;
	for( int i = 1 ; i <= n ; i++ ){
		sum += a[i];
		if( sum == part )posl.push_back( i );
	}
	sum = 0;
	for( int i = n ; i >= 1 ; i-- ){
		sum += a[i];
		if( sum == part )posr.push_back( i );
	}
	sort( posr.begin(), posr.end() );
	if( posr.size() == 0 || posl.size() == 0 ){
		printf("0");
		return 0;
	}
	// for( int i = 0 ; i < posl.size() ; i++ )printf("%d ",posl[i]);
	// printf("\n");
	// for( int i = 0 ; i < posr.size() ; i++ )printf("%d ",posr[i]);
	// printf("\n");
	for( int i = 0 ; i < posl.size() ; i++ ){
		if( posl[i] >= posr[posr.size()-1] )break;
		int idx = upper_bound( posr.begin(), posr.end(), posl[i] ) - posr.begin();
		if( posr[idx] == posl[i] + 1 )idx++;
		ans += posr.size()-idx;
	}
	printf("%lld",ans);
	return 0;
}