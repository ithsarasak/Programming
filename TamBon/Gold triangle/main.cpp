#include<bits/stdc++.h>
long long x[100010], y[100010], p, i;
long long counts;
struct point{
    int a, b;
}all[100010];
int main()
{
    scanf("%d",&p);
    for( i = 0 ; i < p ; i++ ){
        scanf("%d %d",&all[i].a,&all[i].b);
        x[all[i].a]++;
        y[all[i].b]++;
    }
    for( i = 0 ; i < p ; i++ ){
        counts += ( x[all[i].a] - 1 ) * ( y[all[i].b] - 1 );
    }
    printf("%lld",counts);
    return 0;
}
