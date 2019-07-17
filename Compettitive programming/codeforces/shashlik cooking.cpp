#include <bits/stdc++.h>
 
using namespace std;
int n, k;
vector<int> ans;
int main()
{
	scanf("%d %d",&n,&k);
	int range = 2 * k + 1;
	int mod = n % range;
	if( mod == 0 || mod > k + 1 ){
		int pos = k+1;
		while( pos <= n ){
			ans.push_back( pos );
			pos += 2*k + 1;
		}
	}
	else{
		int pos = 1;
		while( pos <= n ){
			ans.push_back( pos );
			pos += 2*k+1;
		}
	}
	printf("%d\n",ans.size());
	for( int i = 0 ; i < ans.size() ; i++ ){
		printf("%d ",ans[i]);
	}
	return 0;
}