#include <bits/stdc++.h>

using namespace std;

const int N = 4200;
long long k, po[N], hsh[N][6], P = 1e9+7, all;
char s[N][N];
int n, m;

int f( char c ) {
    if( c == 'A' ) return 1;
    else if( c == 'T' ) return 2;
    else if( c == 'C' ) return 3;
    else return 4;
}

int main()
{
    scanf("%d %d %lld",&n,&m,&k);
    po[0] = 1;
    for( int i = 1 ; i <= n ; i++ ) po[i] = po[i-1] * P, all += po[i]; 
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%s",&s[i][1]);
        for( int j = 1 ; j <= m ; j++ ) hsh[j][f(s[i][j])] += po[i];
    }
    for( int i = 1 ; i <= n ; i++ ) {
        long long now = 0;
        for( int j = 1 ; j <= m ; j++ ) now += all - hsh[j][f(s[i][j])];
        //printf("%lld\n",now);
        if( now + k*po[i] == all * k ) return !printf("%d",i);
    }
    return 0;
}   