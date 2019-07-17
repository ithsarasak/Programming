#include<bits/stdc++.h>

using namespace std;
int n, m, ans = 1e9, permu[25], buc[25];
vector< int > bomb[25];
void dfs( int p, int va )
{
    //printf("%d %d\n",p,va);
    if( p == n - 1 ){
        permu[p] = va;
        memset( buc, 0, sizeof buc );
        int s = 0, c = 0;
        //printf("permu : ");
        for( int i = 0 ; i < n ; i ++ ){
            //printf("%d",permu[i]);
            if( permu[i] == 1 ){
                for( int j = 0 ; j < bomb[i].size() ; j++ ){
                    if( buc[bomb[i][j]] == 0 ){
                        buc[bomb[i][j]] = 1;
                        s++;
                    }
                }
                c++;
            }
        }
//        printf("\n");
//        printf("Choo : ");
//        for( int i = 1 ; i <= m ; i++ ){
//            printf("%d",buc[i]);
//        }
//        printf("\n");
//        printf("S : %d C : %d Ans : %d\n",s,c,ans);
        //printf("\n%d %d\n",s,c);
        if( s == m && ans > c ){
            ans = c;
        }
        return ;
    }
    permu[p] = va;
    dfs( p + 1, 0 );
    dfs( p + 1, 1 );
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        int bi;
        scanf("%d",&bi);
        for( int j = 0 ; j < bi ; j++ ){
            int t;
            scanf("%d",&t);
            bomb[i].push_back( t );
        }
    }
    dfs( 0, 0 );
    dfs( 0, 1 );
    printf("%d",ans);
    return 0;
}
