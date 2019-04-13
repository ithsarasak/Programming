#include<bits/stdc++.h>

using namespace std;

int r, c, angle;
char name[11][11], b[11][11];
int main()
{
    scanf("%d %d",&r,&c);
    for( int i = 0 ; i < r ; i++ ){
        scanf("%s",name[i]);
    }
    scanf("%d",&angle);
    while( angle >= 90 ){
        angle -= 90;
        int x = 0, y = 0;
        for( int i = 0 ; i < c ; i++ ){
            y = 0;
            for( int j = r - 1 ; j >= 0 ; j-- ){
                b[x][y] = name[j][i];
                y++;
            }
            x++;
        }
        //printf("hi");
        swap( r, c );
        for( int i = 0 ; i < 11 ; i++ ){
            for( int j = 0 ; j < 11 ; j++ ){
                name[i][j] = 0;
            }
        }
        for( int i = 0 ; i < r ; i++ ){
            for( int j = 0 ; j < c ; j++ ){
                name[i][j] = b[i][j];
            }
        }
        for( int i = 0 ; i < 11 ; i++ ){
            for( int j = 0 ; j < 11 ; j++ ){
                b[i][j] = 0;
            }
        }
    }
    if( angle == 0 ){
        for( int i = 0 ; i < r ; i++ ){
            printf("%s\n",name[i]);
        }
        return 0;
    }
    for( int i = 0 ; i < r + c - 1 ; i++ ){
        for( int j = 0 ; j < r - i - 1 ; j++ ){
            printf("-");
        }
        for( int j = 0 ; j < i - r + 1 ; j++ ){
            printf("-");
        }
        for( int j = 0 ; j < c ; j++ ){
            for( int k = 0 ; k < r ; k++ ){
                if( k + j == i ){
                    if( k == 0 ){
                        printf("%c",name[k][j]);
                    }
                    else if( j == c - 1 ){
                        printf("%c",name[k][j]);
                    }
                    else{
                        printf("%c-",name[k][j]);
                    }
                }
            }
        }
        printf("\n");
    }
}
