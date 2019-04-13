#include<bits/stdc++.h>

using namespace std;
int t;
int n, num[100100];
long long fen[1000100], ans;
long long query( int idx )
{
    long long sum = 0;
    for( int i = idx - 1 ; i > 0 ; i -= ( i & -i ) ){
        sum += fen[i];
    }
    return sum;
}
void up( int idx )
{
    for( int i = idx ; i <= 1000000 ; i += ( i & -i ) ){
        fen[i] += 1;
    }
}
int main()
{
    scanf("%d",&t);
    while( t-- ){
        ans = 0;
        memset( fen, 0, sizeof fen );
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&num[i]);
        }
        for( int i = n ; i >= 1 ; i-- ){
            ans += query( num[i] );
            up( num[i] );
        }
        printf("%lld\n",ans);
    }
}
