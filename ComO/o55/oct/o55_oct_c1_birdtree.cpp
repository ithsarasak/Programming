#include<bits/stdc++.h>

using namespace std;
int t;
int main()
{
    scanf("%d",&t);
    while( t-- ){
        int a, b;
        scanf("%d/%d",&a,&b);
        while( a != 1 || b != 1 ){
            if( a < b ){
                swap( a, b );
                a -= b;
                printf("L");
            }
            else{
                a -= b;
                swap( a, b );
                printf("R");
            }
        }
        printf("\n");
    }
    return 0;
}
