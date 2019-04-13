#include <bits/stdc++.h>

using namespace std;
int n, people[110], ans;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&people[i]);
	}
	for( int i = 2 ; i < n ; i++ ){
		if( people[i-1] && people[i+1] && !people[i] ){
			ans ++;
			people[i+1] = 0;
		}
	}
	printf("%d",ans);
	return 0;
}