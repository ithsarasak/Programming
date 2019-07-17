#include<stdio.h>
#include<string.h>
main()
{
    int pos=1;
    char change[50];
    int len,i;

    scanf("%s",change);

    len=strlen(change);

    for(i=0;i<len;i++)
    {
        if(pos==1&&change[i]=='A')
        {
            pos=2;
        }
        else if(pos==2&&change[i]=='A')
        {
            pos=1;
        }
        else if(pos==3&&change[i]=='B')
        {
            pos=2;
        }
        else if(pos==3&&change[i]=='C')
        {
            pos=1;
        }
        else if(pos==2&&change[i]=='B')
        {
            pos=3;
        }
        else if(pos==1&&change[i]=='C')
        {
            pos=3;
        }
    }
    printf("%d",pos);
}
