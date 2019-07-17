#include<bits/stdc++.h>

using namespace std;
struct ed{
    int f, t, d;
    bool operator<( const ed &k )const{
        return d < k.d;
    }
}alled[50010];
struct cheat{
    int f, t;
}cheater[50010];
int par[40010];
int n, m, p, c, ans = -1;
int root(int i)
{
    while(i!=par[par[i]])
    {
        par[i]=par[par[i]];
        i=par[par[i]];
    }
    return i;
}
void mergeset(int a,int b)
{
    par[root(b)]=root(a);
}
int mst( int mid )
{
    //printf("%d\n",mid);
    for( int i = 1 ; i <= n ; i++ ){
        par[i] = i;
    }
    for( int i = 0 ; i < m ; i++ ){
        //printf("%d\n",alled[i].d);
        if( alled[i].d >= mid ){
            break;
        }
        mergeset( alled[i].f , alled[i].t );
    }
    int ch = 1;
    for( int i = 0 ; i < p ; i++ ){
        if( root( cheater[i].f ) == root( cheater[i].t ) ){
            ch = 0;
            break;
        }
    }
    /*for( int i = 1 ; i <= n ;i++ ){
        printf("%d ",par[i]);
    }
    printf("\n");*/
    return ch;
}
int main()
{
    scanf("%d %d %d",&n,&m,&p);
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d %d",&alled[i].f,&alled[i].t,&alled[i].d);
    }
    sort( alled , alled + m );
    for( int i = 0 ; i < p ; i++ ){
        scanf("%d %d",&cheater[i].f,&cheater[i].t);
    }
    if( mst( 1e9 + 10 ) ){
        printf("-1");
        return 0;
    }
    int l = 1, r = 1e9 + 10;
    while( l <= r ){
        int mid = ( l + r ) / 2;
        if( !mst( mid ) ){
            r = mid - 1;
        }
        else{
            ans = max( ans , mid );
            l = mid + 1;
        }
    }
    printf("%d",ans);
    return 0;
}
/*
5 6 1
1 2 7
1 3 7
1 4 7
2 5 4
3 5 3
4 5 5
1 5
*/
