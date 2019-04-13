#include<stdio.h>
#include<string.h>
main()
{
    char sentence[101];
    char ans[101];
    int i,j,len,count=0;

    gets(sentence);

    len=strlen(sentence);

    for(i=0;i<len;i++)
    {
        if(sentence[i]=='p'&&i!=0&&i!=len-1)
        {
            if(sentence[i-1]==sentence[i+1]&&(sentence[i-1]=='a'||sentence[i-1]=='e'||sentence[i-1]=='i'||sentence[i-1]=='o'||sentence[i-1]=='u'))
            {
                sentence[i]='.';
                sentence[i+1]='.';
                i++;
            }
        }
    }
    //printf("%s\n",sentence);
    j=0;
    for(i=0;i<len;i++)
    {
        if(sentence[i]!='.')
        {
            ans[j]=sentence[i];
            //printf("%c",ans[j]);
            count++;
            j++;
        }
    }

    for(i=0;i<count;i++)
    {
        printf("%c",ans[i]);
    }
}
