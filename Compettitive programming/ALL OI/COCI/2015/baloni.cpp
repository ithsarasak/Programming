#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 10;
int n, h[N], arrow[N], tot = 0;
 
int main()
{
    scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&h[i]);
		if( !arrow[h[i]] ) {
			tot++;
			arrow[h[i]-1]++;
		}
		else {
			arrow[h[i]]--;
			arrow[h[i]-1]++;
		}
	}
    printf("%d",tot);
}