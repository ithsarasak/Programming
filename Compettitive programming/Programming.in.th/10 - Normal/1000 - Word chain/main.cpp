#include<stdio.h>
#include<string.h>
char word[30001][1001];
main()
{
    int n,l,i,j,count=0,c=1;

    scanf("%d %d",&n,&l);
    for(i=0;i<l;i++)
    {
        scanf("%s",word[i]);
    }
    for(i=0;i<l-1;i++)
    {
        count=0;
        //printf("%s ",word[i]);
        for(j=0;j<n;j++)
        {
            if(word[i][j]!=word[i+1][j])
            {
                count++;
            }
        }
        //printf("%d ",count);
        if(count>=3)
        {
            printf("%s",word[i]);
            c=0;
            break;
        }
    }
    if(c)
    {
        printf("%s",word[l-1]);
    }
}
