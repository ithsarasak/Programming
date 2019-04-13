#include<bits/stdc++.h>

using namespace std;

struct path{
    int x, y, max_chak;
    bool operator<( const path &k )const{
        return max_chak > k.max_chak;
    }
}t;
struct point{
    int a, b;
}se[2];
priority_queue< path > pq;
int n, maps[1001][1001], c, mark[1001][1001];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            scanf("%d",&maps[i][j]);
            if( maps[i][j] == 0 ){
                se[c].a = i;
                se[c].b = j;
                c++;
            }
        }
    }
    pq.push({ se[0].a, se[0].b, 0 });
    mark[se[0].a][se[0].b] = 1;
    while( !pq.empty() ){
        t = pq.top();
        int ch = t.max_chak;
        mark[t.x][t.y] = 1;
        pq.pop();
        if( t.x == se[1].a && t.y == se[1].b ){
            printf("%d",t.max_chak);
            return 0;
        }
        //printf("%d %d\n",t.x,t.y);
        if( t.x - 1 > 0 && mark[t.x - 1][t.y] == 0 ){
            //printf("x - 1 %d %d\n",t.x - 1,t.y);
            if( maps[t.x - 1][t.y] > ch ){
                pq.push({ t.x - 1, t.y, maps[t.x - 1][t.y] });
            }
            else{
                pq.push({ t.x - 1, t.y, ch });
            }
        }
        if( t.y + 1 <= n && mark[t.x][t.y + 1] == 0 ){
            //printf("y + 1 %d %d\n",t.x,t.y + 1);
            if( maps[t.x][t.y + 1] > ch ){
                pq.push({ t.x, t.y + 1, maps[t.x][t.y + 1] });
            }
            else{
                pq.push({ t.x, t.y + 1, ch });
            }
        }
        if( t.x + 1 <= n && mark[t.x + 1][t.y] == 0 ){
            //printf("x + 1 %d %d\n",t.x + 1,t.y);
            if( maps[t.x + 1][t.y] > ch ){
                pq.push({ t.x + 1, t.y, maps[t.x + 1][t.y] });
            }
            else{
                pq.push({ t.x + 1, t.y, ch });
            }
        }
        if( t.y - 1 > 0 && mark[t.x][t.y - 1] == 0 ){
            //printf("y - 1 %d %d\n",t.x,t.y - 1);
            if( maps[t.x][t.y - 1] > ch ){
                pq.push({ t.x, t.y - 1, maps[t.x][t.y - 1] });
            }
            else{
                pq.push({ t.x, t.y - 1, ch });
            }
        }
    }
}
