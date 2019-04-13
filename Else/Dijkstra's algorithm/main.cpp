#include<bits/stdc++.h>

using namespace std;
long long final[10001],visit[10001];
long long n,m;

struct node{
    long long x,y;
}t;

struct pairs{
    long long p,sum;
    bool operator<(const pairs &q) const{
        return q.sum<sum;
    }
}t1;

vector< node > dist[10001];
priority_queue< pairs > a;

void clear()
{
    while( !a.empty() )
    {
        a.pop();
    }

    for(long long i = 1 ; i <= n ; i++ )
    {
        if( !dist[i].empty() )
        {
            dist[i].pop_back();
        }
        final[i]=0;
        visit[i]=0;
    }
    return ;
}
int main()
{
    int test;

    scanf("%d",&test);

    for(int num = 1 ; num <= test ; num++ )
    {
        scanf("%lld %lld",&n,&m);

        long long p,q,r;

        for(long long i = 0 ; i < m  ; i++ ){

            scanf("%lld %lld %lld",&p,&q,&r);

            t.x=q,t.y=r;

            dist[p].push_back(t);
        }
        /*for(int i=1;i<=n;i++){
         for(int j=0;j<dist[i].size();j++){
         printf("%d %d %d\n",i,dist[i][j].x,dist[i][j].y);
         }
         }*/
        long long s,e;

        scanf("%lld %lld",&s,&e);

        a.push({s,0});

        while(!a.empty())
        {
            t1=a.top();

            for(long long j = 0 ; j < dist[t1.p].size() ; j++ )
            {
                if(visit[dist[t1.p][j].x]==0)
                {
                    if( final[dist[t1.p][j].x] == 0 || final[dist[t1.p][j].x] > t1.sum+dist[t1.p][j].y )
                    {
                        final[ dist[t1.p][j].x ] = t1.sum + dist[t1.p][j].y ;
                        a.push({ dist[t1.p][j].x , final[dist[t1.p][j].x] }) ;
                    }
                }
            }
            visit[t1.p]=1;
            a.pop();
        }
        if( visit[e]!=0 )
        {
            printf("%lld\n",final[e]);
        }
        else
        {
            printf("NO\n");
        }
        clear();
    }
}
