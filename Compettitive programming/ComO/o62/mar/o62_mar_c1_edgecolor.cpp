#include <bits/stdc++.h>
#define iii tuple<int, int, int, int>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 3e5 + 10;
stack<iii> stk;
vector<pii> seg[8*N];
int dsu[N], len[N], n, m, ans;

void recall( int ver ) {
    while( stk.size() > ver ) {
        int a, b, c, d;
        tie( a, b, c, d ) = stk.top(); stk.pop();
        ans = d, dsu[a] = b, len[a] = c;
    }
}

int find( int now ) { return dsu[now] < 0 ? now : find( dsu[now] ); }

void mer( int a, int b ) {
    a = find( a ), b = find( b );
    if( abs( dsu[a] ) < abs( dsu[b] ) ) swap( a, b );
    //printf("%d %d\n",a,b);
    if( a == b ) {
        stk.emplace( tie( a, dsu[a], len[a], ans ) );
        len[a]++;
        //printf("%d %d\n",a,len[a]);
        if( len[a] % 2 ) ans = 1;
        return ;
    }
    stk.emplace( tie( a, dsu[a], len[a], ans ) ), stk.emplace( tie( b, dsu[b], len[b], ans ) );
    dsu[a] += dsu[b], dsu[b] = a, len[a] += len[b] + 1;
    return ;
}

void solve( int l = 1, int r = m, int now = 1 ) {
    //printf("l : %d r : %d\n",l,r);
    int ver = stk.size();
    for( pii i : seg[now] ) {
        //printf("u : %d v : %d\n",i.x,i.y);
        mer( i.x, i.y );
    }
    if( l == r ) {
        //printf("%d ",l);
        if( ans ) printf("no\n");
        else printf("yes\n");
        recall( ver );
        return ;
    } 
    int mid = ( l + r ) >> 1;
    solve( l, mid, now << 1 ), solve( mid + 1, r, now << 1 | 1 );
    recall( ver );
    return ;
}

void update( int ll, int rr, pii va, int l = 1, int r = m, int now = 1 ) {
    
    if( l > rr || r < ll ) return ;
    //printf("ll : %d rr : %d l : %d r : %d\n",ll,rr,l,r);
    if( l >= ll && r <= rr ) return void ( seg[now].emplace_back( va ) );
    int mid = ( l + r ) >> 1;
    update( ll, rr, va, l, mid, now << 1 ), update( ll, rr, va, mid + 1, r, now << 1 | 1 );
    return ;
}

struct coorh {
  size_t operator()(const pii &a) const {
    return a.x + a.y;
  }
};

unordered_map<pii, int, coorh> mp;
int main()
{
    memset( dsu, -1, sizeof dsu );
    scanf("%d %d",&n,&m);
    for( int i = 1, c, a, b ; i <= m ; i++ ) {
        scanf("%d %d %d",&c,&a,&b);
        if( a > b ) swap( a, b );
        if( c ) mp[pii( a, b )] = i;
        else {
            //printf("wtf %d %d %d\n",a,b,mp[pii(a,b)]);
            update( mp[pii( a, b )], i - 1, pii( a, b ) );
            mp[pii( a, b )] = 0;
        }
    }
    //printf("\n");
    for( auto i : mp ) {
        //printf("%d %d %d\n",i.x.x,i.x.y,i.y);
        if( i.y != 0 ) update( i.y, m, i.x );
    }
    solve();
    return 0;
}