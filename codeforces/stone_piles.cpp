#include <bits/stdc++.h>

using namespace std; 

const int N = 1e2 + 10;
char s[N];
int n, mi, now;
int main()
{
    scanf("%d %s",&n,s);
    int len = strlen( s );
    for( int i = 0 ; i < len ; i++ ) {
        if( s[i] == '-' ) now--;
        else now++;
        mi = min( mi, now );
    }
    printf("%d",-1*mi + now );
    return 0;
}