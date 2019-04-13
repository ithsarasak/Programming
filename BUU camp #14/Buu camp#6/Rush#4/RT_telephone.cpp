#include<bits/stdc++.h>

using namespace std;
int n, ans;
unordered_map<char,int> ma;
char s[1100][1100];
char check[1100];
int main()
{
    ma['a'] = 2;
    ma['b'] = 2;
    ma['c'] = 2;
    ma['d'] = 3;
    ma['e'] = 3;
    ma['f'] = 3;
    ma['g'] = 4;
    ma['h'] = 4;
    ma['i'] = 4;
    ma['j'] = 5;
    ma['k'] = 5;
    ma['l'] = 5;
    ma['m'] = 6;
    ma['n'] = 6;
    ma['o'] = 6;
    ma['p'] = 7;
    ma['q'] = 7;
    ma['r'] = 7;
    ma['s'] = 7;
    ma['t'] = 8;
    ma['u'] = 8;
    ma['v'] = 8;
    ma['w'] = 9;
    ma['x'] = 9;
    ma['y'] = 9;
    ma['z'] = 9;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%s",s[i]);
    }
    scanf("%s",check);
    for( int i = 0 ; i < n ; i++ ){
        int len = strlen( s[i] );
        int len2 = strlen( check );
        if( len != len2 )continue;
        int ch = 1;
        for( int j = 0 ; j < len ; j++ ){
            if( ma[s[i][j]] != check[j] - '0' ){
                ch = 0;
                break;
            }
        }
        if( ch )ans++;
    }
    printf("%d",ans);
    return 0;
}
