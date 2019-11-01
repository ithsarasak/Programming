#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
int n, num[N], ans, k;
int main() 
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&num[i]);
    for( int i = 1 ; i <= n ; i++ ) {
        int plus = 1;
        for( int j = 1 ; j <= n ; j++ ) {
            if( i == j ) continue ;
            if( abs( num[i] - num[j] ) <= k ) plus = 0;
        }
        ans += plus;
    }
    printf("%d",ans);
}