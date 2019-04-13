#include<bits/stdc++.h>

using namespace std;

struct path{
    int x, y, minpath;
    bool operator<( const path &k )const{
        return minpath > k.minpath;
    }
}t;
struct point{
    int a, b;
}se[2];
priority_queue< path > pq;
int r, maps[2010][210], c, mark[2010][210], n, d, starti = 1, startj = 1, sum;
int main()
{
    scanf("%d %d",&r,&c);
    for( int i = 1 ; i <= r ; i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            scanf("%d",&maps[i][j]);
        }
    }
    scanf("%d",&d);
    sum = maps[1][1];
    for( int i = 0 ; i < d ; i++ ){
        scanf("%d %d",&se[i].a,&se[i].b);
        //printf("hey");
        int endi = se[i].a, endj = se[i].b;
        for( int i = 0 ; i <= r ; i++ ){
            for( int j = 0 ; j <= c ; j++ ){
                mark[i][j] = 0;
            }
        }
        //printf("w");
        while( !pq.empty() ){
            pq.pop();
        }
        //printf("Hi");
        //printf("%d %d %d",starti,startj,sum);
        printf(">>");
        t.x = starti;
        t.y = startj;
        t.minpath = sum;
        pq.push( t );
        //t = pq.top();
        printf("WTFFFFFF");
        //printf("%d %d %d\n",t.x,t.y,t.minpath);
        while( !pq.empty() ){
            //printf("What");
            t = pq.top();

            int ch = t.minpath;
            mark[t.x][t.y] = 1;
            pq.pop();
            if( t.x == endi && t.y == endj ){
                sum = t.minpath;
                starti = endi;
                startj = endj;
                //printf("%d %d %d",sum,endi,endj);
                break;
            }
            //printf("%d %d %d\n",t.x,t.y,t.minpath);

            if( t.x - 1 > 0 && mark[t.x - 1][t.y] == 0 ){
                //printf("x - 1 %d %d %d\n",t.x - 1,t.y,ch + maps[t.x - 1][t.y]);
                pq.push({ t.x - 1, t.y, ch + maps[t.x - 1][t.y] });
            }
            if( t.y + 1 <= c && mark[t.x][t.y + 1] == 0 ){
                //printf("y + 1 %d %d %d\n",t.x,t.y + 1,ch + maps[t.x][t.y + 1]);
                pq.push({ t.x, t.y + 1, ch + maps[t.x][t.y + 1] });
            }
            if( t.x + 1 <= r && mark[t.x + 1][t.y] == 0 ){
                //printf("x + 1 %d %d %d\n",t.x + 1,t.y,ch + maps[t.x + 1][t.y]);
                pq.push({ t.x + 1, t.y, ch + maps[t.x + 1][t.y] });
            }
            if( t.y - 1 > 0 && mark[t.x][t.y - 1] == 0 ){
                //printf("y - 1 %d %d %d\n",t.x,t.y - 1,ch + maps[t.x][t.y - 1]);
                pq.push({ t.x, t.y - 1, ch + maps[t.x][t.y - 1] });
            }
        }
    }
    printf("%d",sum );
    return 0;
}

