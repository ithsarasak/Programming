#include <bits/stdc++.h>

using namespace std;
int pos[3100], num[3100];
int n;
vector<int> lis;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		int nu;
		scanf("%d",&nu);
		pos[nu] = i;
	}
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i]);
		num[i] = pos[num[i]];
	}
	for( int i = 1 ; i <= n ; i++ ){
		if( lis.empty() )lis.emplace_back( num[i] );
		else{
			if( num[i] > lis[lis.size()-1] )lis.emplace_back( num[i] );
			else{ 
				int idx = lower_bound( lis.begin(), lis.end(), num[i] ) - lis.begin();
				lis[idx] = num[i];
			}
		}
	}
	printf("%d",lis.size());
	return 0;
}