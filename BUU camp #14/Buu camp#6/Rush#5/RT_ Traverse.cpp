#include<bits/stdc++.h>

using namespace std;
int n, m, ans;
int node[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
int e[10][10];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        e[f][t] = 1;
        e[t][f] = 1;
    }
    do{
        int ch = 1;
        for( int i = 0 ; i < n - 1 ; i++ ){
            if( e[node[i]][node[i+1]] == 0 ){
                ch = 0;
                break;
            }
        }
        if( ch )ans++;
    }while( next_permutation( node + 1, node + n ) );
    printf("%d",ans);
    return 0;
}
