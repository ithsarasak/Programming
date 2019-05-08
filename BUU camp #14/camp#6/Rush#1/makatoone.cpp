#include<bits/stdc++.h>

using namespace std;
int n, q;
int sum[100100];
int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 1 ; i <= n ; i++ ){
        int nu;
        scanf("%d",&nu);
        sum[i] = sum[i-1]^nu;
    }
    for( int i = 0 ; i < q ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        printf("%d\n",sum[f-1]^sum[t]);
    }
    return 0;
}
