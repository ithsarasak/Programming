#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t;
    long long d;
    bool operator<( const ee &k )const{
        return d < k.d;
    }
};
struct tt{
    int t;
    long long d;
};
struct ll{
    int no;
    long long di;
}lca[100100][20];
vector<tt> tr[100100];
int n, m;
long long mi = 1e18;
long long path;
int par[100100], lv[100100];
vector<ee> e, e3;
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
long long lc( int a, int b )
{
    long long ma = 0;
    if ( lv[a] < lv[b] )swap( a, b );
    for( int i = 19 ; i >= 0 ; i-- ){
        if( lv[lca[a][i].no] >= lv[b] ){
            ma = max( ma, lca[a][i].di );
            a  = lca[a][i].no;
        }
    }
    if( a == b ){
        return ma;
    }
    for( int i = 19 ; i >= 0 ; i-- ){
        if( lca[a][i].no != lca[b][i].no ){
            ma = max( ma, lca[a][i].di );
            ma = max( ma, lca[b][i].di );
            a = lca[a][i].no;
            b = lca[b][i].no;
        }
    }
    ma = max( ma, max( lca[b][0].di, lca[a][0].di ) );
    return ma;
}
void init_lca( int now, int p )
{
    for( int i = 1 ; i < 20 ; i++ ){
        lca[now][i].no = lca[lca[now][i-1].no][i-1].no;
        lca[now][i].di = max( lca[now][i-1].di,lca[lca[now][i-1].no][i-1].di );
    }
    for( auto v : tr[now] )if( v.t != p )lv[v.t] = lv[now] + 1, lca[v.t][0].no = now, lca[v.t][0].di = v.d, init_lca( v.t, now );
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ )par[i] = i;
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        long long d;
        scanf("%d %d %lld",&f,&t,&d);
        f++, t++;
        e.push_back({ f, t, d });
    }
    sort( e.begin(), e.end() );
    for( int i = 0 ; i < e.size() ; i++ ){
        int a = findroot( e[i].f );
        int b = findroot( e[i].t );
        if( a != b ){
            tr[e[i].f].push_back({ e[i].t, e[i].d });
            tr[e[i].t].push_back({ e[i].f, e[i].d });
            par[a] = b;
            path += e[i].d;
        }
        else e3.push_back( e[i] );
    }
    init_lca( 1, 0 );
    for( int i = 0 ; i < e3.size() ; i++ ){
        long long hh = path + e3[i].d - lc( e3[i].f, e3[i].t );
        if( hh > path && hh < mi )mi = hh;
    }
    printf("%lld",mi-path+1);
    return 0;
}
