#include<bits/stdc++.h>

using namespace std;

struct node{
    int from, go;
    int dis;
    bool operator<( const node &k  )const{
        return dis < k.dis;
    }
}t;
struct node graph[1000010];
int n, i, j, s, m;
int stren[100010];
int par[100010];
long long path;
vector< int > g[100010];

int findroot( int num ){
    if( par[num] == num ){
        return num;
    }
    else{
        return par[num] = findroot( par[num] );
    }
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        //printf("%d\n",i);
        scanf("%d",&stren[i]);
    }
    scanf("%d",&m);
   // printf("%d",m);
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        //printf("%d\n",i);
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j < g[i].size() ; j++ ){
            graph[s].from = i;
            graph[s].go = g[i][j];
            graph[s].dis = stren[i] + stren[g[i][j]];
            s++;
        }
    }
    for( i = 1 ; i <= n ; i ++ ){
        par[i] = i;
    }
    sort( graph , graph + s  );

    for( i = 0 ; i < s ; i++ ){
        //printf("%d %d %d\n",graph[i].from,graph[i].go,graph[i].dis);
        int a = findroot( graph[i].from );
        int b = findroot( graph[i].go );
        if( a != b ){
            par[b] = a;
            path += ( long long )graph[i].dis;
        }
    }
    printf("%lld\n",path);
    return 0;
}
