#include <bits/stdc++.h>

using namespace std;
int n;
string ans;
string w;
int main()
{
	scanf("%d",&n);
	cin >> w;
	int ch = 0;
	for( int i = 0 ; i < n - 1 ; i++ ){
		if( w[i] != w[i+1] ){
			ans += w[i];
			ans += w[i+1];
			ch = 1;
			break;
		}
	}
	if( ch == 0 )printf("NO");
	else{
		printf("YES\n");
		cout << ans;
	}
	return 0;
}
