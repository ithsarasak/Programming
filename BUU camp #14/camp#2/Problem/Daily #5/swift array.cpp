#include<bits/stdc++.h>

using namespace std;

int n, q, i, z, a, b, seg[1000000];
char c;
void up( int l, int r, int idx, int val, int now )
{
    if( l > idx || r < idx ){
        return ;
    }
    if( l == r ){
        seg[now] = val;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, val, now * 2 );
    up( mid + 1, r, idx, val, now * 2 + 1 );
    seg[now] = max( seg[now * 2], seg[now * 2 + 1] );
    return ;
}
int query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r ){
        return -1e9;
    }
    if( l >= ll && r <= rr ){
        return seg[now];
    }
    int mid = ( l + r ) / 2;
    return max( query( l, mid, ll, rr, now * 2 ) , query( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int main()
{
    scanf("%d %d",&n,&q);
    for( int j = 0 ; j < q ; j++ ){
        scanf(" %c",&c);
        if( c == 'U' ){
            scanf("%d %d",&i,&z);
            up( 1, n, i, z, 1 );
        }
        else{
            scanf("%d %d",&a,&b);
            printf("%d\n",query( 1 , n , a , b , 1 ) );
        }
    }
    return 0;
}

