#include <bits/stdc++.h>

using namespace std;
struct ss{
    int pos;
    long long n;
};
int n;
long long ans;
stack<ss> s;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        int t;
        scanf("%d",&t);
        while( !s.empty() && t > s.top().pos ){
            ans += s.top().n;
            s.pop();
        }
        if( !s.empty() && s.top().pos == t ){
            ans += s.top().n;
            s.top().n += 1;
            if( s.size() != 1 )ans++;
        }
        else{
            s.push({ t, 1 });
            if( s.size() != 1 )ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
