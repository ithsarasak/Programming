#include<stdio.h>
#include<string.h>
struct person{
    int score;
    char name;
}person[7],temp;

char vote[20000]={};

int survivor=7;

main()
{
    int i,j,min,count;

    person[0].name='A';
    person[0].score=0;

    person[1].name='B';
    person[1].score=0;

    person[2].name='C';
    person[2].score=0;

    person[3].name='D';
    person[3].score=0;

    person[4].name='E';
    person[4].score=0;

    person[5].name='F';
    person[5].score=0;

    person[6].name='G';
    person[6].score=0;

    while(1)
    {
        scanf("%s",vote);
        int len;

        if(vote[0]=='!')
        {
            break;
        }

        len=strlen(vote);
        for(i=0;i<len;i++)
        {
            if(person[vote[i]-'A'].score!=99999999)
            {
                person[vote[i]-'A'].score++;
            }
        }
        /*for(i=0;i<7;i++)
        {
            //printf("%d ",person[i].score);
        }*/
        //printf("\n");
        if(survivor>1)
        {
            min=0;

            for(i=1;i<7;i++)
            {
                if(person[i].score<person[min].score&&person[i].score!=99999999)
                {
                    min=i;
                }
            }
            //printf("min:%d\n",min);
            for(i=0;i<7;i++)
            {
                count=0;
                if(person[i].score==person[min].score&&i!= min)
                {
                    count++;
                    break;
                }
            }
            //printf("count:%d\n",count);
            if(count==0)
            {
                person[min].score=99999999;
                //printf("person[%d].score:%d\n",min,person[min].score);

                survivor--;
            }
        }
        //printf("Survivor:%d\n",survivor);
        /*for(i=0;i<7;i++)
        {
            printf("%d ",person[i].score);
        }
        printf("\n");*/
    }

    for(i=0;i<6;i++)
    {
        for(j=0;j<6-i;j++)
        {
            if(person[j+1].score>person[j].score)
            {
                temp=person[j+1];
                person[j+1]=person[j];
                person[j]=temp;
            }
        }
    }
    printf("%d",survivor);

    for(i=0;i<7;i++)
    {
        if(person[i].score!=99999999)
        {
            if(person[i].score>30000) { printf("\n%c 30000",person[i].name); }

            else { printf("\n%c %d",person[i].name,person[i].score); }
        }
    }

    return 0;
}
