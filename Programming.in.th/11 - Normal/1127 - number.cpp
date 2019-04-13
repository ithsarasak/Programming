#include <bits/stdc++.h>

using namespace std;

int en, z, mi = 1e9, va[15], num, p[110], s, s2;
int main()
{
	scanf("%d",&en);
	for( int i = 1 ; i <= 9 ; i++ ){
		scanf("%d",&va[i]);
		if( mi >= va[i] ){
			mi = va[i];
			num = i;
		}
	}
	for( ; en >= mi ; en -= mi, s++ ) p[s] = num;
	for( int i = 0 ; i < s && en >= 0 ; i++ ) for( int j = 9 ; j > p[i] ; j-- ){
		if( va[j] - va[p[i]] <= en ){
			en -= ( va[j] - va[p[i]] );
			p[i] = j;
			break;
		}
	}
	for( int i = 0 ; i < s ; i++ ) printf("%d",p[i]);
	return 0;
}