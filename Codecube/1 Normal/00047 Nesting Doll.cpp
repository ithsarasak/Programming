#include<bits/stdc++.h>

using namespace std;
int n, doll[100010], ma, co;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&doll[i]);
    }
    sort( doll, doll + n, greater<int>() );
    co = 1;
    for( int i = 1 ; i < n ; i++ ){
        if( doll[i] != doll[i - 1] ){
            ma = max( ma, co );
            co = 0;
        }
        co++;
    }
    ma = max( ma, co );
    printf("%d",ma);
    return 0;
}
