#include<bits/stdc++.h>

using namespace std;
int n;
char s[5000010];
int si;
int sq, ans;
int think( int num )
{
    for( int i = num ; i < n ; i++ ){
        if( s[i] != s[i%num] ){
            return 0;
        }
    }
    return 1;
}
int main()
{
    for( int z = 0 ; z < 5 ; z++ ){
        ans = 0;
        scanf("%s",s);
        n = strlen( s );
        sq = sqrt( n );
        for( int i = 1 ; i <= sq ; i++ ){
            if( n % i == 0 ){
                if( i == n / i )ans += think( i );
                else ans += think( i ) + think( n / i );
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
