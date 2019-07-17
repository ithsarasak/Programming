#include<bits/stdc++.h>

using namespace std;
int q, n, score[20010];
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&score[i]);
        }
        int ch = 0;
        for( int i = 0 ; i < n - 2 ; i++ ){
            if( ( score[i] == 2 && score[i+1] == 2 ) || ( score[i] == 2 && score[i+1] == 0 && score[i+2] == 2 ) ){
                ch = 1;
                break;
            }
        }
        if( !ch )printf("Valid\n");
        else printf("Invalid\n");
    }
}
