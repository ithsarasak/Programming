#include<stdio.h>
#include<string.h>

char word[300];

int palin( char word[] , int start , int size )
{
    int check = 1, j;
    for( j = start ; j < size ; j++ ){
        if( word[j] != word[size-j] ){
            check = 0;
            break;
        }
    }
    if( check ){
        return 1;
    }
    else{
        return 0;
    }
}
int doublepa( char word[] , int size )
{
    if( palin( word , 0 , ( size - 1 ) ) ){
        if( ( size % 2 ) == 0 ){
            if( palin( word , 0 , ( ( size / 2 ) - 1 ) ) && palin( word , ( size / 2 ) , ( size - 1 ) ) ){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            if( palin( word , 0 , ( ( size / 2 ) - 1 ) ) && palin( word , ( ( size / 2 ) + 1 ) , ( size - 1 ) ) ){
                return 1;
            }
            else if( palin( word , 0 , ( ( size / 2 ) ) ) && palin( word , ( ( size / 2 ) ) , ( size - 1 ) ) ){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    else{
        return 0;
    }
}
int main()
{
    int i;
    int len;

    scanf("%s",word);

    len = strlen( word );

    for( i = 0 ; i < len ; i++ ){
        if( ( word[i] >= 'A') && ( word[i] <= 'Z' ) ){
            word[i] += 32;
        }
    }
    if( doublepa( word , len ) ){
        printf("Double Palindrome\n");
    }
    else if( palin( word , 0 , ( len - 1 ) ) ){
        printf("Palindrome\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
