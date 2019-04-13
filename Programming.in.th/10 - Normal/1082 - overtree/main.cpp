#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node{
    int from, go, dis;
    bool operator <(const node &o)const{
        if(dis < o.dis) return true;
        else            return false;
    }
};
struct node g[1005000];
/*struct plz{
    int froms, gos;
}ans[100010];*/
int n, i, j, s, m, coun;
int par[100010];
/*int compare( const void * a , const void * b )
{
    struct node *p, *q;
    p = ( t *)a;
    q = ( t *)b;
    if( p -> dis > q -> dis ){
        return 1;
    }
    else{
        return -1;
    }
}*/
/*int compare1( const void * a , const void * b )
{
    struct plz *p, *q;
    p = ( struct plz *)a;
    q = ( struct plz *)b;
    if( p -> froms > q -> froms ){
        return 1;
    }
    else if( p -> froms == q -> froms ){
        if( p -> gos > q -> gos ){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}*/
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
        scanf("%d %d %d",&g[i].from,&g[i].go,&g[i].dis);
    }
    for( i = 0 ; i <= n ; i ++ ){
        par[i] = i;
    }
    sort( g , g+m );
    for( i = 0 ; i < m ; i++ ){
        int a = findroot( g[i].from );
        int b = findroot( g[i].go );
        if( a != b ){
            printf("%d %d\n",g[i].from,g[i].go);
            par[b] = a;
            coun++;
            if(coun==n-1) break;
        }
    }
   /* qsort( ans , count , sizeof( struct plz ) , compare1 );
    for( i = 0 ; i < count ; i++ ){
        printf("%d %d\n",ans[i].froms,ans[i].gos);
    }*/
    return 0;
}
