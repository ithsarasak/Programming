#include<bits/stdc++.h>
char code[10000], ans[10000], pres;
int i, len , counts, s;
int main()
{
     scanf("%s",code);
     int len = strlen( code );
     pres = code[0];
     counts = 1;
     for( i = 1 ; i < len ; i++ ){
        if( code[i] != pres ){
            ans[s] = pres;
            s++;
            if( counts > 1 ){
                ans[s] = counts + '0';
                s++;
            }
            pres = code[i];
            counts = 1;
        }
        else{
            counts++;
        }
     }
     ans[s] = pres;
     s++;
     if( counts > 1 ){
        ans[s] = counts + '0';
        s++;
     }
     for( i = 0 ; i < s ; i++ ){
        printf("%c",ans[i]);
     }
     return 0;
}
