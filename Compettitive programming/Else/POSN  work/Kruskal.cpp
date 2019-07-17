#include<bits/stdc++.h>

using namespace std;

struct node{
    int from, go;
    int dis;
    bool operator<( const node &k  )const{
        return dis < k.dis;
    }
}t;
struct node graph[600000];
int n, i, j, s, m;
int path;
int par[1010];

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
    scanf("%d %d",&n,&m);
    for( i = 0 ; i < m ; i ++ ){
        scanf("%d %d %d",&graph[i].from,&graph[i].go,&graph[i].dis);
    }
    for( i = 0 ; i < n ; i ++ ){
        par[i] = i;
    }
    sort( graph , graph + m  );
    for( i = 0 ; i < m ; i++ ){
        int a = findroot( graph[i].from );
        int b = findroot( graph[i].go );
        //printf("%d %d\n",a,b);
        if( a != b ){
            //printf("%d %d %lf\n",a,b,graph[i].dis);
            par[b] = a;
            path += graph[i].dis;
        }
    }
    printf("%d\n",path);
    return 0;
}
