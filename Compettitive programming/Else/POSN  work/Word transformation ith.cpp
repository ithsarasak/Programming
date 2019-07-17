#include<bits/stdc++.h>

using namespace std;

struct pairs{
    int curnode, sum;
    bool operator<( const pairs &k )const{
        return k.sum < sum;
    }
}t;
vector< int > graph[100];
priority_queue< pairs > pri;
char allword[100][100], canbeword[100][100], from[100], want[100];
int n, s, start, en, visit[100], mins = 99999999, dis[100];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%s",allword[i]);
    }
    scanf("%s",from);
    for( int i = 0 ; i < n ; i++ ){
        if( strlen( allword[i] ) == strlen( from ) ){
            strcpy( canbeword[s] , allword[i] );
            s++;
        }
    }
    scanf("%s",want);
    for( int i = 0 ; i < s ; i++ ){
        if( strcmp( canbeword[i] , from ) == 0 ){
            start = i;
        }
        if( strcmp( canbeword[i] , want ) == 0 ){
            en = i;
        }
        for( int j = i + 1 ; j < s ; j++ ){
            int counts = 0;
            for( int k = 0 ; k < strlen( want ) ; k++ ){
                if( canbeword[i][k] != canbeword[j][k] ){
                    counts++;
                }
            }
            if( counts <= 1 ){
                graph[i].push_back( j );
                graph[j].push_back( i );
            }
        }
    }
    pri.push({ start , 0 });
    while( !pri.empty() ){
        t = pri.top();
        //printf("%d %d %d\n",t.curnode,t.sum,graph[t.curnode].size());
        for( int i = 0 ; i < graph[t.curnode].size() ; i++ ){
            if( !visit[graph[t.curnode][i]] ){
                if( dis[graph[t.curnode][i]] == 0 || dis[graph[t.curnode][i]] > t.sum + 1 ){
                    dis[graph[t.curnode][i]] = t.sum + 1;
                    pri.push({ graph[t.curnode][i] , dis[graph[t.curnode][i]] });
                }
            }
        }
        visit[t.curnode] = 1;
        pri.pop();
    }
    printf("%d",dis[en]);
    return 0;
}
