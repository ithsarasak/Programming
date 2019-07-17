#include<bits/stdc++.h>

using namespace std;
struct aa{
    int a, b;
}p[500100];
int n;
long long sum[500100];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&p[i].a);
    }
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&p[i].b);
        p[i+n] = p[i];
        p[i+2*n] = p[i];
    }
    for( int i = 1 ; i <= 3*n ; i++ ){
        sum[i] = sum[i-1] + p[i].b;
    }
    for( int i = n + 1 ; i <= 2*n ; i++ ){
        int l = 0, r = ( n - 1 ) / 2;
        while( l < r ){
            int mid = ( l + r + 1 ) / 2;
            if( p[i].a >= sum[i+mid] - sum[i-mid-1] - p[i].b ){
                l = mid;
            }
            else r = mid - 1;
        }
        printf("%d ",2*l);
    }
    return 0;
}
