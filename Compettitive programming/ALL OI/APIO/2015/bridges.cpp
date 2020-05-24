#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;
 
const int N = 1e5 + 10;
int k, n;
long long ans, dpl[N], dpr[N], suml, sumr;
vector<pii> v;
priority_queue<long long> L;
priority_queue<long long, vector<long long>, greater<long long>> R;
void add( long long x ) {
    int sz = L.size() + R.size();
    if( L.empty() || x <= L.top() ) {
        //printf("L : %d\n",x);
        L.emplace( x );
        suml += x, sz++;
        while( L.size() > ( sz+1 ) / 2 ) {
            //printf("sz1 : %d %lld\n",sz,L.top());
            R.emplace( L.top() );
            sumr += L.top();
            suml -= L.top();
            L.pop();
        }
    }
    else {
        //printf("R : %d\n",x);
        R.emplace( x );
        sumr += x, sz++;
        while( R.size() > ( sz+1 ) / 2 ) {
            //printf("sz2 : %d %lld\n",sz,R.top());
            L.emplace( R.top() );
            sumr -= R.top();
            suml += R.top();
            R.pop();
        }
    }
}

long long process( int idx ) {
    //printf("IDX : %d %lld %lld\n",idx,v[idx].x,v[idx].y);
    add( v[idx].x ), add( v[idx].y );
    int sz = L.size() + R.size();
    //printf("L : %d %lld %lld R : %d %lld %lld\n",L.size(),L.top(),suml,R.size(),R.top(),sumr);
    long long median = L.size() == ( sz + 1 ) / 2 ? L.top() : R.top();
    //printf("%d %d %lld\n",sz,idx,median);
    return median * ( L.size() - R.size() ) - suml + sumr;
}

int main()
{
    scanf("%d %d",&k,&n);
    for( int i = 1 ; i <= n ; i++ ) {
        char a, c;
        long long b, d;
        scanf(" %c %lld %c %lld",&a,&b,&c,&d);
        if( b > d ) swap( b, d );
        if( a == c ) ans += d - b;
        else v.emplace_back( pii( b, d ) );
    }
    if( v.empty() ) return !printf("%lld",ans);
    ans += v.size();
    sort( v.begin(), v.end(), [&]( const pii &a, const pii &b ) {
        return a.x + a.y < b.x + b.y;
    });
    for( int i = 1 ; i <= v.size() ; i++ ) dpl[i] = process( i-1 );
    L = priority_queue<long long>();
    R = priority_queue<long long, vector<long long>, greater<long long>>();
    suml = sumr = 0LL;
    for( int i = v.size() ; i >= 1 ; i-- ) dpr[i] = process( i-1 );
    if( k == 1 ) return !printf("%lld",ans+dpl[v.size()]);
    long long tmp = 2e18;
    for( int i = 1 ; i < v.size() ; i++ ) tmp = min( tmp, dpl[i] + dpr[i+1] );
    printf("%lld",ans+tmp);
    return 0;
}