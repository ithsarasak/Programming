#include<bits/stdc++.h>

using namespace std;
int par[100010], f, t, n, q;
char op;
int findroot( int num )
{
    if( par[num] == num ) return  num;
    else return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 1 ; i <= n ; i++ )par[i] = i;
    for( int i = 0 ; i < q ; i++ ){
        scanf(" %c",&op);
        if( op == 'c' ){
            scanf("%d %d",&f,&t);
            int a = findroot( f );
            int b = findroot( t );
            if( a != b )par[a] = b;
        }
        else{
            scanf("%d %d",&f,&t);
            int a = findroot( f );
            int b = findroot( t );
            if( a == b )printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
