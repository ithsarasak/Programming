#include<bits/stdc++.h>

using namespace std;
int n;
int g[30][30], ind[30], ch, c, mark[30][30];
char  ans[310];
int euler( int state, int u , int co)
{
    if( state == n ){
        for( int i = 0 ; i < co ; i++ ){
            printf("%c ",ans[i]);
        }
        exit( 0 );
    }
    for( int i = 0 ; i < 26 ; i++ ){
        if(g[u][i] != 0 && mark[u][i] == 0 ){
            mark[i][u] = 1;
            mark[u][i] = 1;
            ans[co] = i + 'A';
            euler( state + 1 , i , co + 1 );
            mark[i][u] = 0;
            mark[u][i] = 0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        char t[2];
        scanf("%s",t);
        g[t[0]-'A'][t[1]-'A'] = 1;
        g[t[1]-'A'][t[0]-'A'] = 1;
        ind[t[0]-'A']++;
        ind[t[1]-'A']++;
    }
    for( int i = 0 ; i < 26 ; i++ ){
        //printf("%d ",ind[i]);
        if( ind[i] % 2 == 1 ){
            ans[0] = i + 'A';
            c++;
            euler( 0, i, 1 );
            ch = 1;
        }
    }
    if( !ch ){
        for( int i = 0 ; i < 26 ; i++ ){
            if( ind[i] !=0 ){
                ans[0] = i + 'A';
                c++;
                euler( 0, i, 1);
            }
        }
    }
    return 0;
}
