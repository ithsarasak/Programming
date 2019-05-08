#include <bits/stdc++.h>
#include "wall.h"

using namespace std;

const int N = 1 << 21;
const int inf = 2e9;
int lo[N<<1], hi[N<<1], ret[N], n, k;

void push( int now, int l, int r ) {
    if( l == r ) ret[l] = min( hi[now], max( lo[now], ret[l] ) );
    else {
		hi[now<<1] = max( lo[now], min( hi[now], hi[now<<1] ) ), lo[now<<1] = min( hi[now], max( lo[now], lo[now<<1] ) );
		hi[now<<1|1] = max( lo[now], min( hi[now], hi[now<<1|1] ) ), lo[now<<1|1] = min( hi[now], max( lo[now], lo[now<<1|1] ) );
	}
    //printf("%d %d %d\n",now,l,r);
	lo[now] = 0, hi[now] = inf;
    return ;
}

void update( int ll, int rr, int f, int t, int l = 1, int r = n, int now = 1 ) {
    push( now, l, r );
    if( l > rr || r < ll || l > r ) return ;
    if( l >= ll && r <= rr ) {
        //printf("hi %d lo %d\n",hi[now],lo[now]);
        hi[now] = max( f, min( hi[now], t ) ), lo[now] = min( t, max( lo[now], f ) );
        //printf("l : %d r : %d f : %d t : %d ll : %d rr : %d hi %d lo %d\n",l,r,f,t,ll,rr,hi[now],lo[now]);
        return ;
    }
    
    int mid = ( l + r ) >> 1;
    update( ll, rr, f, t, l, mid, now << 1 ), update( ll, rr, f, t, mid + 1, r, now << 1 | 1 );
    return ;
}

void computeans( int l = 1, int r = n, int now = 1 ) {
    push( now, l, r );
    if( l == r ) return ;
    int mid = ( l + r ) >> 1;
    computeans( l, mid, now << 1 ), computeans( mid + 1, r, now << 1 | 1 );
    return ;
}

void buildWall( int N, int k, int op[], int left[], int right[], int height[], int finalheight[] ) 
{  
    n = N;
    fill( hi, hi + 2*N, inf );
    for( int i = 0 ; i < k ; i++ ) {
        if( op[i] == 1 ) update( left[i] + 1, right[i] + 1, height[i], inf );
        else update( left[i] + 1, right[i] + 1, 0, height[i] );
    }
    computeans();
    for( int i = 1 ; i <= n ; i++ ) finalheight[i-1] = ret[i];
    return ;
}

// #define LOCAL_TEST 0

#ifdef LOCAL_TEST
int main() 
{

    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < k ; i++ ) {
        int op, l, r, h;
        scanf("%d %d %d %d",&op,&l,&r,&h);
        if( op == 1 ) update( l + 1, r + 1, h, inf );
        else update( l + 1, r + 1, 0, h );
        if( i == k - 4 ) {
            computeans();
        for( int i = 1 ; i <= n ; i++ ) printf("%d ",ret[i]);
        cout << endl;
        }
    }
    computeans();
    for( int i = 1 ; i <= n ; i++ ) printf("%d ",ret[i]);
    cout << endl;
    return 0;
}
#endif