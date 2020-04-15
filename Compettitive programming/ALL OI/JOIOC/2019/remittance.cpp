#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
long long a[N], b[N];
int n;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) scanf("%lld %lld",&a[i],&b[i]);
    for( int j = 1 ; j <= 31 ; j++ ) {
        for( int i = 0 ; i < n ; i++ ) {
            int nxt = ( i + 1 ) % n;
            if( a[i] - b[i] >= 2 ) {
                int d = ( a[i] - b[i] ) / 2;
                a[i] -= 2*d;
                a[nxt] += d;
            }
            else if( a[i] - b[i] == 1 && a[i] > 1 ) {
                a[i] -= 2;
                a[nxt] += 1;
            }
        }
    }
    for( int i = 0 ; i < n ; i++ ) if( a[i] ^ b[i] ) return !printf("No");
    printf("Yes");
    return 0;
}