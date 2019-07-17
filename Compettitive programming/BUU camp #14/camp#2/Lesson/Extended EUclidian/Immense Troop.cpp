#include<bits/stdc++.h>

using namespace std;
void eucledian( int a, int b, int *x, int *y )
{
    if( b == 0 ){
        *x = 1, *y = 0;
        return ;
    }
    int u, v;
    eucledian( b, a % b, &u, &v );
    *x = v;
    *y = u - v*( a / b );
    return ;
}
int inverse( int a, int b )
{
    int x, y;
    eucledian( a, b, &x, &y );
    return x%b;
}
int main()
{
    int q, x1, y1, x2, y2, n, r, i, inv;
    long long ans;
    scanf("%d",&q);
    while( q-- ){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if( x1 > x2 || y1 > y2 ){
            printf("0\n");
            continue ;
        }
        n = x2 - x1 + y2 - y1;
        r = y2 - y1;
        if( n - r > r ){
            r = n - r;
        }
        ans = 1;
        for( int i = r + 1 ; i <= n ; i++ ){
            ans *= i;
            ans %= 500000003;
        }
        for( int i = 2 ; i <= n - r ; i++ ){
            inv = inverse( i, 500000003 );
            if( inv < 0 ) inv += 500000003;
            ans *= inv;
            ans %= 500000003;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
