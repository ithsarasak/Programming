#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

long long final[10001], visit[10001];
long long i, j, numver, numedge;
struct node{
    long long go, dis;
}t;
struct pairs{
    long long vertex, dis;
    bool operator < ( const pairs &p )const{
        return p.dis < dis;
    }
}temp;
vector< node > vec[10001];
priority_queue< pairs > q;
int main()
{
    scanf("%lld %lld",&numver,&numedge);

    for( i = 0 ; i < numedge ; i++ )
    {
        long long from, to, hf;
        scanf("%lld %lld %lld",&from,&to,&hf);
        t.go = to;
        t.dis = hf;
        vec[from].push_back(t);
    }

    q.push({ 1 , 0 });

    while( !q.empty() )
    {
        temp = q.top();
        for( j = 0 ; j < vec[temp.vertex].size() ; j++ )
        {
            if( visit[vec[temp.vertex][j].go] == 0 )
            {
                if( final[vec[temp.vertex][j].go] == 0 || final[vec[temp.vertex][j].go] > temp.dis + vec[temp.vertex][j].dis )
                {
                    final[vec[temp.vertex][j].go] = temp.dis + vec[temp.vertex][j].dis;
                    q.push({ vec[temp.vertex][j].go , final[vec[temp.vertex][j].go] });
                }
            }
        }
        visit[temp.vertex] = 1;
        q.pop();
    }
    printf("%lld",( final[numver] + 4 ) / 5 );
    return 0;
}
