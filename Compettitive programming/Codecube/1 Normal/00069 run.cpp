#include<bits/stdc++.h>

using namespace std;
int n, sta[100010], ans[100010], ma;
vector<int> lis;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&sta[i]);
    }
    lis.push_back( sta[0] );
    ans[0] += 1;
    for( int i = 1 ; i < n ; i++ ){
        if( sta[i] > lis.back() ) lis.push_back( sta[i] );
        else{
            int idx = lower_bound( lis.begin(), lis.end(), sta[i] ) - lis.begin();
            lis[idx] = sta[i];
        }
        ans[i] += lis.size();
    }
    lis.clear();
    lis.push_back( sta[n-1] );
    for( int i = n - 2 ; i >= 0 ; i-- ){
        if( sta[i] > lis.back() )lis.push_back( sta[i] );
        else{
            int idx = lower_bound( lis.begin(), lis.end(), sta[i] ) - lis.begin();
            lis[idx] = sta[i];
        }
        ans[i] += lis.size();
    }
    for( int i = 0 ; i < n ; i++ ){
        ma = max( ma, ans[i] - 1 );
    }
    printf("%d",ma);
    return 0;
}
