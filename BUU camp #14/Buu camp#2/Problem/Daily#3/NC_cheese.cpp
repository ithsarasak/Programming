#include<bits/stdc++.h>

using namespace std;
int a, b, h;
int eu( int a, int b )
{
    if( a % b == 0 ){
        return b;
    }
    else return eu( b, a % b );
}
int main()
{
    scanf("%d %d",&a,&b);
    printf("%d", b - eu( a % b , b  ));
    return 0;
}
