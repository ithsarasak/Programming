#include<stdio.h>
main()
{
    int num[20];
    int a[42]={};
    int i;
    int count=0;

    for(i=0;i<10;i++)
    {
        scanf("%d",&num[i]);
    }

    for(i=0;i<10;i++)
    {
        if(a[num[i]%42]==0)
        {
            a[num[i]%42]=1;
            count++;
        }
    }
    printf("%d",count);
}
