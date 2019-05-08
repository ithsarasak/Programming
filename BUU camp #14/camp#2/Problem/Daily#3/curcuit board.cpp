#include<bits/stdc++.h>

using namespace std;
struct pp{
    int x1, x2;
    bool operator<( const pp &k )const{
        if( x1 == k.x1 ) return x2 < k.x2;
        else return x1 > k.x1;
    }
}pa[100010];
vector< int > lis;
int n;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&pa[i].x1,&pa[i].x2);
    }
    sort( pa, pa + n );
    lis.push_back( pa[0].x2 );
    for( int i = 1 ; i < n ; i++ ){
        if( pa[i].x2 > lis.back() ){
            lis.push_back( pa[i].x2 );
        }
        else{
            int idx = upper_bound( lis.begin(), lis.end(), pa[i].x2 ) - lis.begin();
            lis[idx] = pa[i].x2;
        }
    }
    printf("%d",lis.size());
    return 0;
}
