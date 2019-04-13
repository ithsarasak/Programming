#include<bits/stdc++.h>

using namespace std;

int l = 0, r = 99, c;
int main()
{
    printf("------INSTRUCTION------\n0.less than this number\n1.RIGHT NUMBER\n2.more than this number\n");
    while( l <= r ){
        int m = ( l + r ) / 2;
        printf("This number : %d?\nRight? : ",m);
        scanf("%d",&c);
        if( c == 0 ){
            r = m - 1;
        }
        else if( c == 2 ){
            l = m + 1;
        }
        else{
            printf("Mindreader xD");
            return 0;
        }
    }
}
