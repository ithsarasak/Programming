#include<bits/stdc++.h>

using namespace std;
int len, co;
string s;
int main()
{
    scanf("%d",&len);
    cin >> s;
    for( int i = 0 ; i < len ; i++ ){
        if( s[i] == 'S' ){
            if( i <= len - 8 ){
                string a = s.substr( i, 8 );
                if( a == "SPACEBAR" ){
                    co++;
                    i += 7;
                    continue ;
                }
            }
            if( i <= len - 5 ){
                string a = s.substr( i, 5 );
                if( a == "SHIFT" ){
                    co++;
                    i += 4;
                    continue;
                }
            }
            co++;
        }
        else if( s[i] == 'Q' || s[i] == 'W' || s[i] == 'E' || s[i] == 'A' || s[i] == 'D' || s[i] == 'V' ){
            co++;
        }
    }
    printf("%d",co);
    return 0;
}