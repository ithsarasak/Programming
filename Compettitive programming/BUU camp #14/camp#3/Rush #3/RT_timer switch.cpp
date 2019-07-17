#include<bits/stdc++.h>

using namespace std;
int n;
char s[5000010];
int mi = 1e7, si;
int real, now, lps[5000010], sq;
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
    scanf("%d",&n);
    scanf("%s",s);
    sq = sqrt( n );
    for( int i = 1 ; i <= sq ; i++ ){
        if( n % i == 0 ){
            if( think( i ) ){
                printf("%d",i);
                return 0;
            }
            if( think( n/i ) ){
                mi = min( mi, n/i );
            }
        }
    }
    printf("%d",mi);
    return 0;
}
