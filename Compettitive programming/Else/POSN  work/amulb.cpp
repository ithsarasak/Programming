#include<bits/stdc++.h>

using namespace std;

int n1, n2;
int gcd( int n1 , int n2 )
{
    if ( n2 != 0 )
       return gcd( n2 , n1 % n2 );
    else
       return n1;
}
int power( int a , int n )
{
    if( n == 0 ){
        return 1;
    }
    else{
        return a * power( a , n - 1 );
    }
}
int mul( int a , int n )
{
    if( n == 0 ){
        return 0;
    }
    else{
        return a + mul( a , n - 1 );
    }
}
int main()
{
    scanf("%d %d",&n1,&n2);
    printf("A * B = %d\n",mul(n1,n2));
    printf("A ^ B = %d\n",power(n1,n2));
    printf("gcd( A, B ) = %d\n",gcd(n1,n2));
}
