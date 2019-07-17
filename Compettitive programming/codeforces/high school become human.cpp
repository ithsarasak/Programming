#include <bits/stdc++.h>

using namespace std;
int x, y;
int main()
{
	scanf("%d %d",&x,&y);
	if( y * log10( x ) < x * log10( y ) && x != y ){
		printf("<");
	}
	else if( y * log10( x ) > x * log10( y ) && x != y ){
		printf(">");
	}
	else{
		printf("=");
	}
	return 0;
}