#include <bits/stdc++.h>

using namespace std;
int mic[350][350], n, m, data[350][350];
int play( int l, int r )
{
    if( mic[l][r] != -1 )return mic[l][r];
    int ma = data[l][r];
    for( int i = l ; i < r ; i++ ){
        ma = max( ma, data[l][r] + play( l, i ) + play( i + 1, r ) );
    }
    return mic[l][r] = ma;
}
int main()
{
    memset( mic, -1, sizeof mic );
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i ++ ){
        int s, t;
        scanf("%d %d",&s,&t);
        data[s][t]++;
    }
    printf("%d",m - play( 1, n ));
    return 0;
}
