#include<stdio.h>
char adrain[101];
char bruno[101];
char goran[101];
main()
{
    int i,length,a=0,g=0,b=0,max=-1;
    char ans[101];

    for(i=1;i<101;i++)
    {
        if(i%3==1)
        {
            adrain[i-1]='A';
        }
        if(i%3==2)
        {
            adrain[i-1]='B';
        }
        if(i%3==0)
        {
            adrain[i-1]='C';
        }
        if(i%4==1)
        {
            bruno[i-1]='B';
        }
        if(i%4==2)
        {
            bruno[i-1]='A';
        }
        if(i%4==3)
        {
            bruno[i-1]='B';
        }
        if(i%4==0)
        {
            bruno[i-1]='C';
        }
        if(i%6==1)
        {
            goran[i-1]='C';
        }
        if(i%6==2)
        {
            goran[i-1]='C';
        }
        if(i%6==3)
        {
            goran[i-1]='A';
        }
        if(i%6==4)
        {
            goran[i-1]='A';
        }
        if(i%6==5)
        {
            goran[i-1]='B';
        }
        if(i%6==0)
        {
            goran[i-1]='B';
        }
    }

    //printf("%s\n",adrain);
    //printf("%s\n",bruno);
    //printf("%s\n",goran);
    scanf("%d",&length);
    scanf("%s",ans);

    for(i=0;i<length;i++)
    {
        if(goran[i]==ans[i])
        {
            //printf("%c ",ans[i]);
            g++;
        }
        if(adrain[i]==ans[i])
        {
            //printf("%c ",ans[i]);
            a++;
        }
        if(bruno[i]==ans[i])
        {
            //printf("%c ",ans[i]);
            b++;
        }
        //printf("\n");
    }
    if(max<a)
    {
        max=a;
    }
    if(max<b)
    {
        max=b;
    }
    if(max<g)
    {
        max=g;
    }

    printf("%d\n",max);
    if(max==a)
    {
        printf("Adrian\n");
    }
    if(max==b)
    {
        printf("Bruno\n");
    }
    if(max==g)
    {
        printf("Goran\n");
    }
}
