#include<stdio.h>
#include<stdlib.h>

struct node{
    int from, go;
    int dis;
}t;
struct node graph[1000010];
int n, i, j, s, m;
long long path;
int par[200005];
int compare( const void * a , const void * b )
{
    struct node *p, *q;
    p = ( struct node *)a;
    q = ( struct node *)b;
    if( p -> dis < q -> dis ){
        return 1;
    }
    else{
        return -1;
    }
}
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
    for( i = 0 ; i <= n ; i ++ ){
        par[i] = i;
    }
    qsort( graph , m , sizeof( struct node ) , compare );
    /*for( i = 0 ; i < m ; i ++ ){
        printf("%d %d %d\n",graph[i].from,graph[i].go,graph[i].dis);
    }*/
    for( i = 0 ; i < m ; i++ ){
        int a = findroot( graph[i].from );
        int b = findroot( graph[i].go );
        //printf("%d %d\n",a,b);
        if( a != b ){
            //printf("%d %d %d\n",a,b,graph[i].dis);
            par[b] = a;
            path += graph[i].dis - 1;
        }
    }
    printf("%lld\n",path);
    return 0;
}
