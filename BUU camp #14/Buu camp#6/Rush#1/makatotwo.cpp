#include<bits/stdc++.h>

using namespace std;
int n, va[100100], mark[100100], mic[100100];
long long mi = 21474836470;
vector<int> tr[100100];
int dfs( int now , int lv )
{
    int su = va[now];
    mark[now] = lv;
    for( int i = 0 ; i < tr[now].size() ; i++ ){
        if( mark[tr[now][i]] == 0 ){
            su = su ^ dfs( tr[now][i] , lv + 1 );
        }
    }
    return mic[now] = su;
}
long long query( int now )
{
    long long sum = 0;
    for( int i = 0 ; i < tr[now].size() ; i++ ){
        if( mark[tr[now][i]] > mark[now] ){
            sum += mic[tr[now][i]];
        }
    }
    //printf("%d\n",sum);
    sum += ( mic[1] ^ mic[now] );
    return sum;
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&va[i]);
    }
    for( int i = 0 ; i < n - 1 ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        tr[f].push_back( t );
        tr[t].push_back( f );
    }
    dfs( 1, 1 );
    for( int i = 1 ; i <= n ; i++ ){
        //printf("%d %d\n",mic[i],query( i ));
        mi = min( mi, query( i ) );
    }
    printf("%d",mi);
    return 0;
}
