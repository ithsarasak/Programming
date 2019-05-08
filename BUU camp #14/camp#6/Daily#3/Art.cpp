#include<bits/stdc++.h>

using namespace std;
struct vv{
    int po, h, co;
    bool operator<( const vv &k )const{
        if( po == k.po )return co < k.co;
        else return po < k.po;
    }
};
int n, in;
vector<vv> v;
int ans;
int fw[1000100];
int query( int idx )
{
    int sum = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ){
        sum += fw[i];
    }
    return sum;
}
int main()
{
    scanf("%d %d",&n,&in);
    for( int i = 0 ; i < n ; i++ ){
        int f, h, t, co;
        scanf("%d %d %d %d",&f,&h,&t,&co);
        v.push_back({ f, h, co });
        v.push_back({ f+t, h, -1*co });
    }
    sort( v.begin(), v.end() );
    int s = v.size();
    for( int i = 0 ; i < s - 1 ; i++ ){
        for( int j = 1 ; j <= 1e6 ; j += ( j & -j ) ){
            fw[j] += v[i].co;
        }
        for( int j = v[i].h + 1 ; j <= 1e6 ; j += ( j &-j ) ){
            fw[j] += -1*v[i].co;
        }
        //printf("Hi");
        int l = 1, r = 1e6;
        while( l < r ){
            int m = ( l + r ) / 2;
            if( query( m ) <= in ){
                r = m;
            }
            else l = m + 1;
        }
        //printf("Hi2");
        int lower = l;
        l = 1, r = 1e6;
        while( l < r ){
            int m = ( l + r + 1 ) / 2;
            if( query( m ) >= in ){
                l = m;
            }
            else{
                r = m - 1;
            }
        }
        //printf("Hi3");
        int upper = l;
        if( upper == lower && query(upper) == in )ans += v[i+1].po - v[i].po;
        else if( upper != lower ) ans += ( upper - lower+1 ) * (v[i+1].po - v[i].po);
    }
    printf("%d",ans);
    return 0;
}
