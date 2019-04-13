#include<bits/stdc++.h>

using namespace std;

vector<int> co, co2;
int n, m, t;
int main()
{
    scanf("%d %d",&n,&m);
    while( n-- ){
        scanf("%d",&t);
       co.push_back( t );
       co2.push_back( t + 100 );
    }
    while( m-- ){
        scanf("%d",&t);
        co.push_back( t + 100 );
        co2.push_back( t );
    }
    sort( co.begin() , co.end() );
    sort( co2.begin() , co2.end() );
    printf("%d",min( co[0] + co[1] , co2[0] + co2[1] ));
    return 0;
}
