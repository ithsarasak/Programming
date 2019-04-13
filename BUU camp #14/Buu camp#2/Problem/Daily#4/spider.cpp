#include<bits/stdc++.h>

using namespace std;
long long n, t, b1 = 1e9, b2 = -1e9, mx;
long long spider[1000010];
int check1( long long num )
{
    long long c = 1, temp = num;
    for( int i = 0 ; i < n ; i++ ){
        if( temp < spider[i] ){
            c++;
            temp = num;
        }
        temp -= spider[i];
    }
    //printf("C :%lld\n",c);
    if( c <= t ){
        return 1;
    }
    else return 0;
}
int check2( long long num )
{
    long long c = 1, temp = num;
    for( int i = 0 ; i < n ; i++ ){
        if( temp < spider[i] ){
            c++;
            temp = num;
        }
        temp -= spider[i];
    }
    if( c >= t ){
        return 1;
    }
    else return 0;
}
int main()
{
    scanf("%lld %lld",&n,&t);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&spider[i]);
        mx = max( mx, spider[i] );
    }
    if( t == 1 ){
        printf("-1");
        return 0;
    }
    long long l = mx, r = 1e12 + 1;
    while( l < r ){
        //4printf("%lld %lld\n",l,r);
        long long mid = ( l + r ) / 2 + 1;
        if( check2( mid ) ){
            l = mid;
        }
        else r = mid - 1;
    }
    b1 = l;
    l = mx, r = 1e12 + 1;
    while( l < r ){
        //printf("1 %lld %lld\n",l,r);
        long long mid = ( l + r ) / 2;
        if( check1( mid ) ){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%lld",b1-l+1);
    return 0;
}
