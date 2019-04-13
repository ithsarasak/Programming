#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}
main()
{
    int num,area[1000],i,j,k,min=10000,sum1=0,sum2=0,sum3=0,pos1,pos2;

    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        scanf("%d",&area[i]);
    }

    for(i=1;i<=num;i++)
    {
        sum1=0;
        j=i+1;
        sum2=0;
        sum3=0;
        for(k=0;k<i;k++)
        {
            sum1=sum1+area[k];
        }
        for(k=i;k<j;k++)
        {
            sum2=sum2+area[k];
        }
        for(k=j;k<num;k++)
        {
            sum3=sum3+area[k];
        }
        for(j;j<=num;j++)
        {
            int all[3];

            all[0]=sum1;
            all[1]=sum2;
            all[2]=sum3;
            //printf("%d %d %d\n",sum1,sum2,sum3);

            qsort(all,3,sizeof(int),compare);

            if(min>all[2]-all[0])
            {
                min=all[2]-all[0];
                pos1=i+1;
                pos2=j+1;
            }
            if(min==0)
            {
                break;
            }
            sum2=sum2+area[j];
            sum3=sum3-area[j];
        }
    }
    printf("%d %d",pos1,pos2);
}
