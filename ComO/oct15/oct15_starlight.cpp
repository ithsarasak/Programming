#include<bits/stdc++.h>

using namespace std;
struct vv1{
    int x, y;
    bool operator<( const vv1 &k )const{
        return x < k.x;
    }
};
struct vv2{
    int x, y;
    bool operator<( const vv2 &k )const{
        return y < k.y;
    }
};
vector<vv1> v1;
vector<vv2> v2;
int s, n, ma;
double ans2;
int main()
{
    scanf("%d",&s);
    scanf("%d",&n);
    for( int i = 0 ; i< n ; i++ ){
        int x, y;
        scanf("%d %d",&x,&y);
        v1.push_back({ x, y });
        v2.push_back({ x, y });
    }
    sort( v1.begin(), v1.end() );
    sort( v2.begin(), v2.end() );
    for( int i = 0 ; i < v1.size() - 1 ; i++ ){
        ma = max( ma, v1[i+1].x - v1[i].x );
        ma = max( ma, v2[i+1].y - v2[i].y );
    }
    double ans = ( double )ma / 2.00;
    ma = max( ma, v1[0].x );
    ma = max( ma, s - v1[v1.size()-1].x );
    ma = max( ma, v2[0].y );
    ma = max( ma, s - v2[v2.size()-1].y );
    ans2 = ( double )ma;
    if( ans2 - ans > 1e-6 )ans = ans2;
    printf("%.3lf",ans);
    return 0;
}
