#include<bits/stdc++.h>
using namespace std;
int q, mic[1010][1010];
int main()
{
    mic[0][0] = 1;
    for( int i = 1 ; i <= 1000 ; i++ ){
        for( int j = 1 ; j <= i ; j++ ){
            mic[i][j] = ( j * mic[i - 1][j] ) + mic[i - 1][j - 1];
            mic[i][j] %= 9871;
        }
    }
    scanf("%d",&q);
    while( q-- ){
        int n, k;
        scanf("%d %d",&n,&k);
        printf("%d\n",mic[n][k]);
    }
    return 0;
}

