#include<stdio.h>
int soldier[100010], war, i, j, pol;
int one, two;
int par[100010];
int findroot( int num )
{
    if( par[num] == num ){
        return num;
    }
    return par[num] = findroot( par[num] );
}
int main()
{
    scanf("%d %d",&pol,&war);
    for( i = 1 ; i <= pol ; i++ ){
        scanf("%d",&soldier[i]);
        par[i] = i;
    }
    for( i = 1 ; i <= war ; i++ ){
        scanf("%d %d",&one,&two);
        int a = findroot( one );
        int b = findroot( two );
        if( a == b ){
            printf("-1\n");
        }
        else if( soldier[a] > soldier[b] ){
            soldier[a] += soldier[b] / 2;
            par[b] = a;
            printf("%d\n",a);
        }
        else if( soldier[b] > soldier[a] ){
            soldier[b] += soldier[a] / 2;
            par[a] = b;
            printf("%d\n",b);
        }
        else{
            if( a < b ){
                soldier[a] += soldier[b] / 2;
                par[b] = a;
                printf("%d\n",a);
            }
            else{
                soldier[b] += soldier[a] / 2;
                par[a] = b;
                printf("%d\n",b);
            }
        }
    }
    return 0;
}
