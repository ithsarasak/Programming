#include<bits/stdc++.h>

int base, s;
char n[100];
int palin( char b[] , int len , int c )
{
    if( c > 10 ){
        printf("NONE ");
        for( int i = len - 1 ; i >= 0 ; i-- ){
            printf("%c",b[i]);
        }
        exit( 0 );
    }
    char temp[101];
    int s = 0, tod = 0;
    for( int i = 0 ; i < len ; i++ ){
        int t1 , t2;
        if( b[i] >= 'A' ){
            t1 = b[i] - 'A' + 10;
        }
        else{
            t1 = b[i] - '0';
        }
        if( b[len - i - 1] >= 'A' ){
            t2 = b[len - i - 1] - 'A' + 10;
        }
        else{
            t2 = b[len - i - 1] - '0';
        }
        if( t1 + t2 + tod >= base ){
            int t = t1 + t2 + tod - base;
            if( t > 9 ){
                temp[s] = t - 10 + 'A';
            }
            else{
                temp[s] = t + '0';
            }
            tod = 1;
            s++;
        }
        else{
            int t = t1 + t2 + tod;
            if( t > 9 ){
                temp[s] = t - 10 + 'A';
            }
                else{
                temp[s] = t + '0';
            }
            s++;
            tod = 0;
        }
    }
    if( tod ){
        temp[s] = tod + '0';
        s++;
    }
    for( int i = 0 ; i < s / 2 ; i++ ){
        if( temp[i] != temp[s - i - 1] ){
            palin( temp , s , c + 1 );
        }
    }
    for( int i = 0 ; i < s ; i++ ){
        printf("%c",temp[i]);
    }
    exit( 0 );
}
int main()
{
    scanf("%s %d",n,&base);
    int len = strlen( n );

    for( int i = 0 ; i < len / 2 ; i++ ){
        if( n[i] != n[len - i - 1] ){
            palin( n , len , 1 );
        }
    }
    return 0;
}
