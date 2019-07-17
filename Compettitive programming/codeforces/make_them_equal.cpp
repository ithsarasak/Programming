#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n, num[N], mark[N];
vector<int> ans;

int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&num[i]);
    sort( num, num + n );
    for( int i = 0 ; i < n ; i++ ) if( mark[num[i]] == 0 ) ans.emplace_back( num[i] ), mark[num[i]] = 1;
    if( ans.size() > 3 ) printf("-1");
    else if( ans.size() == 3 && ans[2] - ans[1] != ans[1] - ans[0] ) printf("-1");
    else if( ans.size() == 3 ) printf("%d",min( ans[2] - ans[1], ans[1] - ans[0] ));
    else if( ans.size() == 2 ) printf("%d",( ans[1] - ans[0] ) % 2 == 0 ? ( ans[1] - ans[0] ) / 2 : ans[1] - ans[0] );
    else printf("0");
    return 0;
}