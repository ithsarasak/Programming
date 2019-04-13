#include<bits/stdc++.h>

using namespace std;
map< int , int > tree;
int m;
int main()
{
    scanf("%d",&m);
    for( int i = 0 ; i < m ; i++ ){
        char op;
        int l, r, z;
        scanf(" %c",&op);
        if( op == 'U' ){
            scanf("%d %d %d",&l,&r,&z);
            while( l != r ){
                if( l > r ){
                    tree[l] += z;
                    l /= 2;
                }
                else{
                    tree[r] += z;
                    r /= 2;
                }
            }
        }
        else{
                int ans = 0;
            scanf("%d %d",&l,&r);
            while( l != r ){
                if( l > r ){
                    ans += tree[l];
                    l /= 2;
                }
                else{
                    ans += tree[r];
                    r /= 2;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
