#include <bits/stdc++.h>

using namespace std;
int t, m, n, de, ans;
int main()
{
    scanf("%d",&t);
    for( int k = 1 ; k <= t ; k++ ){
        scanf("%d %d",&m,&n);
        ans = 1;
        while( n >= 20 ){
            if( n <= m ){
                ans++;
            }
            n -= 20;
        }
        printf("Case #%d: %d\n",k,ans);
    }
}
