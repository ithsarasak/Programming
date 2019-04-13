#include<bits/stdc++.h>
char code[30][16];
int i, j, n, stage = 1, ans[30][8];
int s1( char a, char b ){
    if( a == '0' && b == '0' ){
        stage = 1;
        return 0;
    }
    else if( a == '1' && b == '1' ){
        stage = 2;
        return 1;
    }
}
int s2( char a, char b ){
    if( a == '0' && b == '1' ){
        stage = 4;
        return 1;
    }
    else if( a == '1' && b == '0' ){
        stage = 3;
        return 0;
    }
}
int s3( char a, char b ){
    if( a == '0' && b == '0' ){
        stage = 2;
        return 1;
    }
    else if( a == '1' && b == '1' ){
        stage = 1;
        return 0;
    }
}
int s4( char a, char b ){
    if( a == '1' && b == '0' ){
        stage = 4;
        return 1;
    }
    else if( a == '0' && b == '1' ){
        stage = 3;
        return 0;
    }
}
int pow( int k ){
    int pro = 1;
    for( int o = 0 ; o < k; o++ ){
        pro *= 2;
    }
    return pro;
}
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%s",code[i]);
    }
    if( strlen( code[n - 1] ) != 16 ){
        n--;
    }
    for( i = 0 ; i < n ; i++ ){
        for( j = 0 ; j < 16 ; j += 2 ){
            if( stage == 1 ){
                ans[i][j / 2] = s1( code[i][j] , code[i][j + 1] );
            }
            else if( stage == 2 ){
                ans[i][j / 2] = s2( code[i][j] , code[i][j + 1] );
            }
            else if( stage == 3 ){
                ans[i][j / 2] = s3( code[i][j] , code[i][j + 1] );
            }
            else if( stage == 4 ){
                ans[i][j / 2] = s4( code[i][j] , code[i][j + 1] );
            }
        }
    }
    int temp = 0;
    for( i = 0 ; i < n ; i++ ){
        temp = 0;
        for( j = 0 ; j < 8 ; j++ ){
            temp += ( pow( 7 - j ) * ans[i][j] );
        }
        printf("%c",temp);
    }
    return 0;
}
