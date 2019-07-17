#include<stdio.h>
#include<string.h>
main()
{
	int a, b, i, j, k = 0, c[2][1000];
	char x[1000];

	scanf("%s",x);

	a = strlen( x );

	if( a %2 == 0 ){
        b = a / 2;
	}
	if( a % 2 == 1 ){
        b = ( a - 1 ) / 2;
	}
	for( i = 0 ; i < 130 ; i++ ){
		c[0][i] = 0;
		c[1][i] = 0;
	}
	for( i = 0 ; i < b ; i++ ){
		c[0][x[i]]++;
	}
	for( i = b + 1 ; i < a ; i++ ){
		c[1][x[i]]++;
	}
	for( i = 0 ; i < 130 ; i++ ){
		if( c[0][i] == c[1][i] && c[0][i] != 0 ){
            k = k + 2 * ( c[0][i] );
		}
		else if( c[0][i] != 0 && c[1][i] != 0 ){
			if( c[0][i] > c[1][i] ){
                k = k + 2 * c[1][i];
			}
			if( c[0][i] < c[1][i] ){
                k = k + 2 * c[0][i];
			}
		}
	}
	printf("%d",k+1);
}
