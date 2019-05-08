#include<bits/stdc++.h>

using namespace std;

int n, q, i, z, a, b, segmin[800010], segmax[800010], height[200010], bucket[200010];
int c;
void build( int l, int r , int now )
{
    if( l == r ){
        segmin[now] = bucket[l];
        segmax[now] = bucket[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    segmin[now] = min( segmin[now * 2], segmin[now * 2 + 1] );
    segmax[now] = max( segmax[now * 2], segmax[now * 2 + 1] );
}
void up( int l, int r, int idx, int val, int now )
{
    if( l > idx || r < idx || l > r ){
        return ;
    }
    if( l == r ){
        segmin[now] = val;
        segmax[now] = val;
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, val, now * 2 );
    up( mid + 1, r, idx, val, now * 2 + 1 );
    segmax[now] = max( segmax[now * 2], segmax[now * 2 + 1] );
    segmin[now] = min( segmin[now * 2], segmin[now * 2 + 1] );
    return ;
}
int qmax( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r ){
        return -1e9;
    }
    if( l >= ll && r <= rr ){
        return segmax[now];
    }
    int mid = ( l + r ) / 2;
    return max( qmax( l, mid, ll, rr, now * 2 ) , qmax( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int qmin( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r ){
        return 1e9;
    }
    if( l >= ll && r <= rr ){
        return segmin[now];
    }
    int mid = ( l + r ) / 2;
    return min( qmin( l, mid, ll, rr, now * 2 ) , qmin( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int main()
{
    cin >> n >> q;
    for( int j = 1 ; j <= n ; j++ ){
        scanf("%d",&height[j]);
        bucket[height[j]] = j;
    }
    build( 1 , n , 1 );
    for( int j = 1 ; j <= q ; j++ ){
        scanf("%d",&c);
        if( c == 1 ){
            scanf("%d %d",&i,&z);
            up( 1, n, height[i], z, 1 );
            up( 1, n, height[z], i, 1 );
            swap( height[i], height[z] );
        }
        else{
            scanf("%d %d",&a,&b);
            if( b - a  == qmax( 1, n, a, b, 1 ) - qmin( 1, n, a, b, 1 ) ){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}

