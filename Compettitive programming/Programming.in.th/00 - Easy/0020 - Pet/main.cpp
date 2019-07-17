#include<stdio.h>
int maxint=2000000000;
int max=-maxint;
main()
{
    int i,j;
    int score[10][10];
    int all[5],num;

    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&score[i][j]);
        }
    }

    for(i=0;i<5;i++)
    {
        all[i]=score[i][0]+score[i][1]+score[i][2]+score[i][3];
    }

    for(i=0;i<5;i++)
    {
        if(max<all[i])
        {
            max=all[i];
            num=i+1;
        }
    }

    printf("%d %d",num,max);
}
