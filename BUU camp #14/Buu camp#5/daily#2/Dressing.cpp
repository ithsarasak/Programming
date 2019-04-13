#include<bits/stdc++.h>

using namespace std;

int indg[50005], indg2[50005], ans[50005], n, m;
priority_queue<int,vector<int>,greater<int> > Heap;
vector< int > graph[50005];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        int from, to;
        scanf("%d %d",&to,&from);
        graph[from].push_back( to );
        indg[to]++;
        indg2[to]++;
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( indg[i] == 0 ){
            Heap.push(i);
        }
    }
    int pt = 1;
    int idx = -1;
    while( !Heap.empty() ){
        int x = Heap.top();
        Heap.pop();
        if( Heap.size() != 0 ){
            idx = pt;
        }
        ans[pt] = x;
        pt++;
        for( int i = 0 ; i < graph[x].size() ; i++ ){
            indg[graph[x][i]]--;
            if( !indg[graph[x][i]] ){
                Heap.push(graph[x][i]);
            }
        }
    }
    if( pt != n + 1 ){
        printf("Never");
        return 0;
    }
    if( idx == -1 ){
        printf("Same\n");
        for( int i = 1 ; i < pt ; i++ ){
            printf("%d ",ans[i]);
        }
        return 0;
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( indg2[i] == 0 ){
            Heap.push(i);
        }
    }
    pt = 1;
    while( !Heap.empty() ){
        int x = Heap.top();
        Heap.pop();
        if( pt == idx ){
            int y = Heap.top();
            Heap.pop();
            Heap.push(x);
            x = y;
        }
        ans[pt] = x;
        pt++;
        for( int i = 0 ; i < graph[x].size() ; i++ ){
            indg2[graph[x][i]]--;
            if( !indg2[graph[x][i]] ){
                Heap.push( graph[x][i] );
            }
        }
    }
    printf("Different\n");
    for( int i = 1 ; i < pt ; i++ ){
        printf("%d ",ans[i]);
    }
    return 0;
}
