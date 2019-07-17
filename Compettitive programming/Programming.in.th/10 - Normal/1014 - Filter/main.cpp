#include<stdio.h>
main()
{
    int x;
    int y;
    int i,j;
    int cur,count1=0,count2=0;

    scanf("%d %d %d",&y,&x,&cur);


    int curtain[100][100]={{0}};//={{},{}};
    int shadow1[cur],shadow2[cur];

    for(i=0;i<cur;i++)
    {
        scanf("%d %d",&shadow1[i],&shadow2[i]);
    }

    for(i=0;i<cur;i++)
    {
        for(j=shadow1[i];j<shadow1[i]+shadow2[i];j++)
        {
            curtain[0][j]++;
        }
    }

    for(i=0;i<y;i++)
    {
        if(curtain[0][i]==1)
        {
            count1++;
        }
        else if(curtain[0][i]==0)
        {
            count2++;
        }
    }
    printf("%d %d",count2*x,count1*x);
}
