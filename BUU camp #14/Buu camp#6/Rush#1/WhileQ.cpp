#include<bits/stdc++.h>

using namespace std;
int q, pos[100100], fw[100100], ch, ans, n;
int query( int idx )
{
    int sum = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ){
        sum += fw[i];
    }
    return sum;
}
void up( int idx )
{
    for( int i = idx ; i <= 100000 ; i += ( i & -i ) ){
        fw[i] += 1;
    }
}
int main()
{
    scanf("%d",&q);
    while( q-- ){
        memset( fw, 0, sizeof fw );
        ans = 0, ch = 0;
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&pos[i]);
        }
        for( int i = n - 1 ; i >= 0 ; i-- ){
            int t = query( pos[i] - 1 );
            if( t > 2 )ch = 1;
            ans += t;
            up( pos[i] );
        }
        if( ch )printf("CHEAT\n");
        else printf("%d\n",ans);
    }
    return 0;
}
