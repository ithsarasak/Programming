#include <bits/stdc++.h>

using namespace std;

struct bb {
    int l, r, i;
    bool operator<( const bb &k ) const {
        return r < k.r;
    }
};
vector<bb> block[285];
int n, t, cnt[1000010];
long long p, num[80010], ans[50010];
vector<long long> pre[1000010];

long long power( long long base, int po ) {
    long long ret = 1;
    for( ; po ; po >>= 1 ) {
        if( po & 1 ) ret =( ret * base ) % p;
        base = ( base * base ) % p;;
    }
    return ret;
}

int main()
{
    for( int i = 0 ; i <= 1000000 ; i++ ) pre[i].emplace_back( 0 );
    scanf("%d %d %lld",&n,&t,&p);
    for( int i = 0 ; i < n ; i++ ) {
        scanf("%lld",&num[i]);
        int x = pre[num[i]].size();
        long long temp = ( ( long long )x * power( num[i], x ) ) % p;
        pre[num[i]].emplace_back( temp );
    }
    for( int i = 0, a, b ; i < t ; i++ ) {
        scanf("%d %d",&a,&b);
        a--, b--;
        block[a/283].push_back({ a, b, i });
    }
    for( int i = 0 ; i < 283 ; i++ ) {
        if( block[i].size() == 0 ) continue ;
        sort( block[i].begin(), block[i].end() );
        int l, r;
        long long sum = 0;
        memset( cnt, 0, sizeof cnt );
        for( int j = block[i][0].l ; j <= block[i][0].r ; j++ ) {
            long long x = num[j];
            sum = ( sum - pre[x][cnt[x]] + pre[x][cnt[x]+1] + p ) % p;
            cnt[x]++;
        } 
        l = block[i][0].l, r = block[i][0].r;
        ans[block[i][0].i] = sum;
        for( int j = 1 ; j < block[i].size() ; j++ ) {
            while( l < block[i][j].l ) {
                long long x = num[l];
                sum = ( sum - pre[x][cnt[x]] + pre[x][cnt[x]-1] + p ) % p;
                cnt[x]--;
                l++;
            }
            while( l > block[i][j].l ) {
                l--;
                long long x = num[l];
                sum = ( sum - pre[x][cnt[x]] + pre[x][cnt[x]+1] + p ) % p;
                cnt[x]++;
            }
            while( r < block[i][j].r ) {
                r++;
                long long x = num[r];
                sum = ( sum - pre[x][cnt[x]] + pre[x][cnt[x]+1] + p ) % p;
                cnt[x]++;
            }
            ans[block[i][j].i] = sum;
        }
    }
    for( int i = 0 ; i < t ; i++ ) printf("%lld\n",ans[i]);
    return 0;
}