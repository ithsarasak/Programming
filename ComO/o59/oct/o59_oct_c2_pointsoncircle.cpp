#include<bits/stdc++.h>

using namespace std;
struct vv{
    int f, t, d;
    bool operator<( const vv &k )const{
        return d < k.d;
    }
};
struct gg{
    int t, d;
};
vector<gg> g[1100];
vector<vv> v;
int par[1100], visit[1100], pos[1100], ind[1100];
int n, k;
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int dfs( int no, int lv )
{
    //printf("%d %d\n",no,lv);
    visit[no] = 1;
    pos[no] = lv % n;
    for( int i = 0 ; i < g[no].size() ; i++ ){
        if( !visit[g[no][i].t] ){
            dfs( g[no][i].t, lv + g[no][i].d );
        }
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= k ; i++ )par[i] = i;
    for( int i = 1 ; i <= k ; i++ ){
        for( int j = 1 ; j <= k ; j++ ){
            int d;
            scanf("%d",&d);
            if( i != j ){
                v.push_back({ i, j, d });
            }
        }
    }
    sort( v.begin(), v.end() );
    for( int i = 0 ; i < v.size() ; i++ ){
        int a = findroot( v[i].f );
        int b = findroot( v[i].t );
        if( a != b ){
            par[a] = b;
            g[v[i].f].push_back({ v[i].t, v[i].d });
            g[v[i].t].push_back({ v[i].f, v[i].d });
            ind[v[i].t]++;
            ind[v[i].f]++;
        }
    }
    for( int i = 1 ; i <= k ; i++ ){
        if( ind[i] == 1 ){
            dfs( i, 0 );
            break;
        }
    }
    for( int i = 1 ; i <= k ; i++ ){
        printf("%d\n",pos[i]);
    }
    return 0;
}
