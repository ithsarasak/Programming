#include<bits/stdc++.h>

using namespace std;
int q, n, k;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%d %d",&n,&k);
        n -= ( k + 1 );
        //cout << n ;
        if( n % 2 ){
            printf("A\n");
        }
        else{
            printf("B\n");
        }
    }
    return 0;
}
