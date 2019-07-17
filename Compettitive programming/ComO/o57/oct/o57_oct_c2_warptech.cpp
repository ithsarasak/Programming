#include <bits/stdc++.h>

using namespace std;
struct gg{
    int t, d;
};
struct ee{
    int f, t, d;
    bool operator<( const ee &k )const{
        return d < k.d;
    }
};
vector<gg> g[5050];
vector<int> tree; 
vector<ee> edge;
int n, m, q, par[5050];
int findroot( int node )
{
    if( par[node] == node )return node;
    else return par[node] = findroot( par[node] );
}
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for( int i = 0 ; i < m ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
        g[t].push_back({ f, d });
        edge.push_back({ t, f, d });
    }
    sort( edge.begin(), edge.end() );
    for( int i = 0 ; i < n ; i++ )par[i] = i;
    for( int i = 0 ; i < edge.size() ; i++ ){
        int a = findroot( edge[i].f );
        int b = findroot( edge[i].t );
        if( a != b ){
            par[a] = b;
            tree.push_back( edge[i].d );
        }
    }
    sort( tree.begin(), tree.end(), greater<int>() );
    for( int i = 0 ; i < q ; i++ ){
        int qe;
        scanf("%d",&qe);
        qe--;
        printf("%d\n",tree[qe]);
    }
    return 0;
}
