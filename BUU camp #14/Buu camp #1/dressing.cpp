#include<bits/stdc++.h>

using namespace std;

int indg[50005], indg2[50005], ans[50005], n, m;
struct hh{
    int no;
    bool operator<( const hh &k )const{
        return no > k.no;
    }
}x, y;
priority_queue< hh > he;
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
            he.push({i});
        }
    }
    int pt = 1;
    int idx = -1;
    while( !he.empty() ){
        x = he.top();
        he.pop();
        if( he.size() != 0 ){
            idx = pt;
        }
        ans[pt] = x.no;
        pt++;
        for( int i = 0 ; i < graph[x.no].size() ; i++ ){
            indg[graph[x.no][i]]--;
            if( !indg[graph[x.no][i]] ){
                he.push({graph[x.no][i]});
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
            he.push({i});
        }
    }
    pt = 1;
    while( !he.empty() ){
        x = he.top();
        he.pop();
        if( pt == idx ){
            y = he.top();
            he.pop();
            he.push({x});
            x = y;
        }
        ans[pt] = x.no;
        pt++;
        for( int i = 0 ; i < graph[x.no].size() ; i++ ){
            indg2[graph[x.no][i]]--;
            if( !indg2[graph[x.no][i]] ){
                he.push({graph[x.no][i]});
            }
        }
    }
    printf("Different\n");
    for( int i = 1 ; i < pt ; i++ ){
        printf("%d ",ans[i]);
    }
    return 0;
}
