#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 +10;
int t, ar[N];    
char s[N];
int main()
{
    scanf("%d",&t);
    for( int rou = 1 ; rou <= t ; rou++ ) {    
        scanf(" %s",&s[1]);
        int len = strlen( &s[1] ), st = 0;
        for( int i = 1 ; i <= len ; i++ ) ar[i] = s[i] - '0';
        printf("Case #%d: ",rou);
        int now = 0;
        for( int i = 1 ; i <= len ; i++ ) {
            int dif = ar[i] - now;
            if( dif >= 0 ) for( int j = 1 ; j <= dif ; j++ ) printf("(");
            else if( dif < 0 ) {
                dif *= -1;
                for( int j = 1 ; j <= dif ; j++ ) printf(")");
            }
            now = ar[i];
            printf("%d",ar[i]);
        }
        for( int i = 0 ; i < now ; i++ ) printf(")");
        printf("\n");
    }
    return 0;
}