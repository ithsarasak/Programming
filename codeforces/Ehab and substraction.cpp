#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> v;
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 0 ; i < n ; i++ ){
		int num;
		scanf("%d",&num);
		v.push_back( num );
	}
	v.push_back( 0 );
	sort( v.begin(), v.end() );
	v.resize( distance( v.begin() , unique( v.begin(), v.end() ) ) );
	for( int i = 1 ; i <= k ; i++ ){
		if( i >= v.size() ){
			printf("0\n");
		}
		else{
			printf("%d\n",v[i] - v[i-1]);
		}
	}
	return 0;
}