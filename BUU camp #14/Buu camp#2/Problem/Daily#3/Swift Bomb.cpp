#include<bits/stdc++.h>
using namespace std;
struct qq{
    int x, y, lv;
}t;
int n, m, qu, x, y;
int ma[1010][1010], buc[1000010];
queue< qq > q;
int main()
{
    memset( ma, -1, sizeof ma );
    scanf("%d %d %d",&n,&m,&qu);
    for( int i = 0 ; i < m ; i++ ){
        int a, b;
        scanf("%d %d",&a,&b);
        ma[a][b] = -1e9;
    }
    scanf("%d %d",&x,&y);
    q.push({ x, y, 0 });
    while( !q.empty() ){
        t = q.front();
        q.pop();
        buc[t.lv]++;
        ma[t.x][t.y] = t.lv;
        if( t.x - 1 > 0 && ma[t.x-1][t.y] == -1 ){
            q.push({ t.x - 1, t.y, t.lv + 1 });
            ma[t.x-1][t.y] = t.lv+1;
        }
        if( t.y - 1 > 0 && ma[t.x][t.y-1] == -1 ){
            q.push({ t.x, t.y-1, t.lv + 1 });
            ma[t.x][t.y-1] = t.lv+1;
        }
        if( t.x + 1 <= n && ma[t.x+1][t.y] == -1 ){
            q.push({ t.x + 1, t.y, t.lv + 1 });
            ma[t.x+1][t.y] = t.lv+1;
        }
        if( t.y + 1 <= n && ma[t.x][t.y+1] == -1 ){
            q.push({ t.x, t.y+1, t.lv + 1 });
            ma[t.x][t.y+1] = t.lv+1;
        }
    }
    for( int i = 1 ; i <= n*n ; i++ ){
        buc[i] += buc[i - 1];
    }
    while( qu-- ){
        int ttt;
        scanf("%d",&ttt);
        printf("%d\n",buc[ttt]);
    }
}
