#include<bits/stdc++.h>

using namespace std;
struct au{
    int a, b;
}coas[200200];
struct dq{
    int pos, en;
};
int qe, n, ans;
deque<dq> q;
int main()
{
    scanf("%d",&qe);
    while( qe-- ){
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&coas[i].a);
        }
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&coas[i].b);
            coas[i+n] = coas[i];
        }
        ans = 0;
        for( int i = 0 ; i < 2*n ; i++ ){
            int t = coas[i].a-coas[i].b;
            q.push_back({ i, t });
            int pu = 0;
            if( q.front().pos == i % n && q.front().pos != i ){
                ans ++;
                q.pop_front();
            }
            while( !q.empty() ){
                //printf("%d %d\n",q.back().en,q.back().pos);
                if( q.back().en + pu >= 0 ){
                    q.back().en += pu;
                    break;
                }
                else{
                    pu += q.back().en;
                }
                q.pop_back();
            }
        }
        while( !q.empty() )q.pop_back();
        printf("%d\n",ans);
    }
    return 0;
}
