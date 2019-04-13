#include<bits/stdc++.h>

using namespace std;
long long n, s;
int check( long long num )
{
    long long num2 = num;
    long long sumnum = 0;
    while( num2 > 0 ){
        sumnum += num2 % 10;
        num2 /= 10;
    }
    if( num - sumnum >= s ) return 1;
    else return 0;
}
int main()
{
    scanf("%lld %lld",&n,&s);
    if( s == 0 ){
        printf("%lld\n%lld",n+1,n);
        return 0;
    }
    long long l = 0, r = n;
    if( !check( n ) ){
        printf("0\n-1");
        return 0;
    }
    while( l < r ){
        long long mid = ( l + r ) / 2;
        if( check( mid ) )r = mid;
        else l = mid + 1;
    }
    printf("%lld\n%lld",n-l+1,n);
    return 0;
}
