#include <bits/stdc++.h>
#include "holiday.h"
using namespace std;
//#define fuck 
const int N = 1e5 + 10;
struct item{
    long long va;
    int sz, l, r;
}seg[20*N];

int ver[N], cnt = 1;
unordered_map<long long, int> mp;
long long va[N], ans = -1LL;
int n, s, d;

vector<long long> coord;
int newleaf( long long va, int sz ) {
    seg[cnt].va = va, seg[cnt].sz = sz, seg[cnt].l = -1, seg[cnt].r = -1;
    cnt++;
    return cnt - 1;
}

int newpar( int l, int r ) {
    seg[cnt].va = seg[l].va + seg[r].va, seg[cnt].sz = seg[l].sz + seg[r].sz, seg[cnt].l = l, seg[cnt].r = r;
    cnt++;
    return cnt - 1;
}

int build( int l = 1, int r = n ) {
    if( l == r ) return newleaf( 0, 0 );
    int mid = ( l + r ) >> 1;
    return newpar( build( l, mid ), build( mid + 1, r ) );
}

int update( int idx, long long va, int now, int l = 1, int r = n ) {
    //printf("now : %d\n",now);
    if( l == r ) return newleaf( va, 1 );
    int mid = ( l + r ) >> 1;
    if( idx <= mid ) return newpar( update( idx, va, seg[now].l, l, mid ), seg[now].r );
    else return newpar( seg[now].l, update( idx, va, seg[now].r, mid + 1, r ) );
}

long long query( int a, int b, int idx, int l = 1, int r = n ) {
    //printf("%d %d %d %d\n",l,r,a,b);
    if( idx <= 0 ) return 0LL;
    if( l == r ) return seg[b].va - seg[a].va;
    int mid = ( l + r ) >> 1;
    int diff = seg[seg[b].r].sz - seg[seg[a].r].sz;
    if( diff >= idx ) return query( seg[a].r, seg[b].r, idx, mid + 1, r );
    else return seg[seg[b].r].va - seg[seg[a].r].va + query( seg[a].l, seg[b].l, idx - diff, l, mid );
}

int cal( int l, int r ) {
    int ret = r - l;
    int x = abs( s - l ), y = abs( s - r );
    return ret + min( x, y );
}

int get( long long x ) { 
    mp[x]++;
    return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + mp[x]; 
} 

void solve( int l, int r, int lb, int rb ) {
    if( l > r ) return ;
    int mid = ( l + r ) >> 1;
    long long nowans = -1LL, ind = lb;
    for( int i = max( lb, mid ) ; i <=  min( mid + d -1, rb ) ; i++ ) {
        int cos = cal( mid, i );
        if( d - cos - 2 < 0 ) continue;
        long long temp = query( ver[mid], ver[i-1], d - cos - 2 );
        long long temp2 = va[mid] + ( ( i == mid ) ? 0 : va[i] );
        //printf("temp %lld temp2 %lld mid %d i %d cos %d\n",temp,temp2,mid,i,cos);
        temp += temp2;
        if( temp > nowans ) ind = i, nowans = temp;
    }
    ans = max( ans, nowans );
    solve( l, mid - 1, lb, ind );
    solve( mid + 1, r, ind, rb );
}

long long findMaxAttraction( int N, int ST, int D, int ttt[] ) {
    s = ST + 1, d = D, n = N;
    for( int i = 0 ; i < n ; i++ ) { 
        va[i+1] = ( long long )ttt[i];
        coord.emplace_back( ttt[i] );
    }
    sort( coord.begin(), coord.end() );
    build();
    ver[0] = cnt - 1;
    for( int i = 1 ; i <= n ; i++ ) {
        update( get( va[i] ), va[i], ver[i-1] );
        ver[i] = cnt - 1;
        //printf("ver : %d\n",ver[i]);
    }
    //for( int i = 0 ; i <= n ; i++ ) printf("%d ",ver[i]);
    //printf("\n");
    for( int i = max( 1, s - d + 1 ) ; i <= min( n, s + d - 1 ) ; i++ ) ans = max( ans, va[i]);
    solve( max( 1, s - d + 1 ), min( n, s + d - 1 ), 1, n );
    return ans;
}

#ifdef fuck
int main()
{
    int n, va[100], st, d;
    scanf("%d %d %d",&n,&st,&d);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&va[i]);
    cout << findMaxAttraction( n, st, d, va );
}
#endif