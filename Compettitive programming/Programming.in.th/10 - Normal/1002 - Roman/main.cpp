#include<stdio.h>
main()
{
    int counti=0,countv=0,countx=0,countl=0,countc=0;
    int page,support;
    int i,j;

    scanf("%d",&page);

    support=page;

    for(i=page;i>0;i--)
    {
        support=i;
        while(support>0)
        {
            if(support>=100)
            {
                support=support-100;
                countc++;
            }
            else if(support>=90)
            {
                support=support-90;
                countc++;
                countx++;
            }
            else if(support>=50)
            {
                support=support-50;
                countl++;
            }
            else if(support>=40)
            {
                support=support-40;
                countl++;
                countx++;
            }
            else if(support>=10)
            {
                support=support-10;
                countx++;
            }
            else if(support==9)
            {
                support=0;
                countx++;
                counti++;
            }
            else if(support>=5)
            {
                support=support-5;
                countv++;
            }
            else if(support==4)
            {
                support=0;
                counti++;
                countv++;
            }
            else if(support==3)
            {
                support=0;
                counti=counti+3;
            }
            else if(support==2)
            {
                support=0;
                counti=counti+2;
            }
            else if(support==1)
            {
                support=0;
                counti++;
            }
        }
    }
            /*while(support>0)
            {
                if(support>=100)
                {
                    support=support-100;
                    printf("c");
                }
                else if(support>=90)
                {
                    support=support-90;
                    printf("xc");
                }
                else if(support>=50)
                {
                    support=support-50;
                    printf("l");
                }
                else if(support>=40)
                {
                    support=support-40;
                    printf("xl");
                }
                else if(support>=10)
                {
                    support=support-10;
                    printf("x");
                }
                else if(support==9)
                {
                    support=0;
                    printf("ix");
                }
                else if(support>=5)
                {
                    support=support-5;
                    printf("v");
                }
                else if(support==4)
                {
                    support=0;
                    printf("iv");
                }
                else if(support==3)
                {
                    support=0;
                    printf("iii");
                }
                else if(support==2)
                {
                    support=0;
                    printf("ii");
                }
                else if(support==1)
                {
                    support=0;
                    printf("i");
                }
            }*/
        printf("%d %d %d %d %d",counti,countv,countx,countl,countc);
}
