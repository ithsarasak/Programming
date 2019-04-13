#include<stdio.h>
struct node{
    int num;
    int amount;
}ans[1000],temp;

main()
{
    int amount,i,j,num[1000],count,marked[1000]={0},number;

    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ )
    {
        scanf("%d",&num[i]);
    }

    int k = 0;
    for( i = 0 ; i < amount ; i++ )
    {
        number = num[i];
        count=1;
        for( j = i + 1 ; j < amount ; j++)
        {
            if( number == num[j] )
            {
                count++;
                marked[j]=1;
            }
        }
        //printf("marked[%d] : %d\n",i,marked[i]);
        //printf("count : %d\n",count);
        if( !marked[i] )
        {
            ans[k].num=number;
            ans[k].amount=count;
            //printf("Ans[%d].amount : %d\n",k,ans[k].amount);
            //printf("Ans[%d].number : %d\n",k,ans[k].num);
            k++;
        }
    }
    //printf("k : %d\n",k);

    for( i = 0 ; i < k ; i++ )
    {
        for( j = i + 1 ; j < k ; j++ )
        {
            if( ans[i].amount < ans[j].amount )
            {
                temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
            else if( ans[i].amount == ans[j].amount )
            {
                if( ans[i].num > ans[j].num )
                {
                    temp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = temp;
                }
            }
        }
    }
    int max = ans[0].amount;

    /*for( i = 0 ; i < k ; i++ )
    {
        printf("%d ",ans[i].num);
    }*/
    printf("%d ",ans[0].num);

    for( i = 1 ; i < k ; i++ )
    {
        if( max == ans[i].amount )
        {
            printf("%d ",ans[i].num);
        }
    }
}
