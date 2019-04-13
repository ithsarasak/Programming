#include<stdio.h>
#include<string.h>
int n, i, len;
char num[11][1001];
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%s",&num[i]);

    }
    for( i = 0 ; i < n ; i++ ){
        len = strlen( num[i] );
        if( num[i][len - 1] == '2' && len == 1 ){
            printf("T\n");
        }
        else if( ( num[i][len - 1] - '0' ) % 2 == 1 ){
            printf("T\n");
        }
        else{
            printf("F\n");
        }
    }
    return 0;
}
