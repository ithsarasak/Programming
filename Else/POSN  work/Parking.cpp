#include<bits/stdc++.h>

using namespace std;

struct work{
    int carnum, time;
    bool operator<( const work &k )const{
        if( k.time != time ){
            return k.time < time;
        }
        else{
            return k.carnum < carnum;
        }
    }
};
vector< work > allwork;
queue< int > alltime;
int n, k, alltime[300001], t;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",t);
        alltime.push( t );
    }
    for( int i = 0 ; i < k ; i++ ){
        allwork.push({ i + 1 , 0 });
    }
    while( )
}
