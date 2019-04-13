#include<bits/stdc++.h>
int a, b, l, r = 2000000000, i, mid;
int tree[1000010];
int main()
{
    scanf("%d %d",&a,&b);
    for( i = 0 ; i < a ; i++ ){
        scanf("%d",&tree[i]);
    }
    while( l < r ){
        mid = ( l + r + 1 )/ 2;
        long long sum  = 0;
        //printf("%d %d %d\n",l,r,mid);
        for( i = 0 ; i < a ; i++ ){
            long long temp = tree[i] - mid;
            if( temp >= 0 ){
                sum += temp;
            }
        }
        if( sum >= b ){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%d",r);
    return 0;
}
