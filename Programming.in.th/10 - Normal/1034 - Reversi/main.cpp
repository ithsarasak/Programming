#include<stdio.h>
char board[15][15], pos2, temp = 'X';
int i, j, n, pos1, check2;
int check( int x, int y , int nextx , int nexty, char f ){
    if( x < 1 || y < 1 || x > 8|| y > 8 ){
        return 0;
    }
    if( board[x][y] == '.')
        return 0;
    if( board[x][y] == f ){
        return 1;
    }
    return check( x + nextx , y + nexty , nextx , nexty , f );
}
int fills( int x, int y , int nextx , int nexty, char f ){
    if( board[x][y] == f ){
        return 0;
    }
    board[x][y] = f;
    fills( x + nextx , y + nexty , nextx , nexty , f );
}
int main()
{
    for( i = 1 ; i <= 8 ; i++ ){
        for( j = 1 ; j <= 8 ; j++ ){
            board[i][j] = '.';
        }
    }
    board[4][4] = 'O';
    board[4][5] = 'X';
    board[5][4] = 'X';
    board[5][5] = 'O';
    scanf("%d",&n);
    for( i = 0  ; i < n ; i++ ){
        scanf(" %c %d",&pos2,&pos1);
        if( temp == 'X' ){
            if( check( pos1 + 1, pos2 - 'a' + 2,1,1,'X' ) == 1 ||
               check( pos1 + 1,pos2 - 'a' + 1,1,0,'X' ) == 1 ||
               check( pos1 + 1, pos2 - 'a',1,-1,'X' ) == 1 ||
               check( pos1 , pos2 - 'a' + 2,0,1,'X' ) == 1 ||
               check( pos1 , pos2 - 'a',0,-1,'X' ) == 1 ||
               check( pos1 - 1, pos2 - 'a' + 2,-1,1,'X')==1 ||
               check( pos1 - 1, pos2 - 'a' + 1,-1,0,'X' ) == 1 ||
               check( pos1 - 1, pos2 - 'a',-1,-1,'X' ) == 1 )
            {
                    if( check( pos1 + 1, pos2 - 'a' + 2,1,1,'X' ) == 1)
                        fills( pos1 + 1, pos2 - 'a' + 2,1,1,'X' );
                    if( check( pos1 + 1,pos2 - 'a' + 1,1,0,'X' ) == 1 )
                        fills( pos1 + 1,pos2 - 'a' + 1,1,0,'X' );
                    if( check( pos1 + 1, pos2 - 'a',1,-1,'X' ) == 1 )
                        fills( pos1 + 1, pos2 - 'a',1,-1,'X' );
                    if( check( pos1 , pos2 - 'a' + 2,0,1,'X' ) == 1 )
                        fills( pos1 , pos2 - 'a' + 2,0,1,'X' );
                    if( check( pos1 , pos2 - 'a',0,-1,'X' ) == 1 )
                        fills( pos1 , pos2 - 'a',0,-1,'X' );
                    if( check( pos1 - 1, pos2 - 'a' + 2,-1,1,'X' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 2,-1,1,'X');
                    if( check( pos1 - 1, pos2 - 'a' + 1,-1,0,'X' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 1,-1,0,'X' );
                    if( check( pos1 - 1, pos2 - 'a',-1,-1,'X' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a',-1,-1,'X' );
                    board[pos1][pos2 - 'a'+1]='X';
                    temp = 'O';
            }
            else{
                    if( check( pos1 + 1, pos2 - 'a' + 2,1,1,'O' ) == 1)
                        fills( pos1 + 1, pos2 - 'a' + 2,1,1,'O' );
                    if( check( pos1 + 1,pos2 - 'a' + 1,1,0,'O' ) == 1 )
                        fills( pos1 + 1,pos2 - 'a' + 1,1,0,'O' );
                    if( check( pos1 + 1, pos2 - 'a',1,-1,'O' ) == 1 )
                        fills( pos1 + 1, pos2 - 'a',1,-1,'O' );
                    if( check( pos1 , pos2 - 'a' + 2,0,1,'O' ) == 1 )
                        fills( pos1 , pos2 - 'a' + 2,0,1,'O' );
                    if( check( pos1 , pos2 - 'a',0,-1,'O' ) == 1 )
                        fills( pos1 , pos2 - 'a',0,-1,'O' );
                    if( check( pos1 - 1, pos2 - 'a' + 2,-1,1,'O' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 2,-1,1,'O');
                    if( check( pos1 - 1, pos2 - 'a' + 1,-1,0,'O' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 1,-1,0,'O' );
                    if( check( pos1 - 1, pos2 - 'a',-1,-1,'O' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a',-1,-1,'O' );
                    board[pos1][pos2 - 'a'+1]='O';
            }

        }
        else{
            if( check( pos1 + 1, pos2 - 'a' + 2,1,1,'O' ) == 1 ||
               check( pos1 + 1,pos2 - 'a' + 1,1,0,'O' ) == 1 ||
               check( pos1 + 1, pos2 - 'a',1,-1,'O' ) == 1 ||
               check( pos1 , pos2 - 'a' + 2,0,1,'O' ) == 1 ||
               check( pos1 , pos2 - 'a',0,-1,'O' ) == 1 ||
               check( pos1 - 1, pos2 - 'a' + 2,-1,1,'O')==1 ||
               check( pos1 - 1, pos2 - 'a' + 1,-1,0,'O' ) == 1 ||
               check( pos1 - 1, pos2 - 'a',-1,-1,'O' ) == 1 )
            {
                    if( check( pos1 + 1, pos2 - 'a' + 2,1,1,'O' ) == 1)
                        fills( pos1 + 1, pos2 - 'a' + 2,1,1,'O' );
                    if( check( pos1 + 1,pos2 - 'a' + 1,1,0,'O' ) == 1 )
                        fills( pos1 + 1,pos2 - 'a' + 1,1,0,'O' );
                    if( check( pos1 + 1, pos2 - 'a',1,-1,'O' ) == 1 )
                        fills( pos1 + 1, pos2 - 'a',1,-1,'O' );
                    if( check( pos1 , pos2 - 'a' + 2,0,1,'O' ) == 1 )
                        fills( pos1 , pos2 - 'a' + 2,0,1,'O' );
                    if( check( pos1 , pos2 - 'a',0,-1,'O' ) == 1 )
                        fills( pos1 , pos2 - 'a',0,-1,'O' );
                    if( check( pos1 - 1, pos2 - 'a' + 2,-1,1,'O' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 2,-1,1,'O');
                    if( check( pos1 - 1, pos2 - 'a' + 1,-1,0,'O' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 1,-1,0,'O' );
                    if( check( pos1 - 1, pos2 - 'a',-1,-1,'O' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a',-1,-1,'O' );
                    board[pos1][pos2 - 'a'+1]='O';
                    temp='X';
            }
            else{
                    if( check( pos1 + 1, pos2 - 'a' + 2,1,1,'X' ) == 1)
                        fills( pos1 + 1, pos2 - 'a' + 2,1,1,'X' );
                    if( check( pos1 + 1,pos2 - 'a' + 1,1,0,'X' ) == 1 )
                        fills( pos1 + 1,pos2 - 'a' + 1,1,0,'X' );
                    if( check( pos1 + 1, pos2 - 'a',1,-1,'X' ) == 1 )
                        fills( pos1 + 1, pos2 - 'a',1,-1,'X' );
                    if( check( pos1 , pos2 - 'a' + 2,0,1,'X' ) == 1 )
                        fills( pos1 , pos2 - 'a' + 2,0,1,'X' );
                    if( check( pos1 , pos2 - 'a',0,-1,'X' ) == 1 )
                        fills( pos1 , pos2 - 'a',0,-1,'X' );
                    if( check( pos1 - 1, pos2 - 'a' + 2,-1,1,'X' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 2,-1,1,'X');
                    if( check( pos1 - 1, pos2 - 'a' + 1,-1,0,'X' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a' + 1,-1,0,'X' );
                    if( check( pos1 - 1, pos2 - 'a',-1,-1,'X' ) == 1 )
                        fills( pos1 - 1, pos2 - 'a',-1,-1,'X' );
                    board[pos1][pos2 - 'a'+1]='X';
            }
        }
    }
    for( i = 1 ; i <= 8 ; i++ ){
        for( j = 1 ; j <= 8 ; j++ ){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

