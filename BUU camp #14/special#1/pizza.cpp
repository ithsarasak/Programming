#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int n, h[2*N], ans;
int main()
{
    for( int i = 0 ; i < 8 ; i++ ) {
        scanf("%d",&h[i]);
        h[i+8] = h[i];
    }
    for( int i = 0 ; i < 8 ; i++ ) {
        ans = max( ans, h[i] + h[i+1] + h[i+2] + h[i+3] );
    }
    printf("%d",ans);
    return 0;
}