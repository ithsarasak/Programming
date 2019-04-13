#include<stdio.h>
main()
{
    int num[5],i,j,temp;
    for(i=0;i<5;i++){
        scanf("%d",&num[i]);
    }
    while(num[0]!=1||num[1]!=2||num[2]!=3||num[3]!=4||num[4]!=5){
        for(i=0;i<4;i++){
            if(num[i]>num[i+1]){
                temp=num[i];
                num[i]=num[i+1];
                num[i+1]=temp;
                printf("%d %d %d %d %d\n",num[0],num[1],num[2],num[3],num[4]);
            }
        }
    }
}
