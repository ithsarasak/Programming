#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> lis;
int main()
{
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		int num;
		scanf("%d",&num);
		if( lis.empty() )lis.emplace_back( num );
		else{
			if( num > lis[lis.size()-1] )lis.emplace_back( num );
			else{ 
				int idx = lower_bound( lis.begin(), lis.end(), num ) - lis.begin();
				lis[idx] = num;
			}
		}
	}
	printf("%d",lis.size());
	return 0;
}