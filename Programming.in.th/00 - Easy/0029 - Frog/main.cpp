#include<stdio.h>
main()
{
    int jump,dis;

    scanf("%d %d",&jump,&dis);

    if(dis%jump==0)
    {
        printf("%d",dis/jump);
    }
    else
    {
        if(dis<jump)
        {
            printf("%d",(dis/jump)+2);
        }
        else
        {
            printf("%d",(dis/jump)+1);
        }
    }
}
