#include<stdio.h>
#include<string.h>

char map[25][26],wfind[100][20];
int m,n,k,nword,len[100], check[100];

int findword( int x , int y , int d )
{
    int sum = 0, checks = 0 ;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x+i][y] != wfind[d][i] || x + i >= m ){
            //break;
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 0 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    sum = 0 ;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x-i][y] != wfind[d][i] || x - i < 0 ){
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 1 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    sum = 0;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x][y+i] != wfind[d][i] || y + i >= n ){
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 2 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    sum = 0 ;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x][y-i] != wfind[d][i] || y - i < 0 ){
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 3 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    sum = 0;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x+i][y+i] != wfind[d][i] || y + i >= n || x + i >= m ){
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 4 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    sum = 0 ;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x+i][y-i] != wfind[d][i] || x + i >= m || y - i < 0 ){
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 5 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    sum = 0 ;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x-i][y+i] != wfind[d][i] || x - i < 0 || y + i >= n ){
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 6 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    sum = 0 ;
    for( int i = 1 ; i < len[d] ; i++ ){
        if( map[x-i][y-i] != wfind[d][i] || x - i < 0 || y - i < 0 ){
            sum = 1;
            checks++;
            break;
        }
    }
    //printf("sum : %d\n",sum);
    if( checks == 7 ){
        printf("%d %d\n",x,y);
        check[d] = 1;
        return 1;
    }
    return 0;
}
int main()
{
    int r = 0;
    scanf("%d %d",&m,&n);
    scanf("\n");
    for( int i = 0 ; i < m ; i++ ){
        gets( map[i] );
    //printf("%d",i);
    }
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( map[i][j] >= 97 && map[i][j] <= 122 ){
                map[i][j] -= 32;
            }
        }
    }
    scanf("\n");
    scanf("%d",&k);
    scanf("\n");
    for( int i = 0 ; i < k ; i++ ){
        gets( wfind[i] );
        //printf("%d",i);
    }
    //scanf("\n");
    for( int i = 0 ; i < k ; i++ ){
        len[i] = strlen( wfind[i] );
        for( int j = 0 ; j < len[i] ; j++ ){
            if( wfind[i][j] >= 97 && wfind[i][j] <= 122 ){
                wfind[i][j] -= 32;
                //printf("*");
            }
        }
    }

    int d = 0;
    int c = 0;
    for( int d = 0 ; d < k ; d++ ){
            c = 0;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( map[i][j] == wfind[d][0] ){
                        r = findword( i , j , d );
                        if( check[d] ){
                            c = 1;
                            break;
                        }
                    //printf("%d %d\n",i,j);
                }
            }
            if( c ){
                break;
            }
        }
    }
    return 0;
}
