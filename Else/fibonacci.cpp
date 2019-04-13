#include<bits/stdc++.h>

using namespace std;
int fibo[2100][310];
int c;
int main()
{
    fibo[0][0] = 0;
    fibo[1][0] = 1;
    for( int i = 2 ; i <= 1200 ; i++ ){
        int tod = 0;
        for( int j = 0 ; j <= 300 ; j++ ){
            int temp = fibo[i-1][j] + fibo[i-2][j] + tod;
            fibo[i][j] = temp % 10;
            tod = temp / 10;
        }
    }
    printf("Command\n1 and the number n ( number of the fibonacci u want to know, n <= 1200 )\n2 to end this program\n");
    while( 1 ){
        scanf("%d",&c);
        if( c == 1 ){
            int n;
            scanf("%d",&n);
            int st = 0;
            for( int i = 300 ; i >= 0 ; i-- ){
                if( fibo[n][i] != 0 )st = 1;
                if( st == 1 )printf("%d",fibo[n][i]);
            }
            printf("\n");
        }
        else if( c == 2 ){
            break;
        }
    }
    return 0;
}
