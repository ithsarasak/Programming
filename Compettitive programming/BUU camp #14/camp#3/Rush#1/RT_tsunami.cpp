#include<bits/stdc++.h>

using namespace std;

int f[4] = { -1 , 0 , 1 , 0 };
int g[4] = { 0 , -1 , 0 , 1 };
int n, i, j, t[1001][1001], mark[1001][1001], check, counts;
struct bfs{
    int lv, x, y;
}tt;
queue< bfs > q;
priority_queue< int > pq;
long long sum;
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        for( j = 0 ; j < n ; j++ ){
            scanf("%d",&t[i][j]);
        }
    }
    q.push({ 1 , n - 1 , n - 1 });
    check = 1;
    sum += t[n - 1][n - 1];
    mark[n - 1][n - 1] = 1;
    while( !q.empty() ){
        tt = q.front();
        //printf("%d %d %d\n",tt.lv,tt.x,tt.y);
        q.pop();
        if( tt.lv != check && tt.lv < 2 * n - 1 ){
            int h = pq.top();
            pq.pop();
            sum += ( long long )h;
            check = tt.lv;
            //printf("%d %d %d\n",tt.lv,h,sum);
        }
        for( i = 0 ; i < 4 ; i++ ){
            if( tt.x + f[i] >= 0 && tt.x + f[i] < n && tt.y + g[i] >= 0 && tt.y + g[i] < n ){
                if( mark[tt.x + f[i]][tt.y + g[i]] == 0 ){
                    q.push({ tt.lv + 1 , tt.x + f[i] , tt.y + g[i] });
                    pq.push( t[tt.x + f[i]][tt.y + g[i]] );
                    mark[tt.x + f[i]][tt.y + g[i]] = tt.lv + 1;
                }
            }
        }
    }
    printf("%lld",sum);
    return 0;
}
