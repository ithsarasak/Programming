#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

int n, k, q, base[N];

struct node{
    set<pii> L, R;
    int posl[60], posr[60], mi = 1e9;
}seg[4*N];

int cal( int now, int mid ) {
    set<pii>::iterator it;
    set<pii>::reverse_iterator rit;
    int mx = mid, mi = mid + 1, ret = 1e9;
    for( int i = 1 ; i <= k ; i++ ) {
        if( seg[now<<1].posl[i] == 1e9 ) mx = max( mx, seg[now<<1|1].posl[i] );
        if( seg[now<<1|1].posr[i] == -1 ) mi = min( mi, seg[now<<1].posr[i] );
    }
    for( rit = seg[now<<1|1].L.rbegin() ; rit != seg[now<<1|1].L.rend() ; rit++ ) {
        ret = min( ret, ( *rit ).x - mi + 1 );
        if( seg[now<<1].posr[( *rit ).y] == -1 ) break;
        mi = min( mi, seg[now<<1].posr[( *rit ).y] );
    }
    for( it = seg[now<<1].R.begin() ; it != seg[now<<1].R.end() ; it++ ) {
        ret = min( ret, mx - ( *it ).x + 1 );
        if( seg[now<<1|1].posl[( *it ).y] == 1e9 ) break;
        mx = max( mx, seg[now<<1|1].posr[( *it ).y] );
    }
    return ret;
}

void update( int idx, int va, int l = 1, int r = n, int now = 1 ) {
    if( l > idx || r < idx || l > r ) return ;
    if( l == r ) {
        seg[now].L.clear(), seg[now].R.clear();
        seg[now].posl[base[idx]] = 1e9, seg[now].posr[base[idx]] = -1;
        seg[now].posl[va] = seg[now].posr[va] = idx;
        seg[now].L.insert( pii( idx, va ) ), seg[now].R.insert( pii( idx, va ) );
        return ;
    }
    int mid = ( l + r ) >> 1;
    update( idx, va, l, mid, now << 1 ), update( idx, va, mid + 1, r, now << 1 | 1 );
    set<pii>::iterator it;
    it = seg[now].L.find( pii( seg[now].posl[base[idx]], base[idx] ) );
    if( it != seg[now].L.end() ) seg[now].L.erase( it );
    it = seg[now].R.find( pii( seg[now].posr[base[idx]], base[idx] ) ); 
    if( it != seg[now].R.end() ) seg[now].R.erase( it );
    it = seg[now].L.find( pii( seg[now].posl[va], va ) ); 
    if( it != seg[now].L.end() ) seg[now].L.erase( it );
    it = seg[now].R.find( pii( seg[now].posr[va], va ) ); 
    if( it != seg[now].R.end() ) seg[now].R.erase( it );
    for( int i = 1 ; i <= k ; i++ ) {
        seg[now].posl[i] = seg[now<<1].posl[i] == 1e9 ? seg[now<<1|1].posl[i] : seg[now<<1].posl[i];
        seg[now].posr[i] = seg[now<<1|1].posr[i] == -1 ? seg[now<<1].posr[i] : seg[now<<1|1].posr[i];
    } 
    if( seg[now].posr[base[idx]] != -1 ) seg[now].L.insert( pii( seg[now].posl[base[idx]], base[idx] ) ), seg[now].R.insert( pii( seg[now].posr[base[idx]], base[idx] ) );
    if( seg[now].posr[va] != -1 ) seg[now].L.insert( make_pair( seg[now].posl[va], va ) ), seg[now].R.insert( make_pair( seg[now].posr[va], va ) );
    int cc = 0;
    for( int i = 1 ; i <= k ; i++ ) if( seg[now].posl[i] == 1e9 || seg[now].posr[i] == -1 ) cc = 1;
    if( !cc ) seg[now].mi = min( seg[now<<1].mi, min( seg[now<<1|1].mi, cal( now, mid ) ) );
    else seg[now].mi = 1e9;
    return ;
}

void build( int l = 1, int r = n, int now = 1 ) {
    if( l == r ) {
        fill( seg[now].posl, seg[now].posl + 55, 1e9 );
        fill( seg[now].posr, seg[now].posr + 55, -1 );
        seg[now].posl[base[l]] = seg[now].posr[base[l]] = l;
        seg[now].L.insert( pii( l, base[l] ) ), seg[now].R.insert( pii( l, base[l] ) );
        return ;
    }
    int mid = ( l + r ) >> 1;
    build( l, mid, now << 1 ), build( mid + 1, r, now << 1 | 1 );
    int cc = 0;
    for( int i = 1 ; i <= k ; i++ ) {
        seg[now].posl[i] = seg[now<<1].posl[i] == 1e9 ? seg[now<<1|1].posl[i] : seg[now<<1].posl[i];
        seg[now].posr[i] = seg[now<<1|1].posr[i] == -1 ? seg[now<<1].posr[i] : seg[now<<1|1].posr[i];
        if( seg[now].posl[i] != 1e9 && seg[now].posr[i] != -1 ) seg[now].L.insert( pii( seg[now].posl[i], i ) ), seg[now].R.insert( pii( seg[now].posr[i], i ) );
        else cc = 1;
    }
    if( !cc ) seg[now].mi = min( seg[now<<1].mi, min( seg[now<<1|1].mi, cal( now, mid ) ) );
    else seg[now].mi = 1e9;
    return ;
}

int main()
{
    scanf("%d %d %d",&n,&k,&q);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&base[i]);
    build();
    while( q-- ) {
        int op, a, b;
        scanf("%d",&op);
        if( op == 1 ) {
            scanf("%d %d",&a,&b);
            update( a, b );
            base[a] = b;
        }
        else printf("%d\n",seg[1].mi == 1e9 ? -1 : seg[1].mi);
    }
    return 0;
}