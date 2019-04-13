#include<bits/stdc++.h>

using namespace std;

long long number;
int sum;
int sumnum( int n )
{
    if( n == 0 ){
        return 0;
    }
    else{
        sum += n % 10;
        sumnum( n / 10 );
    }
}
int main()
{
    scanf("%lld",&number);
    sumnum( number );
    printf("%d",sum);
    return 0;
}
