#include<bits/stdc++.h>

using namespace std;
char tim[10][20], ch[15][5][5];
int one, three, four, ma;
int main()
{
    for( int i = 0 ; i < 3 ; i++ ){
        gets( tim[i] );
    }
    strcpy( ch[1][0], "   " );
    strcpy( ch[1][1], "  |" );
    strcpy( ch[1][2], "  |" );

    strcpy( ch[2][0], " _ " );
    strcpy( ch[2][1], " _|" );
    strcpy( ch[2][2], "|_ " );

    strcpy( ch[3][0], " _ " );
    strcpy( ch[3][1], " _|" );
    strcpy( ch[3][2], " _|" );

    strcpy( ch[4][0], "   " );
    strcpy( ch[4][1], "|_|" );
    strcpy( ch[4][2], "  |" );

    strcpy( ch[5][0], " _ " );
    strcpy( ch[5][1], "|_ " );
    strcpy( ch[5][2], " _|" );

    strcpy( ch[6][0], " _ " );
    strcpy( ch[6][1], "|_ " );
    strcpy( ch[6][2], "|_|" );

    strcpy( ch[7][0], " _ " );
    strcpy( ch[7][1], "  |" );
    strcpy( ch[7][2], "  |" );

    strcpy( ch[8][0], " _ " );
    strcpy( ch[8][1], "|_|" );
    strcpy( ch[8][2], "|_|" );

    strcpy( ch[9][0], " _ " );
    strcpy( ch[9][1], "|_|" );
    strcpy( ch[9][2], " _|" );

    strcpy( ch[0][0], " _ " );
    strcpy( ch[0][1], "| |" );
    strcpy( ch[0][2], "|_|" );
    int c = 0, cou = 0;
    for( int k = 0 ; k <= 2 ; k++ ){
        ma = 9;
        c = 0;
        if( k == 2 ){
            ma = 3;
        }
        for( int i = 0 ; i < 3 ; i++ ){
            for( int j = 0 ; j < 3 ; j++ ){
                if( tim[i][j] != ' ' && tim[i][j] != ch[k][i][j] ){
                    c = 1;
                    break;
                }
            }
            if( c ) break;
        }
        if( c ){
            cou += ma + 1;
            continue;
        }
        for( int l = 0 ; l <= ma ; l++ ){
            c = 0;
            for( int i = 0 ; i < 3 ; i++ ){
                for( int j = 0 ; j < 3 ; j++ ){
                    //printf("%c",ch[l][i][j] );
                    if( tim[i][j+3] != ' ' && tim[i][j+3] != ch[l][i][j] ){
                        //printf("\n%d %d\n",l,k);
                        //printf("%c %c\n",tim[i][j+3],ch[l][i][j]);
                        cou++;
                        c = 1;
                        break;
                    }
                }
                if( c ) break;
                //printf("\n");
            }
            //printf("\n");
        }
        //printf("cou : %d\n",cou);
    }
    one = 24 - cou;
    cou = 0;
    for( int k = 0 ; k <= 5 ; k++ ){
        c = 0;
        for( int i = 0 ; i < 3 ; i++ ){
            for( int j = 0 ; j < 3 ; j++ ){
                if( tim[i][j+7] != ' ' && tim[i][j+7] != ch[k][i][j] ){
                    cou++;
                    c = 1;
                    break;
                }
            }
            if( c ){
                break;
            }
        }
    }
    three = 6 - cou;
    cou = 0;
    for( int k = 0 ; k <= 9 ; k++ ){
        c = 0;
        for( int i = 0 ; i < 3 ; i++ ){
            for( int j = 0 ; j < 3 ; j++ ){
                //printf("%c",ch[k][i][j]);
                if( tim[i][j+10] != ' ' && tim[i][j+10] != ch[k][i][j] ){
                    //printf("\n%d\n",k);
                    cou++;
                    c = 1;
                    break;
                }
            }
            if( c ) break;
            //printf("\n");
        }
    }
    four = 10 - cou;
    //printf("%d %d %d\n",one,three,four);
    printf("%d",one*three*four);
    return 0;
}
/*
 _      _  _
| | _ . _||_
|_| _|. _||
*/
