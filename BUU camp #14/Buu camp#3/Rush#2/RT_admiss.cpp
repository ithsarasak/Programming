#include<bits/stdc++.h>

using namespace std;
char na[110];
int sc[3];
int n;
int main()
{
    scanf("%d",&n);
    while( n-- ){
        scanf("%s",na);
        for( int i = 0 ; i < 3 ; i++ )scanf("%d",&sc[i]);
        int l = strlen( na );
        if( l % 2 )printf("FAIL\n");
        else printf("PASS\n");
    }
}
