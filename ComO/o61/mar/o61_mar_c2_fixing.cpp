#include <bits/stdc++.h>

using namespace std;
int n, m, k, ans;
vector<int> a;
int broke[100100];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for( int i = 0 ; i < m ; i++ ){
		scanf("%d",&broke[i]);
	}
	sort( broke, broke + m );
	for( int i = 0 ; i < m ; i++ ){
		if( i > 0 ){
			a.push_back( broke[i] - broke[i-1] - 1 );
		}
	}
	sort( a.begin(), a.end(), greater<int>() );
	// for( int i = 0 ; i < a.size() ; i++ )printf("%d ",a[i]);
	// printf("\n");
	for( int i = k - 1 ; i < a.size() ; i++ ){
		ans += a[i];
	}
	printf("%d",ans);
	return 0;
}