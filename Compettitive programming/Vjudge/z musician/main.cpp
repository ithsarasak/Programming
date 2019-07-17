#include<bits/stdc++.h>

using namespace std;
int m, n, i, j, counts, maxs;
int d1[4] = { -1 , 0 , 1 , 0 };
int d2[4] = { 0 , -1 , 0 , 1 };
int mark[1010][1010];
char maps[1010][1010];
struct cc{
    int x, y;
}t;
queue< cc > q;
int main()
{
    scanf("%d %d",&m,&n);
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            scanf(" %c",&maps[i][j]);
            //printf("%d %d %c\n",i,j,maps[i][j]);
        }
    }
    //printf("%c",maps[1][6]);
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            if( maps[i][j] == '.' && !mark[i][j] ){
                q.push({ i , j });
                counts = 0;
                while( !q.empty() ){
                    counts++;
                    t = q.front();
                    q.pop();
                    //printf("%d %d %d %c\n",counts,t.x,t.y,maps[t.x][t.y]);
                    mark[t.x][t.y] = 1;
                    for( int k = 0 ; k < 4 ; k++ ){
                        if( t.x + d1[k] > 0 && t.x + d1[k] <= m && t.y + d2[k] > 0 && t.y + d2[k] <= n && maps[t.x + d1[k]][t.y + d2[k]] == '.' && mark[t.x + d1[k]][t.y + d2[k]] == 0 ){
                            mark[t.x + d1[k]][t.y + d2[k]] = 1;
                            q.push({ t.x + d1[k] , t.y + d2[k] });
                        }

                    }
                }
                if( maxs < counts ){
                    maxs = counts;
                }
            }
        }
    }
    printf("%d",maxs);
    return 0;
}
