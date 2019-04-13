#include<bits/stdc++.h>

using namespace std;
int n, m;
deque<int> q;
int num[1100];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
    }
    while( m-- ){
        int k;
        scanf("%d",&k);
        while( !q.empty() )q.pop_back();
        int sum = 0, ma = 0;
        for( int i = 0 ; i < n ; i++ ){
            q.push_back( num[i] );
            sum += num[i];
            while( sum > k && !q.empty() )sum-=q.front(),q.pop_front();
            int si = q.size();
            ma = max( ma, si );
        }
        printf("%d\n",ma);
    }
    return 0;
}
