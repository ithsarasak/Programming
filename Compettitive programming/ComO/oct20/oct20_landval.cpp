#include<bits/stdc++.h>

using namespace std;
int n, m;
int fen[200100];
int main()
{
    scanf("%d %d",&n,&m);
    while( m-- ){
        int op;
        scanf("%d",&op);
        if( op == 1 ){
            int f, t, va;
            scanf("%d %d %d",&f,&t,&va);
            for( int i = f ; i <= n ; i += ( i & -i ) ){
                fen[i] += va;
            }
            for( int i = t + 1 ; i <= n ; i += ( i & -i ) ){
                fen[i] += -1*va;
            }
        }
        else{
            int pos, sum = 0;
            scanf("%d",&pos);
            for( int i = pos ; i > 0 ; i -= ( i & -i ) ){
                sum += fen[i];
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
