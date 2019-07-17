#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 100;
long long mul[85], qs[N*1000], sum, base = 1e9 + 7;
int w, s, cnt;
char gly[N], word[N*1000];

int main()
{
	mul[0] = base;
	for( int i = 1 ; i <= 80 ; i++ ) mul[i] = mul[i-1] * base;
	scanf("%d %d",&w,&s);
	scanf("%s %s",&gly[1],&word[1]);
	for( int i = 1 ; i <= w ; i++ ) sum += mul[gly[i]-'A'];
	for( int i = 1 ; i <= s ; i++ ) qs[i] = qs[i-1] + mul[word[i]-'A'];
	for( int i = w ; i <= s ; i++ ) if( qs[i] - qs[i-w] == sum ) cnt++;
	printf("%d",cnt);
	return 0;
}