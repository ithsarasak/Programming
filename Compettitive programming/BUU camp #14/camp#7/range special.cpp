#include<bits/stdc++.h>

using namespace std;
struct qq{
    long long pos, va;
};
deque< qq > dmin, dmax;
int n, p, q, last = 0;
long long ans;
long long num[1000100];
int main()
{
    scanf("%d %d %d",&n,&p,&q);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&num[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        while( !dmin.empty() && dmin.back().va > num[i] )dmin.pop_back();
        while( !dmax.empty() && dmax.back().va < num[i] )dmax.pop_back();
        dmin.push_back({ i, num[i] });
        dmax.push_back({ i, num[i] });
        while( !dmin.empty() && !dmax.empty() ){
            if( dmax.front().va - dmin.front().va <= q )break;
            if( dmax.front().pos > dmin.front().pos ){
                last = dmin.front().pos;
                dmin.pop_front();
            }
            else{
                last = dmax.front().pos;
                dmax.pop_front();
            }
        }
        ans += i - last;
    }
    last = 0;
    while( !dmin.empty() )dmin.pop_back();
    while( !dmax.empty() )dmax.pop_back();
    for( int i = 1 ; i <= n ; i++ ){
        while( !dmin.empty() && dmin.back().va > num[i] )dmin.pop_back();
        while( !dmax.empty() && dmax.back().va < num[i] )dmax.pop_back();
        dmin.push_back({ i, num[i] });
        dmax.push_back({ i, num[i] });
        while( !dmin.empty() && !dmax.empty() ){
            if( dmax.front().va - dmin.front().va <= p - 1 )break;
            if( dmax.front().pos > dmin.front().pos ){
                last = dmin.front().pos;
                dmin.pop_front();
            }
            else{
                last = dmax.front().pos;
                dmax.pop_front();
            }
        }
        ans -= i - last;
    }
    printf("%lld",ans);
    return 0;
}
