#include <bits/stdc++.h>

using namespace std;

int n, l, r, z;
char op;
map<int, int> tree;
int main()
{
    scanf("%d",&n);
    while( n-- ) {
        scanf(" %c %d %d",&op,&l,&r);
        if( op == 'U' ) {
            scanf("%d",&z);
            while( l != r ){
                if( l > r ) tree[l] += z, l /= 2;
                else tree[r] += z, r /= 2;
            }
        }
        else{
            int ans = 0;
            while( l != r ){
                if( l > r ) ans += tree[l], l /= 2;
                else ans += tree[r], r /= 2;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}