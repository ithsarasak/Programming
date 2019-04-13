#include<bits/stdc++.h>

using namespace std;
int n1, n2;
int checke( int a , int b )
{
    if( a == 0 && b == 0 ){
        return 1;
    }
    else if( a == 1 && b == 0 ){
        return 0;
    }
    else if( a == 0 && b == 1 ){
        return 0;
    }
    else{
        checke( a - 1 , b - 1 );
    }
}
int main()
{
    scanf("%d %d",&n1,&n2);
    if( checke( n1, n2 ) ){
        printf("Equal");
    }
    else{
        printf("Not equal");
    }
    return 0;
}
