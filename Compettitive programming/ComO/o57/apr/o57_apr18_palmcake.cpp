#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define iii tuple<long long, long long, long long>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
vector<iii> poi, vec;
iii st;
int n, ans, pos[N];
int orien( pii a, pii b, pii c ) {
    long long val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
    //printf("ONE : %lld %lld TWO : %lld %lld THREE : %lld %lld VAL :%lld\n",a.x,a.y,b.x,b.y,c.x,c.y,val);
    if( !val ) return 0;
    return val < 0 ? 2 : 1;
}

long long d( pii a, pii b ) { return abs( b.x - a.x ) * abs( b.x - a.x ) + abs( b.y - a.y ) * abs( b.y - a.y ); }
void make_hull() {
    sort( poi.begin(), poi.end(), [&]( const iii &a, const iii &b ) {
        long long x, y, z, x2, y2, z2;
        tie( x, y, z ) = a, tie( x2, y2, z2 ) = b;
        if( y != y2 ) return y > y2;
        else return x > x2;
    }); 
    st = poi.back(), poi.pop_back();
    pii ori( get<0>(st), get<1>(st) );
    sort( poi.begin(), poi.end(), [&]( const iii &a, const iii &b ) {
        long long x, y, z, x2, y2, z2;
        tie( x, y, z ) = a, tie( x2, y2, z2 ) = b;
        int o = orien( ori, pii( x, y ), pii( x2, y2 ) );
        if( o == 0 ) return d( ori, pii( x, y ) ) < d( ori, pii( x2, y2 ) );
        else return o == 2;
    }); 
    /*printf("ORI %lld %lld\n",ori.x,ori.y);
    for( iii i : poi ) {
        printf("%lld %lld\n",get<0>(i),get<1>(i));
    }*/
    for( int i = 0 ; i < (int)poi.size() ; i++ ) pos[get<2>(poi[i])] = i+1;
    vec.emplace_back( st ), vec.emplace_back( poi[0] );
    for( int i = 1 ; i < (int)poi.size() ; i++ ) {
        pii one( get<0>(vec[(int)vec.size()-2]), get<1>(vec[(int)vec.size()-2]) );
        pii two( get<0>(vec.back()), get<1>(vec.back()) );
        pii three( get<0>(poi[i]), get<1>(poi[i]) );
        while( vec.size() > 2 && orien( one, two, three ) != 2 ) {
            vec.pop_back();
            one = pii( get<0>(vec[(int)vec.size()-2]), get<1>(vec[(int)vec.size()-2]) );
            two = pii( get<0>(vec.back()), get<1>(vec.back()) );
        }
        vec.emplace_back( poi[i] );
        /*printf("VEC\n");
        for( iii i : vec ) {
            printf("%lld %lld\n",get<0>(i),get<1>(i));
        }*/
    }
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        long long a, b;
        scanf("%lld %lld",&a,&b);
        poi.emplace_back( iii( a, b, i ) );
    }
    make_hull();
    for( int i = 0 ; i < (int)vec.size()-1 ; i++ ) {
        long long a, b, c, a2, b2, c2;
        tie( a, b, c ) = vec[i];
        tie( a2, b2, c2 ) = vec[(i+2)%(int)vec.size()];
        printf("%lld %lld %lld %d %d\n",a,b,c,pos[c],pos[c2]);
        if( pos[c2] > pos[c] ) ans = max( ans, pos[c2] - pos[c] + 1 );
        else ans = max( ans, n-pos[c] + pos[c2] + 1 );
        //ans = max( ans, abs( pos[c] - pos[c2] ) + 1 );
    }
    /*pii one( get<0>(vec[0]), get<1>(vec[0]) );
    pii two( get<0>(vec[1]), get<1>(vec[1]) );
    pii three( get<0>(vec[(int)vec.size()-1]), get<1>(vec[(int)vec.size()-1]) );
    int last = 0;
    for( int i = 0 ; i < n ; i++ ) {
        if( i == get<2>(vec[0]) || i == get<2>(vec[(int)vec.size()-1]) || i == get<2>(vec[1]) ) continue ;
        pii now( get<0>(poi[i]), get<1>(poi[i]) );
        int temp1 = orien( one, two, now );
        int temp2 = orien( two, three, now );
        int temp3 = orien( three, one, now );
        if( temp1 == temp2 && temp2 == temp3 && temp1 == 2 ) last++;
    }*/
    printf("%d",ans);
    return 0;
}