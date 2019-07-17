#include<bits/stdc++.h>
int n, ans[100000], s, i;
int translate( int k )
{
    while( k > 0 ){
        ans[s] = k % 2;
        k /= 2;
        s++;
     }
}
int main()
{
     scanf("%d",&n);
     if( n == 0 ){
        printf("%d",n);
        return 0;
     }
     translate( n );
     for( i = s - 1 ; i >= 0 ; i-- ){
        printf("%d",ans[i]);
     }
     return 0;
}
