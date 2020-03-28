#include <bits/stdc++.h>

using namespace std;

int ans, n;
char s[20];

int cal( char a ) {
    if( a == 'A' ) return 4;
    else if( a == 'K' ) return 3;
    else if( a == 'Q' ) return 2;
    else if( a == 'J' ) return 1;
    return 0;
}

int main() 
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%s",s);
        for( int j = 0 ; j < 13 ; j++ ) ans += cal( s[j] );
    }
    printf("%d",ans);
}