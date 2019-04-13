#include <bits/stdc++.h>

using namespace std;
int n;
int ans;
string a, b;
int main()
{
	scanf("%d",&n);
	cin >> a >> b;
	for( int i = 0 ; i < n ; i++ ){
		if( a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1] ){
			ans += 1;
			i++;
		}
		else if( a[i] != b[i] )ans++;
	}
	printf("%d",ans);
	return 0;
}