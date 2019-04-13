#include <bits/stdc++.h>

using namespace std;
struct nn{
	long long va;
	int pos;
	bool operator<( const nn &k )const{
		return va > k.va;
	}
}num[200100];
int n;
vector<int> ans;
long long sum;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%lld",&num[i].va);
		num[i].pos = i;
		sum += num[i].va;
	}
	sort( num + 1, num + 1 + n );
	if( sum - num[1].va == 2*num[2].va )ans.push_back( num[1].pos );
	for( int i = 2 ; i <= n ; i++ ){
		if( sum - num[i].va == 2*num[1].va )ans.push_back( num[i].pos );
	}
	printf("%d\n",ans.size());
	for( int i = 0 ; i < ans.size() ; i++ ){
		printf("%d ",ans[i]);
	}
	return 0;
}