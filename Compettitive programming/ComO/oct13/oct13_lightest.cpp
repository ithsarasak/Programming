#include<bits/stdc++.h>

using namespace std;
struct qq{
    int va, w;
    bool operator<( const qq &k )const{
        return w > k.w;
    }
};
priority_queue<qq> q;
int n, m;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n + m ; i++ ){
        char ch;
        scanf(" %c",&ch);
        if( ch == 'T' ){
            int w, v;
            scanf("%d %d",&w,&v);
            q.push({ v, w });
        }
        else{
            if( q.empty() ){
                printf("0\n");
            }
            else{
                printf("%d\n",q.top().va);
                q.pop();
            }
        }
    }
}
