#include<stdio.h>
#include<string.h>
char num[1000000];
int numint[1000000];
main()
{
    scanf("%s",num);

    int len,i;

    len=strlen(num);

    for(i=0;i<len;i++)
    {
        numint[i]=num[i]-'0';
    }

    int sumt=0,sume=0,hs1=0,hs2=0;

    for(i=0;i<len;i++)
    {
        sumt=sumt+numint[i];
        if(i%2==0)
        {
            hs1=hs1+numint[i];
        }
        else
        {
            hs2=hs2+numint[i];
        }
    }

    if(len%2==1)
    {
        sume=hs1-hs2;
    }
    else
    {
        sume=hs2-hs1;
    }

    if(sume<=-11)
    {
        sume=sume%11;
        sume=sume+11;
        sume=sume%11;
    }
    else if(sume<0)
    {
        sume=sume+11;
        sume=sume%11;
    }
    else
    {
        sume=sume%11;
    }
    printf("%d %d",sumt%3,sume);

}
