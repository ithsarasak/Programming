#include<stdio.h>
main()
{
    int maxint=2000000000;
    int max=-maxint;
    int min=maxint;
    int i,j;

    scanf("%d",&i);

    int a[i];

    for(j=0;j<i;j++)
    {
        scanf("%d",&a[j]);
    }
    for(j=0;j<i;j++)
    {
        if(max<a[j])
        {
            max=a[j];
        }
        if(min>a[j])
        {
            min=a[j];
        }
    }

    printf("%d\n",min);
    printf("%d",max);
}
