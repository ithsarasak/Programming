#include<bits/stdc++.h>

using namespace std;
int n, m, ans;
char mp[1010][1010];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 2 ; i <= n + 1 ; i++ ){
        scanf("%s",mp[i] + 2);
    }
    for( int i = 2 ; i <= n + 1 ; i++ ){
        for( int j = 2 ; j <= m + 1 ; j++ ){
            if( mp[i][j] == 'x' ){
                if( mp[i - 1][j - 1] == 'A' ) mp[i - 1][j - 1] = '.';
                if( mp[i - 2][j - 2] == 'A' ) mp[i - 2][j - 2] = '.';
                if( mp[i - 1][j + 1] == 'A' ) mp[i - 1][j + 1] = '.';
                if( mp[i - 2][j + 2] == 'A' ) mp[i - 2][j + 2] = '.';
                if( mp[i + 1][j - 1] == 'A' ) mp[i + 1][j - 1] = '.';
                if( mp[i + 2][j - 2] == 'A' ) mp[i + 2][j - 2] = '.';
                if( mp[i + 1][j + 1] == 'A' ) mp[i + 1][j + 1] = '.';
                if( mp[i + 2][j + 2] == 'A' ) mp[i + 2][j + 2] = '.';
                mp[i][j] = '.';
            }
            else if( mp[i][j] == '+' ){
                if( mp[i][j - 1] == 'A' ) mp[i][j - 1] = '.';
                if( mp[i][j + 1] == 'A' ) mp[i][j + 1] = '.';
                if( mp[i - 1][j] == 'A' ) mp[i - 1][j] = '.';
                if( mp[i + 1][j] == 'A' ) mp[i + 1][j] = '.';
                mp[i][j] = '.';
            }
        }
    }
    for( int i = 2 ; i <= n + 1 ; i++ ){
        for( int j = 2 ; j <= m + 1 ; j++ ){
            if( mp[i][j] == 'A' ){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    for( int i = 2 ; i <= n + 1 ; i++ ){
        for( int j = 2 ; j <= m + 1 ; j++ ){
            printf("%c",mp[i][j]);
        }
        printf("\n");
    }
}
/*
..A..
AA+AA
.AAA.
.AxA.
.AAA.
AA+AA
..A..
*/
