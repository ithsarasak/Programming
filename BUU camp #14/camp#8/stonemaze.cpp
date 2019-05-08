#include <bits/stdc++.h>

using namespace std;

char ma[1010][1010];
int q, r, c;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        int cnt = 0;
        scanf("%d %d",&r,&c);
        for( int i = 0 ; i < r ; i++ )scanf("%s",ma[i]);
        for( int i = 0 ; i < r ; i++ )for( int j = 0 ; j < c ; j++ ){
            if( ma[i][j] == '.' )cnt++;
        }
        printf("%d\n",2*cnt-2);
    }
    return 0;
}
