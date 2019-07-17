#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t, d;
    bool operator<( const ee &k )const{
        return d < k.d;
    }
};
int n, t;
int par[350];
vector<ee> e;
int findroot( int node )
{
    if( par[node] == node )return node;
    else return par[node] = findroot( par[node] );
}
int ind[350];
int main()
{
    scanf("%d %d",&n,&t);
    for( int i = 1 ; i <= n ; i++ ){
        par[i] = i;
        for( int j = 1 ; j <= n ; j++ ){
            int tt;
            scanf("%d",&tt);
            if( i != j ){
                e.push_back({ i, j, tt });
                e.push_back({ j, i, tt });
            }
        }
    }
    sort( e.begin(), e.end() );
    for( int i = 0 ; i < n*n ; i++ ){
        int f = e[i].f;
        int t = e[i].t;
        int d = e[i].d;
        int a = findroot( e[i].f );
        int b = findroot( e[i].t );
        if( a != b ){
            ind[f]++;
            ind[t]++;
            par[a] = b;
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( ind[i] >= 3 )printf("%d ",i);
    }
    printf("\n");
    if( t == 2 ){
        for( int i = 1 ; i <= n ; i++ ){
            if( ind[i] >= 3 )printf("%d ",ind[i]);
        }
    }
    return 0;
}
