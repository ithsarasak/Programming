#include<bits/stdc++.h>

using namespace std;

int n, i, x[500010], y[500010], s = 1;
long long sum1, sum2;
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d %d",&x[i],&y[i]);
    }
    sort( x , x + n );
    sort( y , y + n );
    for( i = n - 1 ; i >= 0 ; i-- ){
        sum1 += ( long long )x[i]*( n - s );
        sum2 += ( long long )y[i]*( n - s );
        s += 2;
    }
    printf("%lld",sum1 + sum2);
    return 0;
}
