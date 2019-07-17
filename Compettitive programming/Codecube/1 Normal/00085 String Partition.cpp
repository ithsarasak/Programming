#include<bits/stdc++.h>

using namespace std;
int n, mi = 1e9;
char w[100100];
int sq, cnt[30];
void check( int num )
{
    int ma = -1, co = 0;
    for( int j = 0 ; j < num ; j++ ){
        memset( cnt, 0, sizeof cnt );
        ma = -1;
        for( int i = j ; i < n ; i += num ){
            cnt[w[i]-'a']++;
            ma = max( ma, cnt[w[i]-'a'] );
        }
        co += ( n / num ) - ma;
    }
    mi = min( mi, co );
}
int main()
{
    scanf("%s",&w);
    n = strlen( w );
    sq = sqrt( n );
    for( int i = 1 ; i <= sq ; i++ ){
        if( n % i == 0 ){
            check( i );
            if( i != 1 )check( n / i );
        }
    }
    printf("%d",mi);
    return 0;
}
