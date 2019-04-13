#include<stdio.h>
#include<string.h>

int i, count, sum;
char parenthesis[201];
int main()
{
    scanf("%s",parenthesis);

    int len = strlen( parenthesis );

    for( i = 0 ; i < len ; i++ ){
        if( parenthesis[i] == '(' ){
                sum += 1;
        }
        else
        {
            if( sum == 0 ){
                count++;
            }
            else{
                 sum -= 1;
            }
        }
    }
    if( sum != 0 )
    {
        count += sum;
    }
    printf("%d",count);
}

