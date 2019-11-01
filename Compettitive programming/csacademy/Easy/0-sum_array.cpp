#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int n, a[N], sum;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    for( int i = 1 ; i <= n ; i++ ) if( !( sum - 2*a[i] ) ) {
        printf("%d",i);
        return 0;
    }
    printf("-1");
    return 0;
}