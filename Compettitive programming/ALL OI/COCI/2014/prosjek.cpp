#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n, a[N], sum[N];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    for( int i = 1 ; i <= n ; i++ ) {
        a[i] = a[i] * i - sum[i-1];
        sum[i] = sum[i-1] + a[i];
    }
    for( int i = 1 ; i <= n ; i++ ) printf("%d ",a[i]);
    return 0;
}