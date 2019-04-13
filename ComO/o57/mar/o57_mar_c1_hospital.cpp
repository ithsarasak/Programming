#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> g[100100];
int visit[100100], ans, mi = 1e9;
int mic[100100], mic2[100100], mic3[100100];
int dfs( int v )
{
    //printf("%d\n",v);
    visit[v] = 1;
    for( int i = 0 ; i < g[v].size() ; i++ ){
        if( !visit[g[v][i]] ){
            mic[v] += dfs( g[v][i] );
            mic2[v] += mic[g[v][i]] + 1 + mic2[g[v][i]];
        }
    }
    return mic[v] + 1;
}
void sol( int v, int p )
{
    visit[v] = 1;
    if( v == 1 ){
        ans = 1;
        mi = mic2[1];
        for( int i = 0 ; i < g[v].size() ; i++ ){
            if( !visit[g[v][i]] ){
                sol( g[v][i], v );
            }
        }
    }
    else{
        int tt;
        mic3[v] = ( mic[1] - mic[v] ) + mic3[p] + ( mic2[p] - mic2[v] - mic[v] - 1 );
        tt = mic2[v] + ( mic[1] - mic[v] ) + mic3[p] + ( mic2[p] - mic2[v] - mic[v] - 1 );
        if( tt < mi ){
            mi = tt;
            ans = v;
        }
        for( int i = 0 ; i < g[v].size() ; i++ ){
            if( !visit[g[v][i]] ){
                sol( g[v][i], v );
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i < n ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
        g[t].push_back( f );
    }
    dfs( 1 );
    memset( visit, 0, sizeof visit );
    sol( 1, 0 );
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%d %d %d\n",mic[i],mic2[i],mic3[i]);
    }*/
    printf("%d",mic2[ans]+mic3[ans]);
    return 0;
}
