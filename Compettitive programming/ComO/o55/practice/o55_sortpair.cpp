#include<bits/stdc++.h>

using namespace std;
struct vv{
    int x, y;
    bool operator<( const vv &k )const{
        if( x == k.x )return y <k.y;
        else return x < k.x;
    }
};
int n;
vector<vv> v;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        int a, b;
        scanf("%d %d",&a,&b);
        v.push_back({ a, b });
    }
    sort( v.begin(), v.end() );
    for( int i = 0 ; i < v.size() ; i++ )printf("%d %d\n",v[i].x,v[i].y);
    return 0;
}
