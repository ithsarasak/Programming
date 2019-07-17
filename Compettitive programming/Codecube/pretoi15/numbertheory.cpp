 #include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const long long base = 1e9 + 7;
long long has[N], po[N], a[N], b[N], yes;
vector<int> pos;
int m, n, cnt;
int main()
{
    po[0] = 1;
    for( int i = 1 ; i <= 200000 ; i++ ) po[i] = po[i-1] * base;
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&a[i]);
    for( int i = 1 ; i <= m ; i++ ) scanf("%lld",&b[i]);
    for( int i = 1 ; i <= m ; i++ ) {
        yes *= base;
        if( b[i] == 1 ) pos.emplace_back( i );
        else yes += b[i];
    }
    for( int i = 1 ; i <= m ; i++ ) has[i] = has[i-1] * base + a[i];
    for( int i = m + 1 ; i <= n ; i++ ) has[i] = ( has[i-1] - a[i-m] * po[m-1] ) * base + a[i];
    for( int i = 1 ; i <= n - m + 1 ; i++ ) {
        long long now = has[i+m-1];
        for( int j : pos ) {
            int del = i + j - 1;
            now -= po[m-j] * a[del];
        }
        if( now == yes ) {
            //printf("%d\n",i);
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}