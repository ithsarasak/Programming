#include<stdio.h>
int n,i,x,num1=0,num2=0;
char a[1000010];

int main()
{
    scanf("%s",a);

    for(i = 0; a[i]; i++)
    {
        num1 += a[i] - '0';
        num2 += a[i] - '0';

        if(a[i + 1])
        {
            num1 *= 10;
            num2 *= 10;
        }

        num1 %= 3;
        num2 %= 11;
    }
    printf("%d %d\n",num1,num2);
}
