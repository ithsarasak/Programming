#include<bits/stdc++.h>

using namespace std;
int a, b, mx = -1e9;
int candy[300010];
int main()
{
    scanf("%d %d",&a,&b);
    for( int i = 0 ; i < b ; i++ ){
        scanf("%d",&candy[i]);
        if( mx < candy[i] ) mx = candy[i];
    }
    int l = 0, r = mx;
    while( l < r ){
        int mid = ( l + r ) / 2;
        int coun = 0;
        for( int i = 0 ; i < b ; i++ ){
            coun += ( int )ceil( ( double )candy[i] / mid );
        }
        if( coun > a ){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    printf("%d",l);
    return 0;
}
