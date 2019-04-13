#include<bits/stdc++.h>

using namespace std;
int a[100100], b[500];
int main()
{
    int n, q, x, y, ans;
    char op;
    scanf("%d %d",&n,&q);
    int len = sqrt(n);
    while( q-- ){
        scanf(" %c %d %d",&op,&x,&y);
        x--;
        if( op == 'U' ){
            a[x] = y;
            b[x/len] = -1e9;
            for( int i = x / len * len ; i< min( n, x / len * len + len ) ; i++ ){
                b[x/len] = max( b[x/len],a[i]);
            }
        }
        else{
            y--;
            ans = -1e9;
            for( int i = x ; i <= y ;){
                if( i % len == 0 && i + len - 1 <= y ){
                    ans = max( ans, b[i / len] );
                    i += len;
                }
                else{
                    ans = max( ans, a[i] );
                    i++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
