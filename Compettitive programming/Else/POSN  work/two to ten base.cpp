#include<bits/stdc++.h>
char number[10000];
int i , len;
int pow( int k )
{
    int n = 1 ;
    for( int j = 0 ; j < k ; j++ ){
        n *= 2;
    }
    return n;
}
int translate( int k )
{
    int ans = 0;
    for( i = 0 ; i <= k ; i++ ){
        ans += ( number[i] - '0' ) * pow( k - i );
    }
    return ans;
}
int main()
{
     scanf("%s",number);
     len = strlen( number );
     len--;
     printf("%d",translate( len ));
     return 0;
}
