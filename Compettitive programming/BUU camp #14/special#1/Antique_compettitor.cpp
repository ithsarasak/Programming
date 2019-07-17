#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node {
    int l, r, num;
    bool operator<( const node &k ) const{
        return r < k.r;
    }
};
vector<node> block[320];
int n, k, q, num[N], cnt[N], ans[N];
int main()
{
    scanf("%d %d %d",&n,&k,&q);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&num[i]);
    for( int i = 1, a, b ; i <= q ; i++ ) {
        scanf("%d %d",&a,&b);
        a--, b--;
        block[a/317].push_back({ a, b, i });
    }
    for( int i = 0 ; i < 320 ; i++ ) {
        if( !(int)( block[i].size() ) ) continue;
        sort( block[i].begin(), block[i].end() );
        int l, r, c = 0;
        for( int j = block[i][0].l ; j <= block[i][0].r ; j++ ) {
            cnt[num[j]]++;
            if( cnt[num[j]] == k ) c++;
        }
        l = block[i][0].l, r = block[i][0].r;
        ans[block[i][0].num] = c;
        for( int j = 1 ; j < block[i].size() ; j++ ){
            while( l < block[i][j].l ) {
                cnt[num[l]]--;
                if( cnt[num[l]] == k - 1 ) c--;
                l++;
            }
            while( l > block[i][j].l ) {
                l--;
                cnt[num[l]]++;
                if( cnt[num[l]] == k ) c++;
            }
            while( r < block[i][j].r ) {
                r++;
                cnt[num[r]]++;
                if( cnt[num[r]] == k ) c++;
            }
            ans[block[i][j].num] = c;
        }
        memset( cnt, 0, sizeof cnt );
    }
    for( int i = 1 ; i <= q ; i++ ) printf("%d\n",ans[i]);
    return 0;
}