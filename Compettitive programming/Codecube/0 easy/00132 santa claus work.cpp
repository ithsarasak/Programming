#include<bits/stdc++.h>

using namespace std;
int n;
long long ans = 1;
int main()
{
    scanf("%d",&n);
    while( n-- ){
        ans += ans * 3;
    }
    printf("%lld",ans);
    return 0;
}
