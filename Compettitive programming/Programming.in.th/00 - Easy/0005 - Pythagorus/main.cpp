#include<stdio.h>
#include<math.h>
main()
{
    double len1;
    double len2;

    scanf("%lf %lf",&len1,&len2);

    printf("%.6f",sqrt((len1*len1)+(len2*len2)));
}
