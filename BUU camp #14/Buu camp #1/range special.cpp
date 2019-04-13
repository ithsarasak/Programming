#include<bits/stdc++.h>

using namespace std;
deque< pair< long long, long long > > dmax, dmin;
long long seq[1000010], n, p, q;
int main()
{
    scanf("%lld %lld %lld",&n,&p,&q);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&seq[i]);
    }
    long long sump = 0, sumq = 0, cur = 0;
    for( int i = 1 ; i <= n ; i++ ){
        while( !dmin.empty() && dmin.back().second > seq[i] )dmin.pop_back();
        while( !dmax.empty() && dmax.back().second < seq[i] )dmax.pop_back();
        dmin.push_back( make_pair( i, seq[i] ) );
        dmax.push_back( make_pair( i, seq[i] ) );
        while( !dmin.empty() && !dmax.empty() ){
            if( dmax.front().second - dmin.front().second <= q )break;
            if( dmax.front().first < dmin.front().first ){
                cur = dmax.front().first, dmax.pop_front();
            }
            else{
                cur = dmin.front().first, dmin.pop_front();
            }
        }
        sumq += i - cur;
    }
    cur = 0;
    while( !dmin.empty() ){
        dmin.pop_back();
    }
    while( !dmax.empty() ){
        dmax.pop_back();
    }
    for( int i = 1 ; i <= n ; i++ ){
        while( !dmin.empty() && dmin.back().second > seq[i] )dmin.pop_back();
        while( !dmax.empty() && dmax.back().second < seq[i] )dmax.pop_back();
        dmin.push_back( make_pair( i, seq[i] ) );
        dmax.push_back( make_pair( i, seq[i] ) );
        while( !dmin.empty() && !dmax.empty() ){
            if( dmax.front().second - dmin.front().second < p )break;
            if( dmax.front() .first < dmin.front().first ){
                cur = dmax.front().first, dmax.pop_front();
            }
            else{
                cur = dmin.front().first, dmin.pop_front();
            }
        }
        sump += i - cur;
    }
    printf("%lld\n",sumq-sump);
    return 0;
}
