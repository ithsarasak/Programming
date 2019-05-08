#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t;
    double w;
    bool operator<( const ee &k )const{
        return w < k.w;
    }
}e[1000010];
int n, m;
int par[1010];
double ans;
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d %lf",&e[i].f,&e[i].t,&e[i].w);
    }
    for( int i = 0 ; i <= n ; i++ ){
        par[i] = i;
    }
    sort( e, e+m );
    for( int i = 0 ; i < m ; i++ ){
        int a = findroot( e[i].f );
        int b = findroot( e[i].t );
        if( a != b ){
            par[a] = b;
            ans += e[i].w;
        }
    }
    printf("%.3f",ans);
    return 0;
}
