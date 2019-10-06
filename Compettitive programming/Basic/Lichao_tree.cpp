#include<bits/stdc++.h>
#define pll pair<long long, long long>
#define m first
#define c second

using namespace std;

pll seg[4*N];


long long get( pll a, long long x ) { return a.m * x + a.c; } 
void update( int s, pll li, int l = 1, int r = N - 9, int now = 1 ) {
    if( s != chk[now] ) {
        chk[now] = s, seg[now] = li;
        return ;
    }
    if( get( li, l ) >= get( seg[now], l ) && get( li, r ) >= get( seg[now], l ) ) return ;
    else if( get( li, l ) <= get( seg[now], l ) && get( li, r ) <= get( seg[now], r ) ) return void( seg[now] = li );
    if( l == r ) return ;
    if( get( li, l ) < get( seg[now], l ) ) swap( seg[now], li );
    int mid = l + r >> 1;
    if( get( li, mid ) < get( seg[now], mid ) ) swap( seg[now], li ), update( s, li, l, mid, now << 1 );
    else update( s, li, mid + 1, r, now << 1 | 1 );
}

long long query( int idx, int s, int l = 1, int r = N - 9, int now = 1 ) {
    if( s != chk[now] ) return 1e18;
    if( l == r ) return get( seg[now], idx );
    int mid = l + r >> 1;
    if( idx <= mid ) return min( get( seg[now], idx ), query( idx, s, l, mid, now << 1 ) );
    else return min( get( seg[now], idx ), query( idx, s, mid + 1, r, now << 1 | 1 ) );
}

int main()
{

}