#include<stdio.h>
#include<vector>
#include<queue>

long long visit[1000];
long long i, j, n, m;
using namespace std;
struct node{
    long long go, dis;
}t, ans[100];
typedef struct node node;
struct pairs{
    long long point, d;
    bool operator<( const pairs &k )const{
        if( k.d == d ){
            return k.point < point;
        }
        else{
            return k.d < d;
        }
    }
}temp;
typedef struct pairs pairs;
vector<node> vec[100];
priority_queue<pairs> q;
int main()
{
    scanf("%lld %lld",&n,&m);

    for( i = 0 ; i < m ; i++ ){
        long long from, to, di;

        scanf("%lld %lld %lld",&from,&to,&di);
        t.go = to;
        t.dis = di;
        vec[from].push_back(t);
        t.go = from;
        vec[to].push_back(t);
    }
    q.push({ 1, 0 });
    int k = 0;
    while( !q.empty() ){
        temp = q.top();
        for( i = 0 ; i < vec[temp.point].size() ; i++ ){
            if( visit[vec[temp.point][i].go] == 0 ){
                ans[k].go = temp.point;
                ans[k].dis = vec[temp.point][i].go;
                q.push({ vec[temp.point][i].go , vec[temp.point][i].dis });
                k++;
                printf("%d\n",k);
            }
        }
        q.pop();
        visit[temp.point] = 1;
    }
    for( i = 0 ; i < k ; i++ ){
        printf("%lld -> %lld\n",ans[i].go,ans[i].dis);
    }
}
