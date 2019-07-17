#include<bits/stdc++.h>

using namespace std;
int sum[100100];
int n, k;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        int nu;
        scanf("%d",&nu);
        sum[i] = nu + sum[i-1];
    }
    while( k-- ){
        int mo;
        scanf("%d",&mo);
        if( mo < sum[1] )printf("0\n");
        else if( mo >= sum[n] )printf("%d\n",n);
        else{
            int idx = upper_bound( sum + 1, sum + 1 + n, mo ) - sum;
            printf("%d\n",idx-1);
        }
    }
    return 0;
}
