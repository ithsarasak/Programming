#include<bits/stdc++.h>
int n, l = 0, r = 2000000000, i, mid;
int main()
{
    scanf("%d",&n);
    while( l < r ){
        mid = ( l + r ) / 2;
        int temp = mid;
        int sum = 0;
        sum +=  15 * ( temp / 3000 );
        temp -= ( temp / 3000 ) * 3000;
        sum += 5 * ( temp / 1500 );
        temp -= ( temp / 1500 ) * 1500;
        sum += 2 * ( temp / 800 );
        temp -= ( temp / 800 ) * 800;
        sum += temp / 500;
        temp -= ( temp / 500 ) * 500;
        //printf("%d %d %d %d\n",l,r,mid,sum);
        if( sum >= n ){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d",r);
    return 0;
}
