#include<bits/stdc++.h>

using namespace std;
queue<int> b;
vector<int> g[50100], g2[50100];
stack<int> ko;
string scc[50010];
int visit[50100], visit2[50100];
char cc[50100];
int st, en;
int ind[50010];
string mic[50010];
int n, m, k, co;
int dfs( int node )
{
    visit[node] = 1;
    for( int i = 0 ; i < g[node].size() ; i++ ){
        if( !visit[g[node][i]] ){
            dfs( g[node][i] );
        }
    }
    ko.push( node );
}
int dfs2( int node )
{
    if( node == 1 )st = co;
    else if( node == n )en = co;
    visit2[node] = co;
    scc[co] += cc[node];
    for( int i = 0 ; i < g2[node].size() ; i++ ){
        if( !visit2[g2[node][i]] ){
            dfs2( g2[node][i] );
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m);
    scanf("%s",&cc[1]);
    for( int i = 1 ; i <= m ; i++ ){
        int fr, to;
        scanf("%d %d",&fr,&to);
        g[fr].push_back( to );
        g2[to].push_back( fr );
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( !visit[i] )dfs( i );
    }
    while( !ko.empty() ){
        int tt = ko.top();
        ko.pop();
        if( !visit2[tt] ){
            co++;
            dfs2( tt );
        }
    }
    for( int i = 1 ; i <= co ; i++ ){
        sort( scc[i].begin(), scc[i].end() );
    }
    for( int i = 0 ; i <= 50000 ; i++ ){
        g2[i].clear();
        visit[i] = 0;
    }
    b.push( st );
    while( !b.empty() ){
        int t = b.front();
        b.pop();
        visit[t] = 1;
        for( int i = 0 ; i < g[t].size() ; i++ ){
            if( visit2[g[t][i]] != visit2[t] ){
                g2[visit2[t]].push_back( visit2[g[t][i]] );
                ind[visit2[g[t][i]]]++;
            }
            if( !visit[g[t][i]] ){
                b.push( g[t][i] );
                visit[g[t][i]] = 1;
            }
        }
    }
    /*for( int i = 1 ; i <= co ; i++ ){
        printf("%d : ",i);
        for( int j = 0 ; j < g2[i].size() ; j++ ){
            printf("%d ",g2[i][j]);
        }
        printf("\n");
    }*/
    b.push( st );
    while( !b.empty() ){
        int t = b.front();
        b.pop();
        mic[t] += scc[t];
        for( int i = 0 ; i < g2[t].size() ; i++ ){
            ind[g2[t][i]]--;
            if( mic[g2[t][i]] == "" || mic[t].length() > mic[g2[t][i]].length() || ( mic[t].length() == mic[g2[t][i]].length() && mic[t] < mic[g2[t][i]] ) ){
                mic[g2[t][i]] = mic[t];
            }
            if( ind[g2[t][i]] == 0 ){
                b.push( g2[t][i] );
            }
        }
    }
    cout << mic[en];
    return 0;
}

