#include<bits/stdc++.h>

using namespace std;
int c, n, mic[110];
vector< int > train[110];
int main()
{
    memset( mic, 127, sizeof mic );
    scanf("%d %d",&c,&n);
    for( int i = 0 ; i < c - 1 ; i++ ){
        char na[25];
        int num, prev, now;
        scanf("%s",na);
        scanf("%d %d",&num,&prev);
        for( int j = 1 ; j < num ; j++ ){
            scanf("%d",&now);
            train[prev].push_back( now );
            prev = now;
        }
    }
    mic[0] = -1;
    for( int i = 1 ; i <= n ; i++ ){
        mic[i] = min( mic[i], mic[i - 1] + 1 );
        for( int j = 0 ; j < train[i].size() ; j++ ){
            mic[train[i][j]] = min( mic[train[i][j]], mic[i] + 1 );
        }
    }
    printf("%d",mic[n]);
    return 0;
}
