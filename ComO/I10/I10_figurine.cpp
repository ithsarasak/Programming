#include<bits/stdc++.h>

using namespace std;
int n, ans;
int num[150100];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ )scanf("%d",&num[i]);
    sort( num + 1, num + 1 + n, greater<int>() );
    int l = 1, r = n;
    while( r - l + 1 >= 5 ){
        ans += num[l];
        ans += num[r] + num[r-1] + num[r-2];
        l += 2;
        r -= 3;
    }
    for( int i = l ; i <= r ; i++ )ans += num[i];
    printf("%d",ans);
    return 0;
}
