#include<bits/stdc++.h>

using namespace std;
int n, p, ma[1000010], ans = 1e9+1;
int main()
{
    scanf("%d %d",&n,&p);
    for( int i = 0 ; i < n ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        ma[min(f,t)]++,ma[max(f,t)+1]--;
    }
    for( int i = 0 ; i <= 1000000; i++ ){
        if( i!= 0 ){
            ma[i] += ma[i-1];
        }
        if( ma[i] == n ){
            int t = abs( p - i );
            if( ans > t ) ans = t;
        }
    }
    if( ans == 1e9+1 )printf("-1");
    else printf("%d",ans);
    return 0;
}
