#include<stdio.h>
main()
{
    int pos1,pos2,pos3;

    scanf("%d %d %d",&pos1,&pos2,&pos3);

    if(pos2-pos1>pos3-pos2)
    {
        printf("%d",pos2-pos1-1);
    }
    else
    {
        printf("%d",pos3-pos2-1);
    }
}
