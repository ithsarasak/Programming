#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < 2*n ; i++ ){
        int a;
        scanf("%d",&a);
        v.push_back( a );
    }
    sort( v.begin(), v.end() );
    printf("%d",v[n-1]);
    return 0;
}
