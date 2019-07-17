#include<stdio.h>
#include<string.h>
#include<math.h>
int findnumber( char str[][80] , int n )
{
    int i, k, j, value, base10, check;
    long long sum = 0;

    char strnum[10], *p, number[][80]={ " _ | ||_|", "     |  |", " _  _||_ ",
                                       " _  _| _|", "   |_|  |", " _ |_  _|",
                                       " _ |_ |_|", " _   |  |", " _ |_||_|",
                                       " _ |_| _|"};
    if( str[0][0] == 0 ){
        for( i = 0 ; i < n * 3 + ( n - 1 ) ; i++ ){
            str[0][i] = ' ';
        }
        str[0][ n * 3 + ( n - 1 ) ]='\0';
    }
    if( str[0][ ( 3 * n ) + ( n - 2 ) ] == '\0' ){
        str[0][ ( 3 * n ) + ( n - 2 ) ] = ' ';
        str[0][ ( 3 * n ) + ( n - 1 ) ] = '\0';
    }
    if( str[1][ ( 3 * n ) + ( n - 2 ) ] == '\0' ){
        str[1][ ( 3 * n ) + ( n - 2 ) ] = ' ';
        str[1][ ( 3 * n ) + ( n - 1 ) ] = '\0';
    }
    if( str[2][ ( 3 * n ) + ( n - 2 ) ] == '\0' ){
        str[2][ ( 3 * n ) + ( n - 2 ) ] = ' ';
        str[2][ ( 3 * n ) + ( n - 1 ) ] = '\0';
    }

    base10 = ( int )pow( 10 , n - 1 );

    base10 = ( base10 % 9 == 0 ) ? base10 + 1 : base10;

    //printf("%d",base10);

    for( k = 0 ; k < n ; k++ ){
        check = 0;
        for( i = 0 ; i < 3  ; i++ ){
            for( j = 0 ; j < 3 ; j++ ){
                strnum[check] = str[i][ j + ( k * 3 ) + k ];
                check++;
            }
        }
        strnum[9] = 0;
        /*for( j = 0 ; j < 9 ; j++ ){
            printf("%d ",strnum[j]);
        }
        printf("\n");
        for( j = 0 ; j < 9 ; j++ ){
            printf("%d ",number[6][j]);
        }
        printf("\n");*/
        for( i = 0 ; i < 10 ; i++ ){
            if( strcmp( strnum, number[i] ) == 0 ){
                value = i;
            }
        }
        sum += value * base10;

        base10 /= 10;
    }
    return sum;
}
int main(){
    char str1[3][80], str2[3][80];

    int i, n, m;
    long long num1, num2;

    scanf("%d %d",&n,&m);

    gets( str1[0] );

    for( i = 0 ; i < 3 ; i++ ){
        gets( str1[i] );
    }
    num1 = findnumber( str1 , n );

    for( i = 0 ; i < 3 ; i++ ){
        gets( str2[i] );
    }

    num2 = findnumber( str2 , m );

    printf("%lld", num1 + num2 );
}


