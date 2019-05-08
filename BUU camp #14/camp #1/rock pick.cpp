#include<bits/stdc++.h>

using namespace std;
int n;
int rocks[110], mic[110][110];
int dp( int l, int r )
{
    if( mic[l][r] != -1 ){
        return mic[l][r];
    }
    if( l > r ){
        return 0;
    }
    return mic[l][r] = max( max( dp( l + 1, r - 1 ) + rocks[l] , dp( l + 2 , r ) + rocks[l] ) , max( dp( l + 1, r - 1 ) + rocks[r] , dp( l , r - 2 ) + rocks[r] ) );
}
int main()
{
    memset( mic , -1 , sizeof mic );
    scanf("%d",&n);
    for( int i = 1 ; i <= 2 * n ; i++ ){
        scanf("%d",&rocks[i]);
    }
    printf("%d",dp( 1, 2 * n ));
    return 0;
}
