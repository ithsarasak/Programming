#include <bits/stdc++.h>

using namespace std;
int q, n;
char num[310];
int main()
{
	scanf("%d",&q);
	while( q-- ){
		scanf("%d",&n);
		scanf("%s",num);
		if( n == 2 && num[0] >= num[1] ){
			printf("NO\n");
			continue;
		}
		printf("YES\n2\n");
		printf("%c ",num[0]);
		for( int i = 1 ; i < n ; i++ )printf("%c",num[i]);
		printf("\n");
	}
	return 0;
}
cabacaba