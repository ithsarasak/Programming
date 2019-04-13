#include<bits/stdc++.h>

using namespace std;

struct qq{
    long long day;
    int shirt;
    bool operator<( const qq &k )const{
        if( day == k.day )return shirt > k.shirt;
        else return day > k.day;
    }
};
priority_queue<int,vector<int>,greater<int> > heap;
priority_queue<qq> q;
int n, k, send;
long long day;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        int nu;
        scanf("%d",&nu);
        heap.push( nu );
    }
    while( !heap.empty() ){
        day++;
        int t = heap.top();
        heap.pop();
        if( send < k ){
            q.push({ day + t + 1, t });
            send++;
        }
        //printf("%lld %d %d\n",day,t,send);
        while( !q.empty() && q.top().day <= day + 1 ){
            heap.push( q.top().shirt );
            q.pop();
        }
    }
    printf("%lld",day);
    return 0;
}
