#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int t, k, n;
int mark[35], ans;
char s[N];
int f( char c ) { return c - 'a'; }
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        ans = 0;
        int all = 0;
        scanf("%d %d",&n,&k);
        scanf("%s",&s[1]);
        for( int i = 1 ; i <= k / 2 ; i++ ) {
            memset( mark, 0, sizeof mark ), all = 0;
            //printf("%d\n",i);
            for( int j = i, temp = k + 1 - i ; j <= n && temp <= n ; j += k, temp += k ){
                //printf("%c %c\n",s[j],s[temp]);
                all += 2, mark[f(s[j])]++, mark[f(s[temp])]++;
            }
            sort( mark, mark+30, greater<int>() );
            ans += all - mark[0];
        } 
        if( k % 2 ) {
            //printf("Helo");
            memset( mark, 0, sizeof mark ), all = 0;
            int x = ( k + 1 ) >> 1;
            for( int j = x ; j <= n ; j += k ) all++, mark[f(s[j])]++;
            sort( mark, mark+30, greater<int>() );
            ans += all - mark[0];
        }
        printf("%d\n",ans);
    }
    return 0;
}