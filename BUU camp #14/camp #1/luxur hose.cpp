#include<bits/stdc++.h>

using namespace std;
struct peo{
    long long day, cost;
    bool operator<( const peo &k )const{
        if( k.day == day ){
            return cost > k.cost;
        }
        else{
            return day > k.day;
        }
    }
}buyer[100010];
priority_queue< long long > heap;
long long n, maxday, ans, coun;
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld %lld",&buyer[i].day,&buyer[i].cost);
        if( maxday < buyer[i].day ){
            maxday = buyer[i].day;
        }
    }
    sort( buyer , buyer + n );
    int coo = 0 ;
    for( int i = maxday ; i >= 1 ; i-- ){
        while( buyer[coo].day > i ){
            coo++;
        }
        while( buyer[coo].day == i ){
            heap.push( buyer[coo].cost );
            coo++;
        }
        if( !heap.empty() ){
            int t = heap.top();
            ans += t;
            heap.pop();
            coun++;
        }
    }
    printf("%lld %lld",ans,coun);
    return 0;
}
