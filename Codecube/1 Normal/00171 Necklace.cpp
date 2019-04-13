#include<bits/stdc++.h>

using namespace std;

int n, i, len, j;
const int inf = 2000000000;
char op[400010];
int seg[1600010];
int sum[400010];
void build( int l, int r, int now )
{
    if( l == r ){
        seg[now] = inf;
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    seg[now] = inf;
}
void up( int l, int r, int val, int idx, int now )
{
    if( l > idx || r < idx ) return ;
    if( l == r ){
        seg[now] = val;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, val, idx, now * 2 );
    up( mid + 1, r, val, idx, now * 2 + 1 );
    seg[now] = min( seg[now * 2], seg[now * 2 + 1] );
    return ;
}
int query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll )return inf;
    if( l >= ll && r <= rr ) return seg[now];
    int mid = ( l + r ) / 2;
    return min( query( l, mid, ll, rr, now * 2 ) , query( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int main()
{
    scanf("%s",&op[1]);
    scanf("%d",&n);
    len = strlen( &op[1] );
    for( int i = len + 1 ; i <= 2*len ; i++ ){
        op[i] = op[i-len];
    }
    for( int i = 1 ; i <= 2*len ; i++ ){
        if( op[i] == '(' ){
            sum[i] = sum[i-1] + 1;
        }
        else sum[i] = sum[i-1] - 1;
        up( 1, 2 * len, sum[i], i, 1 );
    }
    for( int i = 0 ; i < n ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        if( t < f ){
            t += len;
        }
        int mi = query( 1, 2*len, f, t, 1 );
        //printf("%d %d\n",sum[f],sum[t]);
        if( mi < sum[f-1] || sum[f-1] != sum[t] ){
            printf("no\n");
        }
        else{
            printf("yes\n");
        }
    }
    return 0;
}

