#include<bits/stdc++.h>

using namespace std;
struct node{
    int to, dis;
};

vector< node > tree[110];
int mark[110], dp[110][110], l[110], r[110], w[110];
int dfs( int curnode )
{
    mark[curnode] = 1;
    for( int i = 0 ; i < tree[curnode].size() ; i++ ){
        if( mark[tree[curnode][i].to] )continue;
        if( l[curnode] == 0 ) l[curnode] = tree[curnode][i].to;
        else r[curnode] = tree[curnode][i].to;
        w[tree[curnode][i].to] = tree[curnode][i].dis;
        dfs( tree[curnode][i].to );
    }
}
int mic( int now, int k )
{
    int mx = -1;
    if( k == 0 ){
        return 0;
    }
    if( dp[now][k] != -1 ){
        return dp[now][k];
    }
    for( int i = 0 ; i < k ; i++ ){
        mx = max( mx, mic( l[now], i ) + mic( r[now], k - i - 1 ) );
    }
    return dp[now][k] = mx + w[now];
}
int main()
{
    int n, k;
    memset( dp , -1, sizeof dp );
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n - 1 ; i++ ){
        int f, t, dis;
        scanf("%d %d %d",&f,&t,&dis);
        tree[f].push_back({ t, dis });
        tree[t].push_back({ f, dis });
    }
    dfs( 1 );
//    for( int i = 1 ; i <= n ; i++ ){
//        printf("%d %d %d\n",w[i],l[i],r[i]);
//    }
    printf("%d",mic( 1, k + 1 ));
    return 0;
}
/*
5 2
1 3 1
1 4 10
2 3 20
3 5 20
*/
