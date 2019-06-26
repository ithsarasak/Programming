#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int k;
long long ans;
char s[N];

int main()
{
    scanf("%d %s",&k,&s[1]);
    int len = strlen( &s[1] );
    for( int i = 1 ; i <= ( len >> 1 ) ; i++ ) {
        int cnt = 0;
        int e1 = i, e2 = i * 2, p1 = i, p2 = i * 2;
        for( ; p1 > 0 ; p1--, p2-- ) {
            if( s[p1] != s[p2] ) cnt++;
        }
        if( cnt <= k ) ans++;
        e1++, e2++;
        for( ; e2 <= len ; e1++, e2++ ) {
            if( s[e1] != s[e2] ) cnt++;
            if( s[e1] != s[e1-i] ) cnt--;
            if( cnt <= k ) ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}