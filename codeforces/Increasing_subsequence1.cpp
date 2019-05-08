#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, num[N], cnt, mx;
char ans[N];

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&num[i]);
    int l = 1, r = n;
    while( l <= r && ( num[l] > mx || num[r] > mx ) ) {
        if( ( num[l] <= num[r] && num[l] > mx ) || num[r] < mx ){
            mx = max( mx, num[l] );
            ans[cnt++] = 'L', l++;
        }
        else {
            mx = max( mx, num[r] );
            ans[cnt++] = 'R', r--;
        }
    }
    int len = strlen( ans );
    printf("%d\n%s",len,ans);
    return 0;
}