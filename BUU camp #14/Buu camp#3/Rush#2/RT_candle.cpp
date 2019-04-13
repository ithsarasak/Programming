#include<bits/stdc++.h>

using namespace std;

int m, n, i, j, real1[2500][2500], check[2500][2500], counts = 1, o, l;
char no[2500][2500];
struct point{
    int x, y;
}temp;
queue< point > bfs;
int main()
{
    scanf("%d %d",&m,&n);
    for( i = 1 ; i <= m ; i++ ){
        scanf("%s",&no[i][1]);
    }
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            real1[i][j] = no[i][j] - '0';
        }
    }
    for( o = 1 ; o <= m ; o++ ){
        for( l = 1 ; l <= n ; l++ ){
            if( real1[o][l] == 1 && check[o][l] == 0 ){
                //printf("%d %d\n",i,j);
                bfs.push( { o , l } );
                while( !bfs.empty() ){
                    temp = bfs.front();
                    bfs.pop();
                    //printf("%d %d\n",temp.x,temp.y);
                    check[temp.x][temp.y] = counts;
                    i = temp.x;
                    j = temp.y;
                    if( real1[i - 1][j - 1] == 1 && check[i - 1][j - 1] == 0){
                        check[i - 1][j - 1] = counts;
                        bfs.push( { i - 1 , j - 1 });
                    }
                    if( real1[i - 1][j] == 1 && check[i - 1][j] == 0 ){
                        check[i - 1][j] = counts;
                        bfs.push( { i - 1 , j });
                    }
                    if( real1[i - 1][j + 1] == 1 && check[i - 1][j + 1] == 0 ){
                        check[i - 1][j + 1] = counts;
                        bfs.push( { i - 1 , j + 1 });
                    }
                    if( real1[i][j - 1] == 1 && check[i][j - 1] == 0 ){
                        check[i][j - 1] = counts;
                        bfs.push( { i , j - 1 });
                    }
                    if( real1[i][j + 1] == 1 && check[i][j+ 1] == 0 ){
                        check[i][j + 1] = counts;
                        bfs.push( { i , j + 1 });
                    }
                    if( real1[i + 1][j - 1] == 1 && check[i + 1][j - 1] == 0 ){
                        check[i + 1][j - 1] = counts;
                        bfs.push( { i + 1 , j - 1 });
                    }
                    if( real1[i + 1][j] == 1 && check[i + 1][j] == 0 ){
                        check[i + 1][j] = counts;
                        bfs.push( { i + 1 , j });
                    }
                    if( real1[i + 1][j + 1] == 1 && check[i + 1][j + 1] == 0 ){
                        check[i + 1][j + 1] = counts;
                        bfs.push( { i + 1 , j + 1 });
                    }
                }
                counts++;
            }
        }
    }
    printf("%d",counts - 1);
    return 0;
}

