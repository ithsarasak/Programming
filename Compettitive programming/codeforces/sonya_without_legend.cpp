#include <bits/stdc++.h>

using namespace std;

int n;
long long val, ans;
priority_queue<long long> q;
int main()
{
    scanf("%d",&n);
    scanf("%lld",&val);
    q.emplace( val - 1 );
    for( int i = 2 ; i <= n ; i++ ) {
        scanf("%lld",&val); val -= i;
        q.emplace( val );
        if( q.top() > val ) {
            ans += q.top() - val;
            q.pop();
            q.emplace( val );
        }
        //printf("%d\n",ans);
    }
    printf("%lld",ans);
    return 0;
}