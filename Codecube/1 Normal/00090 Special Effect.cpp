#include<bits/stdc++.h>

using namespace std;
int w, h;
char ma[100][100];
int main()
{
    scanf("%d %d",&w,&h);
    for( int i = 1 ; i <= h ; i++ ){
        scanf("%s",&ma[i][1]);
    }
    for( int i = 1 ; i <= h ; i++ ){
        for( int j = 1 ; j <= w ; j++ ){
            if( ma[i][j] == '>' ){
                int x = i, y = j;
                y++;
                while( j <= w ){
                    if( ma[x][y] == '.' ){
                        ma[x][y] = '-';
                    }
                    else if( ma[x][y] == 'B' ){
                        ma[x][y] = '*';
                        break;
                    }
                    else if( ma[x][y] == '|' ){
                        ma[x][y] = '+';
                    }
                    else break;
                    y++;
                }
            }
            else if( ma[i][j] == '^' ){
                int x = i, y = j;
                x--;
                while( x >= 1 ){
                    if( ma[x][y] == '.' ){
                        ma[x][y] = '|';
                    }
                    else if( ma[x][y] == 'B' ){
                        ma[x][y] = '*';
                        break;
                    }
                    else if( ma[x][y] == '-' ){
                        ma[x][y] = '+';
                    }
                    else break;
                    x--;
                }
            }
            else if( ma[i][j] == '<' ){
                int x = i, y = j;
                y--;
                while( j >= 1 ){
                    if( ma[x][y] == '.' ){
                        ma[x][y] = '-';
                    }
                    else if( ma[x][y] == 'B' ){
                        ma[x][y] = '*';
                        break;
                    }
                    else if( ma[x][y] == '|' ){
                        ma[x][y] = '+';
                    }
                    else break;
                    y--;
                }
            }
            else if( ma[i][j] == 'V' ){
                int x = i, y = j;
                x++;
                while( x <= h ){
                    if( ma[x][y] == '.' ){
                        ma[x][y] = '|';
                    }
                    else if( ma[x][y] == 'B' ){
                        ma[x][y] = '*';
                        break;
                    }
                    else if( ma[x][y] == '-' ){
                        ma[x][y] = '+';
                    }
                    else break;
                    x++;
                }
            }
            else if( ma[i][j] == 'B' ){
                ma[i][j] = '*';
            }
        }
    }
    for( int i = 1 ; i <= h ; i++ ){
        printf("%s\n",&ma[i][1]);
    }
    return 0;
}
