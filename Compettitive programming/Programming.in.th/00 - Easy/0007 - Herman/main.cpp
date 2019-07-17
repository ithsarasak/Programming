#include<stdio.h>
#include<math.h>
main()
{
    const long double pi=3.14159265358979323846;
    double input;
    double area1;
    double area2;

    scanf("%lf",&input);

    area1=pi*input*input;
    area2=2*input*input;

    printf("%lf\n",area1);
    printf("%lf\n",area2);
}
