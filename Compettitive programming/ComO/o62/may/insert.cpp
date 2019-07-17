#include <bits/stdc++.h>
#define pil pair<int, long long>
#define x first
#define y second 

using namespace std;

const int N = 4e5 + 10;
int n;
long long a[N], sum[N], suf, ans;
char s[N];
vector<int> pos;
vector<pil> cal;
int main()
{
    scanf("%d",&n);
    pos.emplace_back( 0 );
    for( int i = 1 ; i <= 2*n - 1 ; i++ ) {
        if( i % 2 ) scanf("%lld",&a[i]);
        else {
            scanf(" %c",&s[i]);
            if( s[i] == '-' ) pos.emplace_back( i );
        }
    }
    pos.emplace_back( 2*n );
    // for( int i : pos ) cout << i << " ";
    // cout << endl;
    sum[1] = a[1];
    for( int i = 2 ; i <= 2*n - 1 ; i++ ) sum[i] = sum[i-1] + ( s[i-1] == '+' ? 1 : -1 ) * a[i];
    // for( int i = 1 ; i <= 2*n - 1 ; i++ ) cout << sum[i] << " ";
    // cout << endl;
    cal.emplace_back( pil( pos[0] + 1, sum[pos[1]-1] - sum[pos[0]] ) );
    for( int i = 2 ; i <= ( int )pos.size() - 1 ; i++ ) cal.emplace_back( pil( pos[i-1] + 1, sum[pos[i]-1] - sum[pos[i-1]] + 2 * a[pos[i-1]+1] ) );
    //for( pil i : cal ) cout << i.x << " " << i.y << endl;
    ans = sum[2*n-1];
    for( int i = ( int )cal.size() - 1 ; i >= 1 ; i-- ) {
        long long temp = sum[cal[i].x-1] - cal[i].y + suf;
        //printf("%d %lld %lld %lld %lld\n",cal[i].x,sum[cal[i].x-1],cal[i].y,suf,temp);
        ans = max( ans, temp );
        suf += cal[i].y;
    }
    printf("%lld",ans);
    return 0;
}