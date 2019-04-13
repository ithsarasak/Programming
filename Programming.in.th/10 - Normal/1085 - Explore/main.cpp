#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

vector<int> vec[500001];
queue<int> q;
int i, j, room, teleport, rock, go, to, maxs, t, d = 1, visit[500001],rocks[500001];
int main()
{
    scanf("%d %d %d",&room,&teleport,&rock);

    for( i = 0 ; i < teleport ; i++ )
    {
        scanf("%d %d",&go,&to);
        vec[go].push_back(to);
    }
    for( i = 0 ; i < rock ; i++ )
    {
        scanf("%d",&go);

        rocks[go]++;
    }
    q.push(1);
    while( !q.empty() ){
        t = q.front();
        q.pop();
        if( maxs < t ){
            maxs = t;
        }
        if( t == room ){
            printf("1");
            break;
        }
        if( !visit[ t + 1 ] && rocks[t] == 0 ){
            q.push( t + 1 );
            visit[ t + 1 ] = 1;
        }
        for( j = 0 ; j < vec[t].size() ; j++ ){
                if( !visit[vec[t][j]] ){
                    visit[vec[t][j]] = 1;
                    q.push( vec[t][j] );
                }
        }
    }
    if( maxs != room ){
        printf("0 %d",maxs);
    }
}
