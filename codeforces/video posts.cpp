#include <bits/stdc++.h>

using namespace std;
int n, k;
int num[100100], sum, sumnow;
vector<int> ans;
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&num[i]);
		sum += num[i];
	}
	if( sum % k ){
		printf("No");
		return 0;
	}
	sum /= k;
	int ch = 0, cnt = 0;
	for( int i = 0 ; i < n ; i++ ){
		sumnow += num[i];
		cnt++;
		if( sumnow == sum ){
			ans.push_back( cnt );
			cnt = 0;
			sumnow = 0;
		}
		else if( sumnow > sum ){
			ch = 1; 
			break;
		}
	}
	if( ch )printf("No");
	else{
		printf("Yes\n");
		for( int i = 0 ; i < ans.size() ; i++ )printf("%d ",ans[i]);
	}
	return 0;
}
