#include <bits/stdc++.h>

using namespace std;

int n, k, q;
int main()
{
    scanf("%d",&q);
    while( q-- ) {
        scanf("%d %d",&n,&k);
        int t = n / k;
        if( n % k ) t++;
        if( max( t, k ) == k ) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}