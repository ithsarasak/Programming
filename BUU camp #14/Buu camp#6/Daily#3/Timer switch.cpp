#include<bits/stdc++.h>

using namespace std;
int n, mi = 1e9;
char tim[5000100];
int check( int num )
{
    for( int i = num ; i < n ; i++ ){
        if( tim[i] != tim[i%num] ){
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",tim);
    int sq = ( int )( sqrt( n ) );
    for( int i = 1 ; i <= sq ; i++ ){
        if( n % i == 0 ){
            if( check( i ) ){
                printf("%d",i);
                return 0;
            }
            else if( check( n / i ) ){
                mi = min( mi, n / i );
            }
        }
    }
    printf("%d",mi);
    return 0;
}
