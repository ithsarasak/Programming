#include <bits/stdc++.h>

using namespace std;
struct nn{
	int pos, com;
	bool operator<( const nn &k )const{
		return  pos < k.pos;
	}
}num[100100];
int n, ans = 1e9, par[100100];
int findroot( int num ){
	if( par[num] == num )return num;
	else return par[num] = findroot( par[num] );
}
int main()
{
	for( int i = 1 ; i <= 100000 ; i++ )par[i] = i;
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i].pos);
		num[i].com = i;
	}
	sort( num + 1, num + 1 + n );
	for( int i = 0 ; i < n - 2 ; i++ ){
		int f, t;
		scanf("%d %d",&f,&t);
		int a = findroot( f );
		int b = findroot( t	);
		if( a != b ){
			par[a] = b;
		}
	}
	for( int i = 1 ; i <= n - 1 ; i++ ){
		int a = findroot( num[i].com );
		int b = findroot( num[i+1].com );
		if( a != b ){
			ans = min( ans, num[i+1].pos - num[i].pos );
		}
	}
	printf("%d",ans);
	return 0;
}