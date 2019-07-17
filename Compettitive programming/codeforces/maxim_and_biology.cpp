#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, ans = 1e9;
char s[N];

int cala( char c ) { return min( abs( c - 'A' ), 26 - abs( c - 'A' ) ); }
int calc( char c ) { return min( abs( c - 'C' ), 26 - abs( c - 'C' ) ); } 
int calt( char c ) { return min( abs( c - 'T' ), 26 - abs( c - 'T' ) ); }
int calg( char c ) { return min( abs( c - 'G' ), 26 - abs( c - 'G' ) ); }

int main()
{
    scanf("%d %s",&n,s);
    for( int i = 0 ; i < n - 3 ; i++ ) ans = min( ans, cala( s[i] ) + calc( s[i+1] ) + calt( s[i+2] ) + calg( s[i+3] ) );
    printf("%d",ans);
    return 0;
}