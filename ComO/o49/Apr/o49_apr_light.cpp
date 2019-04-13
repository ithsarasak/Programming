#include<bits/stdc++.h>

using namespace std;
long long query[100100];
long long l, n;
long long seg[400100], lz[400100];
vector<int> coor;
void build( int l, int r, int now )
{
    if( l == r ){
        seg[now] = coor[l+1] - coor[l];
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    seg[now] = seg[now*2] + seg[now*2+1];
    return ;
}
void up( int l, int r, int ll, int rr, int now )
{
    if( lz[now] ){
        seg[now] = coor[r+1] - coor[l] - seg[now];
        if( l != r ){
            lz[now*2] ^= 1;
            lz[now*2+1] ^= 1;
        }
        lz[now] = 0;
    }
    if( l > rr || r < ll || l > r )return ;
    if( l >= ll && r <= rr ){
        seg[now] = coor[r+1] - coor[l] - seg[now];
        if( l != r ){
            lz[now*2] ^= 1;
            lz[now*2+1] ^= 1;
        }
        return ;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, ll, rr, now * 2 );
    up( mid + 1, r, ll, rr, now * 2 + 1 );
    seg[now] = seg[now*2] + seg[now*2+1];
    return ;
}
int main()
{
    scanf("%lld %lld",&l,&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&query[i]);
        query[i]++;
        coor.push_back( query[i] );
    }
    coor.push_back( 1 );
    coor.push_back( -1 );
    coor.push_back( l + 1 );
    sort( coor.begin(), coor.end() );
    for( int i = 0 ; i < n ; i++ ){
        query[i] = lower_bound( coor.begin(), coor.end(), query[i] ) - coor.begin();
    }
    int rb = lower_bound( coor.begin(), coor.end(), l ) - coor.begin();
    rb--;
    build( 1, rb, 1 );
    /*for( int i = 1 ; i <= 4*n ; i++ ){
        printf("%lld ",seg[i]);
    }
    printf("\n");
    printf("%lld\n",seg[1]);*/
    for( int i = 0 ; i < n ; i++ ){
        up( 1, rb, query[i], rb, 1 );
        printf("%lld\n",seg[1]);
    }
    return 0;
}
