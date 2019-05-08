#include <bits/stdc++.h>

using namespace std;
struct ss{
    long long h, cnt, num;
};
stack<ss> st[1100];
long long n, m;
long long hi[1100][1100], arr[1100][1100], sum[1100], ans;
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            long long num;
            scanf("%lld",&num);
            arr[i][j] = num;
            long long hinow = 1, cntnow = 1;
            while( !st[i].empty() && st[i].top().num != num )sum[i] -= st[i].top().h*st[i].top().cnt,st[i].pop();
            if( num == arr[i-1][j] )hinow = hi[i-1][j] + 1;
            hi[i][j] = hinow;
            while( !st[i].empty() && st[i].top().h >=hinow )sum[i] -= st[i].top().h*st[i].top().cnt,cntnow+=st[i].top().cnt,st[i].pop();
            st[i].push({ hinow, cntnow, num });
            sum[i] += st[i].top().h*st[i].top().cnt;
            ans += sum[i];
        }
    }
    printf("%lld",ans);
    return 0;
}
