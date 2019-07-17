#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
char s[N];
int ok[2020][2020], cnt[30];
int main()
{
    scanf("%s",&s[1]);
    int len = strlen( &s[1] );
    if( len % 2 ) return !printf("-1");
    for( int i = 1 ; i <= len ; i++ ) {
        for( int j = 1 ; j <= len - i + 1 ; j++ ) {
            if( i % 2 ) ok[j][j] = 0;
            else {
                if( i == 2 && s[j] == s[j+1] ) ok[j][j+1] = 1;
                else if( i != 2 ) ok[j][j+i-1] = ok[j+1][j+i-2];
            }
        }
    }
    for( int i = 1 ; i <= len ; i++ ) pos[s[i]-'a'].emplace_back( i );
    for( int i = 0 ; i <= 25 ; i++ ) if( pos[i].size() % 2 ) return !printf("-1");
    for( int i = 1 ; i <= len ; i++ ) {
        int now = s[i] - 'a';
        int idx = lower_bound( pos[now].begin(), pos[now].end(), i ) - pos[now].begin();
        
    }
    return 0;
}