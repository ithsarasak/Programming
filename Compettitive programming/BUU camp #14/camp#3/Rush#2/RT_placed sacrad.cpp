#include<bits/stdc++.h>

using namespace std;
struct ee{
     int d, f, t;
     bool operator<( const ee &k )const{
        return d > k.d;
    }
}e[1000010];
int par[200010];
int n, m;
long long ans;
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i= 0 ; i < m ; i++ ){
        scanf("%d %d %d",&e[i].f,&e[i].t,&e[i].d);
        e[i].d--;
    }
    sort( e, e+m );
    for( int i = 1 ; i <= n ; i++ ){
        par[i] = i;
    }
    for( int i = 0 ; i < m ; i++ ){
        int a = findroot( e[i].f );
        int b = findroot( e[i].t );
        if( a != b ){
            par[a] = b;
            ans += ( long long )e[i].d;
        }
    }
    printf("%lld",ans);
    return 0;
}
