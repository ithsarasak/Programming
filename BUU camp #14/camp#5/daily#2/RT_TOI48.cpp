#include<bits/stdc++.h>
using namespace std;

int K[5010][15010], val[5010], wt[5010], n, W;
int main()
{
    scanf("%d %d",&n,&W);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&val[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&wt[i]);
        wt[i]++;
        wt[i] *= 8;
    }
    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= W; w++){
            if( i == 0 || w == 0 ) K[i][w] = 0;
            else if (wt[i-1] <= w) K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else K[i][w] = K[i-1][w];
        }
    }
    printf("%d",K[n][W]);
    return 0;
}
