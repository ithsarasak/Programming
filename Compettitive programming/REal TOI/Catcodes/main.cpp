#include<stdio.h>
#include<string.h>

char codes[201][1000001], cat[100001][300];
int i, j, m, n, num, len[201], sol[201][1000001];

int main()
{
    freopen("input.txt","r",stdin);

    scanf("%d %d",&m,&n);

    for( i = 0 ; i < m ; i++ ){
        scanf("%s",cat[i]);
    }
    scanf("%d",&num);


    for( i = 0 ; i < num ; i++ ){
        scanf("%d",&len[i]);
        scanf("%s",codes[i]);
    }

    for( i = 0 ; i < num ; i++ ){
        int k = 0;
        for( j = 0 ; j < m ; j++ ){
            char *str;
            str = strstr( codes[i], cat[i] );
            printf("%s\n",str);
            /*if(  ){
                sol[i][k] = j + 1;
                k++;
            }*/
        }
    }
    /*for( i = 0 ; i < num ; i++ ){
        int k = 0;
        if( sol[i][0] == 0 ){
            printf("OK");
        }
        else{
            while( sol[i][k] != 0 ){
                printf("%d ",sol[i][k]);
                k++;
            }
        }
        printf("\n");
    }*/
    return 0;
}
