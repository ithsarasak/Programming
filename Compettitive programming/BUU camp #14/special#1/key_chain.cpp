#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, k, key[N], door[N], now = 0;
long long ans, loop;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ) {
        scanf("%d",&key[i]);
        key[i]--;
        door[key[i]] = i;
    }
    for( int i = 0 ; i < min( n, k ) ; i++ ) {
        int times = ( door[i] - now + n + 1 ) % n;
        if( times == 0 ) times = n;
        times--;
        //cout << times << endl;
        ans += ( long long )times;
        now = door[i];
    }
    if( k <= n ) {
        printf("%lld",ans);
        return 0;
    } 
    k -= n;
    for( int i = 0 ; i < min( n, k ) ; i++ ) {
        int times = ( door[i] - now + n + 1 ) % n;
        if( times == 0 ) times = n;
        times--;
        //cout << times << endl;
        ans += ( long long )times;
        loop += ( long long )times;
        now = door[i];
    }
    if( k <= n ) {
        printf("%lld",ans);
        return 0;
    } 
    k -= n;
    ans += ( long long )( k / n ) * loop;
    k %= n;
    for( int i = 0 ; i < min( n, k ) ; i++ ) {
        int times = ( door[i] - now + n + 1 ) % n;
        if( times == 0 ) times = n;
        times--;
        //cout << times << endl;
        ans += ( long long )times;
        now = door[i];
    }
    printf("%lld",ans);
    return 0;
}