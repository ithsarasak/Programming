#include<stdio.h>
struct x{
    long long num = 0;
    char name;
}all[26];
int i = 26, j, k;
char op;
int main()
{
    for( j = 0 ; j < 26 ; j++ )
    {
        all[j].name = j + 'A';
        all[j].num = 0;
    }
    while( op != '!' )
    {
        scanf(" %c",&op);

        if( op == '=' )
        {
            char ch;
            int kar;

            //*printf("%d",i);
            scanf(" %c %d",&ch,&kar);
            //printf("%c %d\n",ch,kar);

            for( j = 0 ; j < i ; j++ )
            {
                if( all[j].name == ch )
                {
                    all[j].num = kar;
                }
            }
        }
        else if( op == '#' )
        {
            //printf("%c %d\n",all[0].name,all[0].num);
            char ch;

            scanf(" %c",&ch);

            for( j = 0 ; j < i ; j++ )
            {
                //printf("%d",j);
                if( all[j].name == ch )
                {
                    printf("%d\n",all[j].num);
                    break;
                }
            }
        }
        else if( op == '*' )
        {
            int pos1, pos2;
            char first, second;

            scanf(" %c %c",&first,&second);

            for( j = 0 ; j < i ; j++ )
            {
                if( all[j].name == first )
                {
                    pos1 = j;
                }
                if( all[j].name == second )
                {
                    pos2 = j;
                }
            }

            all[pos1].num *= all[pos2].num;
        }
        else if( op == '/' )
        {
            int pos1, pos2;
            char first, second;

            scanf(" %c %c",&first,&second);

            for( j = 0 ; j < i ; j++ )
            {
                if( all[j].name == first )
                {
                    pos1 = j;
                }
                if( all[j].name == second )
                {
                    pos2 = j;
                }
            }

            all[pos1].num /= all[pos2].num;
        }
        else if( op == '+' )
        {
            int pos1, pos2;
            char first, second;

            scanf(" %c %c",&first,&second);

            for( j = 0 ; j < i ; j++ )
            {
                if( all[j].name == first )
                {
                    pos1 = j;
                }
                if( all[j].name == second )
                {
                    pos2 = j;
                }
            }

            all[pos1].num += all[pos2].num;
        }
        else if( op == '-' )
        {
            int pos1, pos2;
            char first, second;

            scanf(" %c %c",&first,&second);

            for( j = 0 ; j < i ; j++ )
            {
                if( all[j].name == first )
                {
                    pos1 = j;
                }
                if( all[j].name == second )
                {
                    pos2 = j;
                }
            }

            all[pos1].num -= all[pos2].num;
        }
    }
    printf("!");
    return 0;
}
