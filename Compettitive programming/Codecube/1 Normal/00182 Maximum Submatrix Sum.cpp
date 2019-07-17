#include<bits/stdc++.h>

using namespace std;
int n, h, w, a[100010], b[100010];
long long ma1, ma2, s1, s2;
int main()
{
    scanf("%d %d %d",&n,&h,&w);
    for( int i = 0 ; i < n; i++ ){
        scanf("%d",&a[i]);
        s1 += ( long long )a[i];
        if( i >= h ){
            s1 -= ( long long )a[i - h];
        }
        if( ma1 < s1 ){
            ma1 = s1;
        }
    }
    for( int i = 0 ; i < n; i++ ){
        scanf("%d",&b[i]);
        s2 += ( long long )b[i];
        if( i >= w ){
            s2 -= ( long long )b[i - w];
        }
        if( ma2 < s2 ){
            ma2 = s2;
        }
    }
    //printf("%lld %lld\n",ma1,ma2);
    printf("%lld",ma1*w + ma2 * h );
    return 0;
}
