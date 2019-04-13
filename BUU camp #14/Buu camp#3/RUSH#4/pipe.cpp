#include<bits/stdc++.h>

using namespace std;
struct ed{
    int f, t, d;
    bool operator<( const ed &k )const{
        return d < k.d;
    }
}e[120000000];
struct pp{
    int x, y;
}po[15010];
int n, k, s, co;
int par[15010];
long long ans;
int findroot( int num ){
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&po[i].x,&po[i].y);
    }
    for( int i = 0 ; i < n ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
            e[s].f = i;
            e[s].t = j;
            e[s].d = abs( po[i].x - po[j].x ) + abs( po[i].y - po[j].y );
            s++;
        }
    }
    sort( e, e + s );
    for( int i = 0 ; i <= n ; i++ ){
        par[i] = i;
    }
    /*for( int i = 0 ; i < s ;  i ++ ){
        printf("%d %d %d\n",e[i].f,e[i].t,e[i].d);
    }*/
    for( int i = 0 ; ; i++ ){
        int a = findroot( e[i].f );
        int b = findroot( e[i].t );
        if( a != b ){
            par[a] = b;
            //printf("%d\n",e[i].d);
            ans += ( long long )e[i].d;
            co++;
            if( co == n-k )break;
        }
    }
    printf("%lld",ans);
    return 0;
}
