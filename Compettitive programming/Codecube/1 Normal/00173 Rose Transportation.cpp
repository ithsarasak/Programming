#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t, d;
    bool operator<( const ee &k )const{
        return d > k.d;
    }
}ed[200010];
int n, m, t[100010], par[100010];
long long path;
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&t[i]);
    }
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d",&ed[i].f,&ed[i].t);
        ed[i].d = t[ed[i].f] + t[ed[i].t];
    }
    sort( ed, ed + m );
    for( int i = 1 ; i <= n ; i++ ){
        par[i] = i;
    }
    for( int i = 0 ; i <m ; i++ ){
        int a = findroot( ed[i].f );
        int b = findroot( ed[i].t );
        if( a!= b ){
            par[a] = b;
            path += ( long long )ed[i].d;
        }
    }
    printf("%lld",path);
}
