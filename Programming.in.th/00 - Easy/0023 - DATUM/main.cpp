#include <stdio.h>
main()
{
    int day,i;
    int month, sumday = 0;
    int amountday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    scanf("%d %d",&day,&month);

    for( i = 0 ; i < month - 1 ; i++ )
    {
        sumday = sumday + amountday[i];
    }
    sumday = sumday + day;

    if( sumday % 7 == 1)
    {
        printf("Thursday");
    }
    else if( sumday % 7 == 2)
    {
        printf("Friday");
    }
    else if( sumday % 7 == 3)
    {
        printf("Saturday");
    }
    else if( sumday % 7 == 4)
    {
        printf("Sunday");
    }
    else if( sumday % 7 == 5)
    {
        printf("Monday");
    }
    else if( sumday % 7 == 6)
    {
        printf("Tuesday");
    }
    else if( sumday % 7 == 0)
    {
        printf("Wednesday");
    }
}
