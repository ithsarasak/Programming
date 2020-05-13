#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e4 + 10;

int n, l, q, a[N], qu[110], ans[110][N];
vector<int> coord;
int main()
{
    scanf("%d %d",&n,&l);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    scanf("%d",&q);
    for( int i = 1 ; i <= q ; i++ ) {
        scanf("%d",&qu[i]);
        coord.emplace_back( qu[i] );
    }
    sort( coord.begin(), coord.end() );
    for( int d = 1 ; d <= n - l ; d++ ) {
        int p1 = 1, p2, cnt = 0;
        p2 = p1 + d;
        for( p1 = 1 ; p1 <= l ; p1++, p2++ ) {
            //printf("%d %d\n",p1,p2);
            if( a[p1] != a[p2] ) cnt++;
        }
        //printf("wtf %d %d %d\n",p1,p2,cnt);
        int idx = lower_bound( coord.begin(), coord.end(), cnt ) - coord.begin();
        ans[idx][1]++, ans[idx][1+d]++;
        while( p2 <= n ) {
            if( a[p1-l] != a[p2-l] ) cnt--;
            if( a[p1] != a[p2] ) cnt++;
            idx = lower_bound( coord.begin(), coord.end(), cnt ) - coord.begin();
            ans[idx][p1-l+1]++, ans[idx][p2-l+1]++;
            p1++, p2++;
        }
    }
    for( int i = 1 ; i < q ; i++ ) for( int j = 1 ; j <= n ; j++ ) ans[i][j] += ans[i-1][j];
    for( int i = 1 ; i <= q ; i++ ) {
        int idx = lower_bound( coord.begin(), coord.end(), qu[i] ) - coord.begin();
        for( int j = 1 ; j <= n - l + 1 ; j++ ) printf("%d ",ans[idx][j]);
        printf("\n");
    }
    return 0;
}