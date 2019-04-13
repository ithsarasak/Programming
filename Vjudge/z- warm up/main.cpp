#include<bits/stdc++.h>

using namespace std;

int a, b;
int main()
{
    scanf("%d %d",&a,&b);
    if( b == 0 ){
        printf("1");
    }
    else if( a % 10  == 0 ){
        printf("0");
    }
    else if( a % 10 == 1 ){
        printf("1");
    }
    else if( a % 10 == 2 ){
        if( b % 4 == 1 ){
            printf("2");
        }
        else if( b % 4 == 2 ){
            printf("4");
        }
        else if( b % 4 == 3 ){
            printf("8");
        }
        else{
            printf("6");
        }
    }
    else if( a % 10 == 3 ){
        if( b % 4 == 1 ){
            printf("3");
        }
        else if( b % 4 == 2 ){
            printf("9");
        }
        else if( b % 4 == 3 ){
            printf("7");
        }
        else{
            printf("1");
        }
    }
    else if( a % 10 == 4 ){
        if( b % 2 == 1 ){
            printf("4");
        }
        else{
            printf("6");
        }
    }
    else if( a % 10 == 5 ){
        printf("5");
    }
    else if( a % 10 == 6 ){
        printf("6");
    }
    else if( a % 10 == 7 ){
       if( b % 4 == 1 ){
            printf("7");
        }
        else if( b % 4 == 2 ){
            printf("9");
        }
        else if( b % 4 == 3 ){
            printf("3");
        }
        else{
            printf("1");
        }
    }
    else if( a % 10 == 8 ){
        if( b % 4 == 1 ){
            printf("8");
        }
        else if( b % 4 == 2 ){
            printf("4");
        }
        else if( b % 4 == 3 ){
            printf("2");
        }
        else{
            printf("6");
        }
    }
    else if( a % 10 == 9 ){
        if( b % 2 == 1 ){
            printf("9");
        }
        else{
            printf("1");
        }
    }
    return 0;
}
