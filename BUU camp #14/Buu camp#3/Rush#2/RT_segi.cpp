#include<bits/stdc++.h>

using namespace std;
int ti = 20;
int n;
int cal[5][5];
char s[300];
int mem[300][300][5], mark[300][300];
void play( int l, int r )
{
    if( l == r ){
        mem[l][r][s[l]-'0'] = 1;
        return ;
    }
    if( mark[l][r] != 0 )return ;
    mark[l][r] = 1;
    for( int i = l ; i < r ; i++ ){
        play( l, i ), play( i+1, r );
        for( int j = 0 ; j < 3 ; j++ ){
            for( int k = 0 ; k < 3 ; k++ ){
                if( mem[l][i][j] == 1 && mem[i+1][r][k] == 1 ){
                    mem[l][r][cal[j][k]] = 1;
                }
            }
        }
    }
    return ;
}
int main()
{
    cal[0][0] = 2;
    cal[0][1] = 1;
    cal[0][2] = 0;
    cal[1][0] = 2;
    cal[1][1] = 1;
    cal[1][2] = 1;
    cal[2][0] = 1;
    cal[2][1] = 2;
    cal[2][2] = 1;
    while( ti-- ){
        memset( mark, 0, sizeof mark );
        memset( mem, 0, sizeof mem );
        scanf("%d %s",&n,&s[1]);
        play( 1, n );
        if( mem[1][n][0] == 1 )printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
