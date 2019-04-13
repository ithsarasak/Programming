#include<bits/stdc++.h>

using namespace std;

struct it{
    int x, y;
}t;
queue< it > q;
int n, girl[1010][1010], i, j, first = 0, last = INT_MAX, a, b, mark[1010][1010];
int dx[4] = { -1 , 0 , 1 , 0 };
int dy[4] = { 0 , -1 , 0 , 1 };
bool check(int xx ,int yy){
    if( 0< xx && xx <= n && 0 < yy && yy <= n) return true ;
    return false;
}
int bfs( int num )
{
    int ii , jj;
    for( ii = 1 ; ii <= n ; ii++ ){
        for( jj = 1 ; jj <= n ; jj++ ){
            mark[ii][jj] = 0;
        }
    }
    mark[a][b] =  1;
    q.push({ a , b  });
    //printf("%d %d\n",a,b);
    while( !q.empty() ){
        t = q.front();
        q.pop();
       // printf("%d %d\n",t.x,t.y);
        if( girl[t.x][t.y] == 0 && mark[t.x][t.y] == 0 ){
            //printf("%d %d %d\n",num,t.x,t.y);
            while( !q.empty() ){
                q.pop();
            }
            return 1;
        }
        else{
            int backup;
            mark[t.x][t.y] = 1;
            for( int ii = 0 ; ii < 4 ; ii++ ){
                if( check( t.x + dx[ii] , t.y + dy[ii] )){
                    if( girl[t.x + dx[ii]][t.y + dy[ii]] <= num && mark[t.x + dx[ii]][t.y + dy[ii]] == 0 ){
                        if( girl[t.x + dx[ii]][t.y + dy[ii]] != 0 ){
                            mark[t.x + dx[ii]][t.y + dy[ii]] = 1;
                        }
                        //printf("tx %d ty %d\n",t.x + dx[ii], t.y + dy[ii]);
                        q.push({ t.x + dx[ii], t.y + dy[ii] });
                    }
                }
            }
        }
    }
    while( !q.empty() ){
        q.pop();
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            scanf("%d",&girl[i][j]);
            if( girl[i][j] == 0 ){
                a = i;
                b = j;
            }
        }
    }
    int mid;
    while( first < last ){
        mid =  ( first + last ) / 2;
        //printf("%d %d %d\n",first,mid,last);
        if( bfs( mid ) ){
            last = mid;
        }
        else{
            first = mid + 1;
        }
    }
    printf("%d",first);
    return 0;
}
