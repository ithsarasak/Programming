#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int N = 1e5 + 10;

struct qq {
    int a, b, c, i;
    qq( int a, int b, int c, int i ) : a( a ), b( b ), c( c ), i( i ) {}
    friend bool operator<( const qq &a, const qq &b ) {
        return a.c > b.c;
    }
};
vector<qq> que;
vector<int> coord[N], t[N], coo;
vector<pii> sc;
int n, Q, ptr, ans[N];

void update( vector<int> &t, int idx ) {
    for( int i = idx ; i < t.size() ; i += i & -i ) t[i] += 1;
}

int query( vector<int> &t, int idx ) {
    int ret = 0;
    for( int i = idx ; i > 0 ; i -= i & -i ) ret += t[i];
    return ret;
}

int query2d( int x, int y ) {
    int ret = 0;
    for( int i = x ; i > 0 ; i -= i & -i ) {
        int idx = upper_bound( coord[i].begin(), coord[i].end(), y ) - coord[i].begin();
        int a = query( t[i], idx );
        ret += query( t[i], idx );
    }
    return ret;
}

void update2d( int x, int y ) {
    for( int i = x ; i < N ; i += i & -i ) {
        int idx = upper_bound( coord[i].begin(), coord[i].end(), y ) - coord[i].begin();
        update( t[i], idx );
    }
}

int get( int x ) { return lower_bound( coo.begin(), coo.end(), x ) - coo.begin() + 1; }
int main()
{
    scanf("%d %d",&n,&Q);
    for( int i = 0, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        sc.emplace_back( pii( a, b ) ), coo.emplace_back( a );
    }
    sort( coo.begin(), coo.end() );
    coo.resize( unique( coo.begin(), coo.end() ) - coo.begin() );
    for( pii x : sc ) {
        int idx = get( x.x );
        for( int i = idx ; i < N ; i += i & -i ) {
            coord[i].emplace_back( x.y );
        }
    }
    for( int i = 1 ; i < N ; i++ ) {
        sort( coord[i].begin(), coord[i].end() );
        coord[i].resize( unique( coord[i].begin(), coord[i].end() ) - coord[i].begin() );
        t[i].resize( coord[i].size() + 5 );
    }
    sort( sc.begin(), sc.end(), [&](pii &a, pii &b) {
        return a.x + a.y > b.x + b.y;
    });
    for( int i = 0, a, b, c ; i < Q ; i++ ) {
        scanf("%d %d %d",&a,&b,&c);
        que.emplace_back( a, b, c, i );
    }
    sort( que.begin(), que.end() );
    for( qq q : que ) {
        while( ptr < sc.size() && sc[ptr].x + sc[ptr].y >= q.c ) {
            update2d( get( sc[ptr].x ), sc[ptr].y );
            ptr++;
        }
        ans[q.i] = query2d( coo.size(), 1e9 ) - query2d( coo.size(), q.b-1 ) - query2d( get( q.a ) - 1, 1e9 ) + query2d( get( q.a )-1, q.b-1 );
    }
    for( int i = 0 ; i < Q ; i++ ) printf("%d\n",ans[i]);
    return 0;
}