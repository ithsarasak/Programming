#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}
main()
{
    int s[4],i;

    for(i=0;i<4;i++)
    {
        scanf("%d",&s[i]);
    }

    qsort(s,4,sizeof(int),compare);

    printf("%d",s[0]*s[2]);
}
