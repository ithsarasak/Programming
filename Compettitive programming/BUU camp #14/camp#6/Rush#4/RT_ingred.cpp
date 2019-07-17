#include<bits/stdc++.h>

using namespace std;
struct pa{
    int x, y;
}pai[410];
int n, m, ans;
int in[30];
void play( int idx, int va )
{
    if( idx == n ){
        in[idx] = va;
        /*for( int i = 0 ; i <= idx ; i++ ){
            printf("%d",in[i]);
        }
        printf("\n");*/
        for( int i = 0 ; i < m ; i++ ){
            if( in[pai[i].x] == 1 && in[pai[i].y] == 1 ){
                return ;
            }
        }
        ans ++;
        return ;
    }
    in[idx] = va;
    play( idx + 1, 0 );
    play( idx + 1, 1 );
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d",&pai[i].x,&pai[i].y);
    }
    play( 1, 0 );
    play( 1, 1 );
    printf("%d",ans);
    return 0;
}
