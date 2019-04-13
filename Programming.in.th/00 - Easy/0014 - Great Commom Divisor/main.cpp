#include<stdio.h>
main()
{
    int i;
    int num1,num2;
    int temp;
    int gcd;

    scanf("%d %d",&num1,&num2);
    if(num1>num2)
    {
        temp=num1;
        num1=num2;
        num2=temp;
    }
    for(i=1;i<=num1;i++)
    {
        if(num1%i==0&&num2%i==0)
        {
            gcd=i;
        }
    }
    printf("%d",gcd);
}
