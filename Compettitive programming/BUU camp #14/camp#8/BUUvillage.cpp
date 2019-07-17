#include <bits/stdc++.h>

using namespace std;

int in[51000], out[51000];
int q;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        int n, m;
        scanf("%d %d",&n,&m);
        for( int i = 0 ; i < m ; i++ ){
            int a, b;
            scanf("%d %d",&a,&b);
            in[b]++, out[a]++;
        }
        int sum = 0;
        for( int i = 1 ; i <= n ; i++ ){
            if( in[i] == out[i] + 1 )sum++;
            else if( in[i] > out[i] )sum += 2;
        }
        if( sum < 2 )printf("Yes\n");
        else printf("No\n");
        memset( in, 0 ,sizeof in );
        memset( out, 0, sizeof out );
    }
    return 0;
}
