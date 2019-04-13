#include<bits/stdc++.h>

using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    while( n-- ){
        string s;
        cin >> s;
        int l = s.length();
        int st = 0, si = 0;
        string sa[110];
        for( int i = 0 ; i < l ; i++ ){
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
                sa[si] += s[i];
                st |= 1;
            }
            else if( st == 1 && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' ){
                si++;
                st = 0;
            }
        }
        if( s[l-1] == 'a' || s[l-1] == 'e' || s[l-1] == 'i' || s[l-1] == 'o' || s[l-1] == 'u' ){
            si++;
        }
        st = 0;
        int cnt = 0;
        /*for( int i = 0 ; i < si ; i++ ){
            cout << sa[i] << endl;
        }*/
        swap( sa[0], sa[si-1] );
        for( int i = 0 ; i < l ; i++ ){
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
                if( st == 0 ){
                    cout << sa[cnt];
                    cnt++;
                    st = 1;
                }
            }
            else{
                st = 0;
                cout << s[i];
            }
        }
        printf("\n");
    }
    return 0;
}
