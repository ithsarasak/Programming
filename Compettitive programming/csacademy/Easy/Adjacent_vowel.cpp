#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int n, ans;
char word[N];

int chk( char x ) {
    if( x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ) return 1;
    else return 0;
}
int main()
{
    scanf("%d",&n);
    scanf(" %s",&word[1]);
    int len = strlen( &word[1] );
    for( int i = 1 ; i < len ; i++ ) {
        if( chk( word[i] ) && chk( word[i+1] ) ) ans++;
    }
    printf("%d",ans);
    return 0;
}