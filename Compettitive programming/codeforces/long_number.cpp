#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m[10], st;
char a[N];
int main()
{
    scanf("%d %s",&n,a);
    for( int i = 1 ; i <= 9 ; i++ ) scanf("%d",&m[i]);
    for( int i = 0 ; i < n ; i++ ) {
        if( m[a[i]-'0'] > a[i] - '0' ) st = 1;
        if( m[a[i]-'0'] < a[i] - '0' && st ) break;
        if( st ) a[i] = m[a[i]-'0'] + '0';
    }
    printf("%s",a);
    return 0;
}