#include<bits/stdc++.h>

using namespace std;
int n, mica[1000010], micb[1000010];
char s[1000010];
int main()
{
    scanf("%d",&n);
    scanf("%s",&s[1]);
    for( int i = 1 ; i <= n ; i++ ){
        if( s[i] == 'A' ){
            mica[i] = mica[i - 1];
            micb[i] = min( mica[i - 1] + 1, micb[i - 1] + 1 );
        }
        else{
            micb[i] = micb[i - 1];
            mica[i] = min( mica[i - 1] + 1, micb[i - 1] + 1 );
        }
    }
    printf("%d",mica[n]);
    return 0;
}
