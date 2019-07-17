#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no, d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}t;
struct gg{
    int t, d;
};
vector<gg> g[70];
priority_queue<qq> q;
int p, ans= 1e9;
int dis[70];
char ans2;
int main()
{
    for( int i = 0 ; i < 70 ; i++ )dis[i] = 1e9;
    scanf("%d",&p);
    for( int i = 0 ; i < p ; i++ ){
        char f, t;
        int d;
        scanf(" %c  %c %d",&f,&t,&d);
        //printf("%d %d\n",f-'A'+1,t-'A'+1);
        g[f-'A'+1].push_back({ t-'A'+1, d });
        g[t-'A'+1].push_back({ f-'A'+1, d });
    }
    dis['Z'-'A'+1] = 0;
    q.push({ 'Z'-'A'+1, 0 });
    while( !q.empty() ){
        t = q.top();
        q.pop();
        for( int i = 0 ; i < g[t.no].size() ; i++ ){
            //printf("%d %d\n",g[t.no][i].t,t.d);
            if( dis[g[t.no][i].t] > t.d + g[t.no][i].d ){
                dis[g[t.no][i].t] = t.d + g[t.no][i].d;
                q.push({ g[t.no][i].t, t.d + g[t.no][i].d });
            }
        }
    }
    for( int i = 1 ; i <= 25 ; i++ ){
        //printf("%d\n",dis[i]);
        if( dis[i] < ans ){
            ans = dis[i];
            ans2 = i + 'A' - 1;
        }
    }
    printf("%c %d",ans2,ans);
    return 0;
}
