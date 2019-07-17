#include <bits/stdc++.h>

using namespace std;
int fen[300100];
vector<int> ch[30];
char s[300100], w[100100];
int mode, len, len2, cursor[30];
long long cost;
void up( int idx, int va )
{
	for( int i = idx ; i <= len ; i += ( i & -i ) ){
		fen[i] += va;
	}
	return ;
}
long long query( int idx ){
	long long sum  =0;
	for( int i = idx ; i > 0 ; i-= ( i & -i ) ){
		sum += ( long long )fen[i];
	} 
	return sum;
}
int main()
{
	scanf("%d",&mode);
	scanf("%s",&s[1]);
	len = strlen( &s[1] );
	for( int i = 1 ; i <= len ; i++ ){
		ch[s[i]-'a'+1].push_back( i );
		up( i, 1 );
	}
	scanf("%s",&w[1]);
	int check = 0;
	len2 = strlen( &w[1] );
	for( int i = 1 ; i <= len2 ; i++ ){
		if( cursor[w[i]-'a'+1] >= ch[w[i]-'a'+1].size() ){
			check = 1;
			break;
		}
		cost += query( ch[w[i]-'a'+1][cursor[w[i]-'a'+1]] );
		if( mode == 1 ){
			up( ch[w[i]-'a'+1][cursor[w[i]-'a'+1]], -1 );
		}
		cursor[w[i]-'a'+1]++;
	}	
	if( check )printf("-1");
	else printf("%lld",cost);
	return 0;
}