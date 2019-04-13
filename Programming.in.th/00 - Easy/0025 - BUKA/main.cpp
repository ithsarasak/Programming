#include<stdio.h>
#include<string.h>
int first[200],last[200],ans[200];
int i;
int main()
{
    char input1[100];

    scanf("%s",input1);

    int len;
    len = strlen(input1);

    for( i = 0 ; i < len ; i++ )
    {
        first[100-len+i] = input1[i] - '0';
    }

    char op;

    scanf(" %c",&op);
    char input2[100];

    scanf("%s",input2);

    int len2 = strlen(input2);

    for( i = 0 ; i < len2 ; i++ )
    {
        last[100-len2+i] = input2[i] - '0';
    }

    if( op == '*' )
    {
        bool c = false;
        int count = 0 ;
        for( i = 0 ; i < 100 ; i++ )
        {
            if( c )
            {
                count++;
            }
            else if( first[i] == 1 )
            {
                c = true;
            }
        }
        c = false;
        for( i = 0 ; i < 100 ; i++ )
        {
            if( c )
            {
                count++;
            }
            else if( last[i] == 1 )
            {
                c = true;
            }
        }
        ans[ 199 - count ] = 1;
        c = false;
        for( i = 0 ; i < 200 ; i++ )
        {
            if( c )
            {
                printf("%d",ans[i]);
            }
            else if( ans[i] == 1 )
            {
                printf("%d",ans[i]);
                c = true;
            }
        }
    }
    else
    {
        bool c = false;
        for( i = 0 ; i < 100 ; i++ )
        {
            ans[i] = first[i] + last[i];
        }
        /*for( i = 0 ; i < 100 ; i++ )
        {
            printf("%d",first[i]);
        }
        printf("\n");
        for( i = 0 ; i < 100 ; i++ )
        {
            printf("%d",last[i]);
        }
        printf("\n");
        for( i = 0 ; i < 100 ; i++ )
        {
            printf("%d",ans[i]);
        }
        printf("\n");*/
        for( i = 0 ; i < 100 ; i++ )
        {
            if( c )
            {
                printf("%d",ans[i]);
            }
            else if( ans[i] > 0 )
            {
                printf("%d",ans[i]);
                c = true;
            }
        }
    }
    return 0;
}
