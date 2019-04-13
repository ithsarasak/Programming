#include<stdio.h>

char di[101];
int i, len, lost, n, w, e, s, maxx, maxy, sum1, sum2;
int main()
{
    scanf("%s",di);

    while( di[len] != '\0' ){
        if( di[len] == 'N' ){
            n++;
        }
        else if( di[len] == 'S' ){
            s++;
        }
        else if( di[len] == 'E' ){
            e++;
        }
        else if( di[len] == 'W' ){
            w++;
        }
        len++;
    }
    scanf("%d",&lost);
   if( n >= s && e >= w ){
        sum1 = n + e;
        sum2 = s + w;
   }
   else if( n >= s && e < w ){
        sum1 = n + w;
        sum2 = s + e;
   }
   else if( n < s && e >= w ){
        sum1 = s + e;
        sum2 = n + w;
   }
   else if( n < s && e < w ){
        sum1 = s + w;
        sum2 = n + e;
   }
   if( sum2 < lost ){
        lost -= sum2;
        sum2 = 0;
        sum1 -= lost;
   }
   else{
        sum2 -= lost;
   }
   printf("%d",2 * ( sum1 - sum2 ) );
   return 0;
}
