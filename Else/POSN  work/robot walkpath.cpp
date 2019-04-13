#include<bits/stdc++.h>

using namespace std;

int l, h, c;
int walk( int a ,int b )
{
    if( a > l || b > h ){
        return 0;
    }
    if( a == l && b == h ){
        c++;
        return 0;
    }
    walk( a , b + 1 );
    walk( a + 1 , b );
}
int main()
{
    scanf("%d %d",&l,&h);
    walk( 0 , 0 );
    printf("%d",c);
    return 0;
}
