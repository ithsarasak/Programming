#include<bits/stdc++.h>

using namespace std;
int q, poi[100010], ind[100010], n, mark[100010];
int cnt;
void dfs( int no, int co )
{
    if(mark[no])    return ;
    mark[no] = co;
    ind[poi[no]]--;
    if( ind[poi[no]] == 0 || co == 1 ) dfs(poi[no],3-co);
}
int main()
{
    scanf("%d",&q);
    while( q-- ){
        cnt = 0;
        for( int i = 0 ; i <= 100000 ; i++ )ind[i]=0,mark[i]=0;
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&poi[i]);
            ind[poi[i]]++;
        }
        for( int i = 1 ; i <= n ; i++ ){
            if( ind[i] == 0 && !mark[i] ){
                dfs( i, 1 );
            }
        }
        for( int i = 1 ; i <= n ; i++ ){
            if( !mark[i] ){
                dfs( i, 2 );
            }
        }
        for( int i = 1 ; i <= n ; i++ ){
            if( mark[i] == 2 )cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
