#include<bits/stdc++.h>

using namespace std;
struct info{
    long long idx, va;
};
deque<info> q;
long long n, k, milen, mx;
long long ho[6000010], qs[6000010];
int main()
{
    scanf("%lld %lld",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&ho[i]);
        qs[i] = qs[i-1] + ho[i];
    }
    q.push_back({0,0});
    for( int i = 1 ; i <= n ; i++ ){
        while( !q.empty() && q.back().va > qs[i] )q.pop_back();
        while( !q.empty() && q.front().idx < i - k )q.pop_front();
        q.push_back({ i, qs[i] });
        if( mx < q.back().va - q.front().va ){
            mx = q.back().va - q.front().va;
            milen = q.back().idx - q.front().idx;
        }
        else if( mx == q.back().va - q.front().va ){
            milen = min( milen, q.back().idx - q.front().idx );
        }
    }
    printf("%lld %lld",mx,milen);
    return 0;
}

