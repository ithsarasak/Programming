#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
int t;
char s[N];
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        int n, cnt = 0;
        scanf("%d %s",&n,s);
        for( int i = 0 ; i < n ; i++ ) {
            if( s[i] == '8' ) break;
            else cnt++;
        }
        if( n - cnt >= 11 ) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}