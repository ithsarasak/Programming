#include<bits/stdc++.h>

using namespace std;
int n, he[1000010];
int ans[1000010];
deque<int> q;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&he[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        while( !q.empty() && he[i] >= he[q.back()] ) q.pop_back();
        if( q.empty() )ans[i] += i;
        else ans[i] += abs( i - q.back() );
        q.push_back( i );
    }
    while( !q.empty() )q.pop_back();
    for( int i = n ; i >= 1 ; i-- ){
        while( !q.empty() && he[i] >= he[q.back()] ) q.pop_back();
        if( q.empty() )ans[i] += n - i + 1;
        else ans[i] += abs( q.back() - i );
        q.push_back( i );
    }
    for( int i = 1 ; i <= n ; i++ ){
        printf("%d ",ans[i]-1);
    }
    return 0;
}
