#include <bits/stdc++.h>

using namespace std;

int k, ans[5][5], all, inv;
int main()
{
    scanf("%d",&k);
    int x = log2( k );
    x++;
    for( int i = 0 ; i <= x ; i++ ) all |= ( 1<<i );
    inv = all ^ k;
    ans[0][0] = ans[0][1] = ans[1][0] = ans[1][2] = ans[2][1] = all;
    ans[0][2] = ans[2][0] = ans[2][2] = k;
    ans[1][1] = inv;
    printf("3 3\n");
    for( int i = 0 ; i < 3 ; i++ ) {
        for( int j = 0 ; j < 3 ; j++ ) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}