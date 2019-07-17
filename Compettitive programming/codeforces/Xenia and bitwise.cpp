#include<bits/stdc++.h>

using namespace std;
int seg[600100], num[150100];
int n, m;
void build( int l, int r, int now, int time )
{
    if( l == r ){
        //printf("%d %d %d\n",now,l,num[l]);
        seg[now] = num[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, 2*now, time - 1 );
    build( mid + 1, r, 2*now + 1, time - 1 );
    if( time % 2 ) seg[now] = seg[2*now] | seg[2*now+1];
    else seg[now] = seg[2*now] ^ seg[2*now+1];
    return ;
}
void up( int l, int r, int now, int idx, int va, int time )
{
    if( l > idx || r < idx || l > r )return ;
    if( l == r ){
        seg[now] = va;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, now * 2, idx, va, time - 1 );
    up( mid + 1, r, now * 2 + 1, idx, va, time - 1 );
    if( time % 2 )seg[now] = seg[now*2] | seg[now*2+1];
    else seg[now] = seg[now*2] ^ seg[now*2+1];
    return ;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= ( 1 << n ) ; i++ ){
        scanf("%d",&num[i]);
    }
    build( 1, (1<<n), 1, n );
    /*for( int i = 1 ; i <= ( 1 << (n + 1) ) - 1 ; i++ ){
        printf("%d ",seg[i]);
    }
    printf("\n");*/
    for( int i = 0 ; i < m ; i++ ){
        int p, b;
        scanf("%d %d",&p,&b);
        up( 1, (1<<n), 1, p, b, n );
        /*for( int i = 1 ; i <= ( 1 << (n + 1) ) - 1 ; i++ ){
            printf("%d ",seg[i]);
        }
        printf("\n");*/
        printf("%d\n",seg[1]);
    }
    return 0;
}
