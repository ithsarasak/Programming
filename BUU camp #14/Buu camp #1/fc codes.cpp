#include<bits/stdc++.h>

using namespace std;

char code[100010][4];
int n, counts;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%s",code[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        for( int j = i + 1 ; j <n ; j++ ){
            if( code[i][0] == code[j][0] || code[i][1] == code[j][1] || code[i][2] == code[j][2] ){
                counts++;
            }
        }
    }
    printf("%d",counts);
    return 0;
}
