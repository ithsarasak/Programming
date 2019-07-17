#include <bits/stdc++.h>

using namespace std;
int mark[150], one, two, n, num[150];
int a, b;
char ans[150];
int main()
{
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&num[i]);
		mark[num[i]]++;
	}
	for( int i = 0 ; i < n ; i++ ){
		if( mark[num[i]] == 1 )one++;
		else if( mark[num[i]] > 2 )two++;
	}
	if( one % 2 == 0 ){
		for( int i = 0 ; i < n ; i++ ){
			if( mark[num[i]] == 1 ){
				if( a <= b ){
					a++;
					ans[i] = 'A';
				}
				else{
					b++;
					ans[i] = 'B';
				}
			}
			else ans[i] = 'A';
		}
		printf("YES\n");
		printf("%s",ans);
		return 0;
	}
	else{
		if( two == 0 ){
			printf("NO");
			return 0;
		}
		printf("YES\n");
		for( int i = 0 ; i < n ; i++ ){
			if( mark[num[i]] == 1 ){
				if( a <= b ){
					a++;
					ans[i] = 'A';
				}
				else{
					b++;
					ans[i] = 'B';
				}
			}
			else if( mark[num[i]] == 2 ){
				ans[i] = 'A';
			}
		}
		int ch = 0;
		for( int i = 0 ; i < n ; i++ ){
			if( mark[num[i]] > 2 ){
				if( !ch ){
					ans[i] = 'B';
					ch = 1;
				}
				else ans[i] = 'A';
			} 
		}
		printf("%s",ans);
	}
	return 0;
} 