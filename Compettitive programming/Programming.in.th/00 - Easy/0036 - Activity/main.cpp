#include <stdio.h>
int main()
{
    int num;

    scanf("%d",&num);

    if( num == 1 )
    {
        printf("2");
    }
    else
    {
        int help,i;

        if( num % 2 == 1 )
        {
            help = num / 2;

            int diff;

            diff = num - help;
            //printf("%d %d %d\n",num,help,diff);

            long long  ans1 = 1 , ans3 = 1;

            for( i = help + 1 ; i <= num ; i++ )
            {
                ans1 = ans1 * i;
            }
            for( i = 1 ; i <= diff ; i++ )
            {
                ans3 = ans3 * i;
            }
            long long ans ;

            ans = ans1 / ans3;

            printf("%lld",2*ans);
        }
        else
        {
            help = num / 2;

            int diff;

            diff = num - help;
            //printf("%d %d %d\n",num,help,diff);

            long long  ans1 = 1 , ans3 = 1;

            for( i = help + 1 ; i <= num ; i++ )
            {
                ans1 = ans1 * i;
            }
            for( i = 1 ; i <= diff ; i++ )
            {
                ans3 = ans3 * i;
            }
            long long ans ;
            ans = ans1 / ans3;
            printf("%lld",ans);
        }
    }
    return 0;
}
