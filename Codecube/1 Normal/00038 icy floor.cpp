#include<bits/stdc++.h>

using namespace std;
struct po{
    int x, y, path;
    bool operator<( const po &k )const{
        return path > k.path;
    }
}t;
int n, ma[1010][1010], mark[1010][1010];
int fx[4] = { 1, 0, -1, 0 };
int fy[4] = { 0, 1, 0, -1 };
priority_queue<po> q;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            scanf("%d",&ma[i][j]);
        }
    }
   // printf("\n");
    q.push({ 1, 1, 0 });
    while( !q.empty() ){
        t = q.top();
        q.pop();
        if( mark[t.x][t.y] )continue;
        mark[t.x][t.y] = 1;
        if( t.x == n && t.y == n ){
            printf("%d",t.path);
            return 0;
        }
        for( int i = 0 ; i < 4 ; i++ ){
            int te = t.path;
            int te2 = t.x, te3 = t.y;
            while( te2 + fx[i] > 0 && te2 +fx[i] <= n && te3 + fy[i] > 0 && te3 + fy[i] <= n ){
                if( ma[te2 + fx[i]][te3 + fy[i]] != 0 ){
                    break;
                }
                te++;
                te2 += fx[i];
                te3 += fy[i];
            }
            if( !mark[te2][te3] ){
                q.push({ te2, te3, te });
                /*for( int i = 1 ; i <= n ; i++ ){
                    for( int j = 1 ; j <= n ; j++ ){
                        printf("%d ",mark[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");*/
            }

        }
    }
    printf("-1");
    return 0;
}
