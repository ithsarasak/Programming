#include<bits/stdc++.h>

using namespace std;
int n, m;
int a[100010], b[100010];
int l = 0, r = 5000000;
int check( int mi )
{
    int tem = m;
    for( int i = 0 ; i < n ; i++ ){
        int t = a[i]*mi-b[i];
        tem -= max( 0, t );
        if( tem < 0 ){
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&b[i]);
    }
    scanf("%d",&m);
    while( l < r ){
        int m = ( l + r + 1 ) / 2;
        if( check( m ) ){
            l = m;
        }
        else{
            r = m - 1;
        }
    }
    printf("%d",l);
    return 0;
}
