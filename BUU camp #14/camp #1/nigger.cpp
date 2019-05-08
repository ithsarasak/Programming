#include<bits/stdc++.h>

using namespace std;

int n, q, i, z, a, b, seg[400010], lz[400010];
int c;
void up( int l, int r, int ll, int rr, int now )
{
    if( lz[now] ){
        seg[now] = r - l + 1 - seg[now];
        if( l != r ){
            lz[now * 2] ^= 1;
            lz[now * 2 + 1] ^= 1;
        }
        lz[now] ^= 1;
    }
    if( l > rr || r < ll || l > r ){
        return ;
    }
    if( l >= ll && r <= rr ){
        seg[now] = r - l + 1 - seg[now];
        if( l != r ){
            lz[now * 2] ^= 1;
            lz[now * 2 + 1] ^= 1;
        }
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, ll, rr, now * 2 );
    up( mid + 1, r, ll, rr, now * 2 + 1 );
    seg[now] = seg[now * 2] + seg[now * 2 + 1];
    return ;
}
int query( int l, int r, int ll, int rr, int now )
{
    if( lz[now] ){
        seg[now] = r - l + 1 - seg[now];
        if( l != r ){
            lz[now * 2] ^= 1;
            lz[now * 2 + 1] ^= 1;
        }
        lz[now] ^= 1;
    }
    if( l > rr || r < ll || l > r ){
        return 0;
    }
    if( l >= ll && r <= rr ){
        return seg[now];
    }
    int mid = ( l + r ) / 2;
    int q1 = query( l , mid , ll, rr , now * 2 );
    int q2 = query( mid + 1 , r , ll, rr , now * 2 + 1 );
    seg[now] = seg[now * 2] + seg[now * 2 + 1];
    return q1 + q2;
}
int main()
{
    cin >> n >> q;
    for( int j = 0 ; j < q ; j++ ){
        scanf("%d",&c);
        if( c == 0 ){
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

