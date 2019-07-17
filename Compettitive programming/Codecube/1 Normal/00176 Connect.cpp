#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t;
}edge[100010];
int n, k, q;
int par[100010];
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d %d",&n,&k,&q);
    for(int i=0;i<k;i++){
        scanf("%d %d",&edge[i].f,&edge[i].t);
    }
    for(int i=0;i<=n;i++){
        par[i] = i;
    }
    for(int i=0;i<k;i++){
        int a = findroot( edge[i].f );
        int b = findroot( edge[i].t );
        if( a != b ){
            par[a] = b;
        }
    }
    while(q--){
        int fr, to;
        scanf("%d %d",&fr,&to);
        int a = findroot( fr );
        int b = findroot( to );
        if( a == b ) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
