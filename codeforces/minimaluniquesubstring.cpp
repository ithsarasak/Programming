#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

int n, k, dif, mod;
char ans[N];

bool chk( int i ) {
    if( i % mod == dif ) return true;
    else return false;
} 

int main() 
{
    scanf("%d %d",&n,&k);
    dif = ( n - k ) / 2, mod = ( n - k ) / 2 + 1;
    for( int i = 0 ; i < n ; i++ ) {
        if( chk( i ) ) ans[i] = '1';
        else ans[i] = '0';
    }
    printf("%s",ans);
    return 0;
}