#include <bits/stdc++.h>

using namespace std;

int t, n;
char baby[200100];
int main()
{
    scanf("%d",&t);
    for( int z = 1 ; z <= t ; z++ ) {
        scanf("%d %s",&n,baby);
        int l = strlen( baby );
        printf("Case #%d: ",z);
        for( int i = 0 ; i < l ; i++ ) {
            if( baby[i] == 'E' ) printf("S");
            else printf("E");
        }
        printf("\n");
    }
    return 0;
}