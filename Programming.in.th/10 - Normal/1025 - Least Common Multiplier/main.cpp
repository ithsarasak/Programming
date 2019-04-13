#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
    return(* ( int * )a-* ( int * )b);
}
main()
{
    int num[50001];
    int i,j,k,amount;
    long long lcm=1;

    scanf("%d",&amount);

    for(i=0;i<amount;i++)
    {
        scanf("%d",&num[i]);
    }
    /*for(j=0;j<amount;j++)
        {
            printf("%d ",num[j]);
        }*/
    qsort(num,amount,sizeof(int),compare);
    i=2;
    int max=num[amount-1];
    while(i<=max)
    {
        //printf("%d\n",i);
        /*for(j=0;j<amount;j++)
        {
            printf("%d ",num[j]);
        }*/
        int count=0;
        for(j=0;j<amount;j++)
        {
            if(num[j]%i==0)
            {
                count++;
            }
        }
        //printf("%d\n",count);
        if(count>=2)
        {
            for(j=0;j<amount;j++)
            {
                if(num[j]%i==0)
                {
                    num[j]=num[j]/i;
                }
            }
            lcm=lcm*i;
        }
        else
        {
            i++;
        }
        /*for(j=0;j<amount;j++)
        {
            printf("%d ",num[j]);
        }*/
        //printf("\n");
        //printf("%d ",i);
        //printf("%d\n",num[amount-1]);
        //break;
    }
    for(i=0;i<amount;i++)
    {
        lcm=lcm*num[i];
    }
    printf("%ld",lcm);
}
