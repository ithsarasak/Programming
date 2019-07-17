#include<bits/stdc++.h>

using namespace std;
double a, b, c;
int main()
{
    scanf("%lf %lf %lf",&a,&b,&c);
    long long a2 = ( long long )( a * 10000000000 );
    long long b2 = ( long long )( b * 10000000000 );
    long long c2 = ( long long )( c * 10000000000 );
    if( a2 + b2 == c2 ){
        printf("Correct");
        return 0;
    }
    else{
        printf("Wrong");
    }
    return 0;
}
