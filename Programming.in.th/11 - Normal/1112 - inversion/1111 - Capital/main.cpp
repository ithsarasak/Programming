#include<stdio.h>
#include<vector>

using namespace std;

struct node{
    int x, d;
    bool operator<( const struct node &p )const{
        return x < p.x;
    }
};
typedef struct node node;
vector<node> dis[100010];
long long dp[100010];
int i, j, n;
int max( int a , int b )
{
    return( a > b ? a : b );
}
int main()
{
    scanf("%d",&n);

    for( i = 0 ; i < n - 1 ; i++ ){
        int a, b, c;

        scanf("%d %d %d",&a,&b,&c);

        if( a > b ){
            int t;
            t = a;
            a = b;
            b = t;
        }
        dis[a].push_back({ b , c});
    }
    for( i = 1 ; i <= n ; i++ ){
        j = 0;
        for( j = 0 ; j < dis[i].size() ; j++ ){
                //printf(" %d",dis[i][j].d);
            if( dp[dis[i][j].x] == 0 ){
                dp[dis[i][j].x] = dp[i] + dis[i][j].d;
            }
            else{
                dp[dis[i][j].x] = max( dp[i] + dis[i][j].d , dp[j] );
            }
        }
        //printf("\n");
    }
    int maxx = 0;
    for( i = 1 ; i <= n ; i++ ){
       // printf(" %d",dp[i]);
        if( maxx < dp[i] ){
            maxx = dp[i];
        }
    }
    printf("%d",maxx);
}
