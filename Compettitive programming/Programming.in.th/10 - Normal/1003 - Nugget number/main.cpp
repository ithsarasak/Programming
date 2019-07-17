#include<stdio.h>
main()
{
    int nuggetnum[101]={0};
    int num;
    int i,c=0;

    nuggetnum[6]=1;
    nuggetnum[9]=1;
    nuggetnum[20]=1;

    scanf("%d",&num);

    for(i=0;i<num+1;i++)
    {
        if(nuggetnum[i]==1)
        {
            if(i+20<=100)
            {
                nuggetnum[i+6]=1;
                nuggetnum[i+9]=1;
                nuggetnum[i+20]=1;
            }

            else if(i+9<=100)
            {
                nuggetnum[i+6]=1;
                nuggetnum[i+9]=1;
            }
            else if(i+6<=100)
            {
                nuggetnum[i+6]=1;
            }
        }
    }

    for(i=0;i<num+1;i++)
    {
        if(nuggetnum[i]==1)
        {
            if(i<=num)
            {
                printf("%d\n",i);
                c=1;
            }
        }
    }
    if(!c)
    {
        printf("no");
    }
}
