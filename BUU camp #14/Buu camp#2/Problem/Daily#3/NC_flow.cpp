#include<bits/stdc++.h>

using namespace std;
struct qq{
    int x, y, le;
    bool operator<( const qq &k )const{
        return le < k.le;
    }
}t;
int ma[110][110], ans = 0, mic[110][110], di[4][2] = { 1 , 0,
                                                       0 , 1,
                                                       -1, 0,
                                                       0 , -1};
int m, n;
priority_queue< qq > q;
int main()
{
    scanf("%d %d",&m,&n);
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            scanf("%d",&ma[i][j]);
            q.push({ i, j, ma[i][j] });
        }
    }
    while( !q.empty() ){
        t = q.top();
        q.pop();
        for( int i = 0 ; i < 4 ; i++ ){
            mic[t.x][t.y] = max( mic[t.x][t.y], mic[t.x+di[i][0]][t.y+di[i][1]] );
        }
        mic[t.x][t.y]++;
    }
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( ans < mic[i][j] ){
                ans = mic[i][j];
            }
        }
    }
    printf("%d",ans);
    return 0;
}
