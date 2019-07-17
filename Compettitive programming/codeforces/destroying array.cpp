#include<bits/stdc++.h>

using namespace std;
int n;
long long num[100100];
deque<int> q;
set<int> s;
long long ans[100100], sum[100100], ma;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        sum[i] = sum[i-1] + num[i];
    }
    for( int i = 0 ; i < n ; i++ ){
        int t;
        scanf("%d",&t);
        q.push_back( t );
    }
    for( int i = 1 ; i <= n ; i++ )s.insert( i );
    for( int i = 0 ; i < n ; i++ ){
        ans[n-1-i] = ma;
        int t = q.back();
        q.pop_back();
        set<int>::iterator it = s.lower_bound( t );
        set<int>::iterator it2 = it;
        int lb, rb;
        if( it == s.begin() ){
            lb = 0;
        }
        else{
            it--;
            lb = *it;
        }
        it2++;
        if( it2 == s.end() ){
            rb = n;
        }
        else{
            rb = *it2;
            rb--;
        }
        s.erase( t );
        ma = max( ma, sum[rb] - sum[lb] );
    }
    for( int i = 0 ; i < n ; i++ )printf("%lld\n",ans[i]);
    return 0;
}
