#include<bits/stdc++.h>

using namespace std;
int t, x;
int base2[32];
int main()
{
    scanf("%d",&t);
    while( t-- ){
        int xt;
        scanf("%d",&xt);
        if( !xt ){
            printf("n");
            continue ;
        }
        int s = 0;
        x = abs( xt );
        while( x > 0 ){
            base2[s] = x % 2;
            x /= 2;
            s++;
        }
        int st = 0;
        for( int i = 0 ; i < s ; i++ ){
            if( st == 1 && base2[i] == 0 ){
                base2[i] = 1;
                st = 0;
            }
            else if( st == 1 ){
                base2[i] = 0;
            }
            if( base2[i] == 1 && base2[i + 1] == 1 ){
                st = 1;
                base2[i] = -1;
            }
        }
        if( st == 1 ){
            base2[s] = 1;
            s++;
        }
        for( int i = s - 1 ; i >= 0 ; i-- ){
            if( xt < 0 ){
                base2[i] *= -1;
            }
            if( base2[i] == 1 ){
                printf("p");
            }
            else if( base2[i] == 0 ){
                printf("n");
            }
            else{
                printf("e");
            }
        }
        printf("\n");
    }
}
