#include<stdio.h>
#include<string.h>
int win,lose,judge,i;
char ans[200001];
int result(int win,int lose,int max_char,int max_result,char round,int check)
{
    if(win>judge||lose>judge)
    {
        return 0;
    }
    if(check!=0)
        ans[check] = round;

    //printf("win:%d lose:%d max_char:%d max_result:%d round:%c check:%d\n",win,lose,max_char,max_result,round,check);
    //printf("judge:%d\n",judge);
    //printf("ans[%d]:%c\n",check,ans[check]);

    if(win==judge||lose==judge)
    {
        //printf("In\n");
        int len;

        len = strlen(ans);

        //printf("len:%d\n",len);
        for(i = 1 ;i <= check ; i++)
        {
            printf("%c ",ans[i]);
            max_char++;
        }
        max_result++;
        printf("\n");
        return 0;
    }

    result(win+1,lose,max_char,max_result,'W',check+1);
    result(win,lose+1,max_char,max_result,'L',check+1);
}
main()
{
    scanf("%d",&judge);
    scanf("%d",&win);
    scanf("%d",&lose);
    result(win,lose,0,0,'W',0);
}
