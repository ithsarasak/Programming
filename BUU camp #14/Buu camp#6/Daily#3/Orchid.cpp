#include<bits/stdc++.h>

using namespace std;
int n, orc[1000010];
vector<int> lis;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&orc[i]);
    }
    lis.push_back( orc[0] );
    for( int i = 1 ; i < n ; i++ ){
        if( orc[i] >= lis.back() ){
            lis.push_back( orc[i] );
        }
        else{
            int idx = upper_bound( lis.begin(), lis.end(), orc[i] ) - lis.begin();
            lis[idx] = orc[i];
        }
    }
    printf("%d",n-lis.size());
    return 0;
}
