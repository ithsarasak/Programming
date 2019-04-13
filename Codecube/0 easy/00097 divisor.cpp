#include<bits/stdc++.h>

using namespace std;
int n, sq;
vector<int> ans;
int main()
{
    scanf("%d",&n);
    sq = sqrt( n );
    for( int i = 1 ; i <= sq ; i++ ){
        if( !( n % i ) ){
            ans.push_back( i );
            if( i != n / i )
                ans.push_back( n / i );
        }
    }
    sort( ans.begin() , ans.end() );
    for( int i = 0 ; i < ans.size() ; i++ ){
        printf("%d ",ans[i]);
    }
    return 0;
}
