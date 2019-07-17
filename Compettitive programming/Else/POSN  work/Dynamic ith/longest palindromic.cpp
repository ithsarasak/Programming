#include<bits/stdc++.h>

using namespace std;

int ans[1001][1001], len, s;
char st[1001], se[1001];
int maxs( int a, int b )
{
    if( a > b ){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
    scanf("%s",st);
    len = strlen( st );
    for( int i = 0 ; i < len ; i++ ){
       ans[i][i] = 1;
    }
    for( int i = 1 ; i < len ; i++ ){
        for( int j = 0 ; j <= len - i ; j++ ){
            if( st[j] != st[j + i]){
                ans[j][j + i] = maxs( ans[j][j + i - 1] , ans[j + 1][j + i] );
            }
            else{
                ans[j][j + i] = ans[j + 1][j + i - 1] + 2;
            }
        }
    }
    printf("max length : %d\nPalindromic subsequence : ",ans[0][len - 1]);
    if( ans[0][len - 1] % 2 == 0 ){
        int posx = 0, posy = len - 1;
        while( ans[posx][posy] != 0 ){
            if( ans[posx][posy] != ans[posx + 1][posy] && ans[posx][posy] != ans[posx][posy - 1] ){
                se[s] = st[posx];
                posx++;
                posy--;
                s++;
            }
            else{
                if( ans[posx][posy] == ans[posx + 1][posy] ){
                    posx += 1;
                }
                else if( ans[posx][posy] == ans[posx][posy - 1] ){
                    posy -= 1;
                }
            }
        }
        for( int i = 0 ; i < s ; i++ ){
            printf("%c",se[i]);
        }
        for( int i = s - 1 ; i >= 0 ; i-- ){
            printf("%c",se[i]);
        }
    }
    else{
        int posx = 0, posy = len - 1;
        while( ans[posx][posy] != 1 ){
            if( ans[posx][posy] != ans[posx + 1][posy] && ans[posx][posy] != ans[posx][posy - 1] ){
                se[s] = st[posx];
                posx++;
                posy--;
                s++;
            }
            else{
                if( ans[posx][posy] == ans[posx + 1][posy] ){
                    posx += 1;
                }
                else if( ans[posx][posy] == ans[posx][posy - 1] ){
                    posy -= 1;
                }
            }
        }
        se[s] = st[posx];
        s++;
        for( int i = 0 ; i < s ; i++ ){
            printf("%c",se[i]);
        }
        for( int i = s - 2 ; i >= 0 ; i-- ){
            printf("%c",se[i]);
        }
    }
    return 0;
}
