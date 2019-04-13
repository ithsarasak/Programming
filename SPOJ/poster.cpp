#include<bits/stdc++.h>

using namespace std;
struct ss{
    int co, ti, t;
    bool operator<( const ss &k )const{
        return ti < k.ti;
    }
};
struct vv{
    int f, t, co, ti;
    bool operator<( const vv &k )const{
        if( f == k.f )return ti > k.ti;
        else f < k.f;
    }
};
priority_queue<ss> q;
vector<vv> v;
int t;
int main()
{
    scanf("%d",&t);
    while( t-- ){
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            int f, t;
            scanf("%d %d",&f,&t);
            v.push_back({ f, t+1, i+1, i+1 });
        }
        sort( v.begin(), v.end() );
        for( int i = 0 ; i < v.size() ; i++ ){
            while( !q.empty() && q.top().t )
        }
    }
}
