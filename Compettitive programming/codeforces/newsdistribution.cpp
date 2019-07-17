#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, m, cnt[N], s, f, t, par[N];

int findroot( int num ) {
    if( num == par[num] ) return num;
    else return par[num] = findroot( par[num] );
}

int main()
{
    for( int i = 1 ; i <= 500000 ; i++ ) par[i] = i;
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= m ; i++ ) {
        scanf("%d",&s);
        if( s == 0 ) continue ;
        scanf("%d",&f);
        for( int j = 0 ; j < s - 1 ; j++ ) {
            scanf("%d",&t);
            int x = findroot( f ), y = findroot( t );
            if( x != y ) par[x] = y;
        }
    }
    for( int i = 1 ; i <= n ; i++ ) cnt[findroot( i )]++;
    for( int i = 1 ; i <= n ; i++ ) printf("%d ",cnt[findroot( i )]);
    return 0;
}