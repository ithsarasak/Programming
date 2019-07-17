#include<bits/stdc++.h>

using namespace std;
struct qq{
    int va, idx;
};
int n;
int num[1001000];
deque<qq> q;
int len = 0, ma;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        while(!q.empty() && num[i] < q.front().va ){
            ma = -2000000000;
            q.pop_front();
        }
        ma = max( ma, num[i] );
        q.push_back({ num[i], i });
        if( num[i] == ma ){
            len = max( len, i - q.front().idx + 1 );
        }
    }
    if( len == 1 )printf("-1");
    else printf("%d",len);
    return 0;
}
