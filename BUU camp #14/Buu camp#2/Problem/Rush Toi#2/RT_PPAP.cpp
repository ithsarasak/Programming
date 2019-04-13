#include<bits/stdc++.h>

using namespace std;
char help[5000000];
int si, q;
int main()
{
    help[0] = 'P';
    help[1] = 'P';
    help[2] = 'A';
    help[3] = 'P';
    si = 4;
    while( si <= 1500000 ){
        int t = si;
        help[si] = 'P';
        si++;
        if( si > 1500000 ){
                break;
            }
        for( int i = 0 ; i < t ; i++ ){
            if( si > 1500000 ){
                break;
            }
            if( help[i] == 'A' ){
                help[si] = 'P';
            }
            else{
                help[si] = 'A';
            }
            si++;
        }
        if( si > 1500000 ){
                break;
            }
        for( int i = 0 ; i < t ; i++ ){
            help[si] = help[i];
            si++;
        }
        if( si > 1500000 ){
                break;
            }
    }
    scanf("%d",&q);
    while( q-- ){
        long long n;
        scanf("%lld",&n);
        printf("%c\n",help[n - 1]);
    }
}
