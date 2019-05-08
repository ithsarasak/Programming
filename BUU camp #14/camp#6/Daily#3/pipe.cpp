#include<bits/stdc++.h>

using namespace std;
struct pp{
    int x, y;
}po[15100];
int n, k;
int dis[15100];
long long ans;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&po[i].x,&po[i].y);
    }
    memset( dis, 127, sizeof dis );
    for( int i = 0 ; i < n - 1 ; i++ ){
        int mi = 1e9, no;
        for( int j = i + 1 ; j < n ; j++ ){
            dis[j] = min( dis[j], abs( po[i].x - po[j].x ) + abs( po[i].y - po[j].y ) );
            if( dis[j] < mi ){
                mi = dis[j];
                no = j;
            }
        }
        swap( dis[i+1], dis[no] );
        swap( po[i+1], po[no] );
    }
    sort( dis, dis + n );
    for( int i = 0 ; i < n - k ; i++ ){
        ans += ( long long )dis[i];
    }
    printf("%lld",ans);
    return 0;
}
