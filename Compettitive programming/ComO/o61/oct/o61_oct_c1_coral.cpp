#include <bits/stdc++.h>

using namespace std;

const int N = 1500000;
int mark[N], k, m, ans = 1e9, cnt;

int main()
{
    scanf("%d %d",&k,&m);
    for( int i = 1 ; i <= m ; i++ ) {
        int x, y;
        scanf("%d %d",&y,&x);
        y = x + ( 1 << y ), x++;
        if( mark[x-1] == 0 ) cnt++, mark[x-1] = 1;
        if( mark[y] == 0 ) cnt++, mark[y] = 1;
        if( cnt == ( 1 << k ) + 1 ) ans = min( ans, i );  
    } 
    printf("%d",ans);
    return 0;
}