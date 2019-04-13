#include<bits/stdc++.h>

using namespace std;
int n;
int wood[30010], ans;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&wood[i]);
    }
    if( n < 3 ){
        printf("%d",n);
        return 0;
    }
    sort( wood + 1, wood + n + 1 );
    for( int i = 1 ; i <= n ; i++ ){
        int sum = wood[i] + wood[i + 1];
        int idx = lower_bound( wood + 1 , wood + n + 1 , sum ) - wood;
        if( idx - i >= 3 ){
            ans = max( ans , idx - i );
        }
    }
    printf("%d",ans);
    return 0;
}
