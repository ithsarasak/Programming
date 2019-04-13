#include<bits/stdc++.h>

using namespace std;
int n, mi = 1e9;
long long brick1[300100], brick2[300100];
long long check( long long me )
{
    long long po = 0;
    for( int i = 0 ; i < n ; i++ ){
        po += abs( me + abs( i - n / 2 ) - brick1[i] );
    }
    for( int i = 0 ; i < n ; i++ ){
        po += abs( me + abs( i - n / 2 ) - brick2[i] );
    }
    return po;
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&brick1[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&brick2[i]);
    }
    long long l = 0, r = 1e12;
    while( l < r ){
        int mid = ( l + r + 1 ) / 2;
        if( check( mid ) > check( mid-1 ) ){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    printf("%lld",check( l ) );
    return 0;
}
