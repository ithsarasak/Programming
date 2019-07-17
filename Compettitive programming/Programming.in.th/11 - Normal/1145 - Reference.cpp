#include<bits/stdc++.h>

using namespace std;
map<string,int> m1, m2, m3, m4;
char s1[60], s2[60], s3[60], s4[60];
int len;
string ans;
int main()
{
    scanf("%s %s %s %s",s1,s2,s3,s4);
    int len1 = strlen( s1 );
    int len2 = strlen( s2 );
    int len3 = strlen( s3 );
    int len4 = strlen( s4 );
    for( int i = 0 ; i < len1 ; i++ )s1[i] = tolower( s1[i] );
    for( int i = 0 ; i < len2 ; i++ )s2[i] = tolower( s2[i] );
    for( int i = 0 ; i < len3 ; i++ )s3[i] = tolower( s3[i] );
    for( int i = 0 ; i < len4 ; i++ )s4[i] = tolower( s4[i] );
    for( int i = 0 ; i < len1 ; i++ ){
        string sth = "";
        for( int j = i ; j < len1 ; j++ ){
            sth += s1[j];
            m1[sth] = 1;
        }
    }
    for( int i = 0 ; i < len2 ; i++ ){
        string sth = "";
        for( int j = i ; j < len2 ; j++ ){
            sth += s2[j];
            m2[sth] = 1;
        }
    }
    for( int i = 0 ; i < len3 ; i++ ){
        string sth = "";
        for( int j = i ; j < len3 ; j++ ){
            sth += s3[j];
            m3[sth] = 1;
        }
    }
    for( int i = 0 ; i < len4 ; i++ ){
        string sth = "";
        for( int j = i ; j < len4 ; j++ ){
            sth += s4[j];
            m4[sth] = 1;
        }
    }
    for( map<string,int>::iterator it = m1.begin() ; it != m1.end() ; it++ ){
        string a = it -> first;
        int c = 0;
        if( m1[a] )c++;
        if( m2[a] )c++;
        if( m3[a] )c++;
        if( m4[a] )c++;
        if( c >= 3 ){
            if( a.length() > len ){
                ans = a;
                len = a.length();
            }
        }
    }
    for( map<string,int>::iterator it = m2.begin() ; it != m2.end() ; it++ ){
        string a = it -> first;
        int c = 0;
        if( m1[a] )c++;
        if( m2[a] )c++;
        if( m3[a] )c++;
        if( m4[a] )c++;
        if( c >= 3 ){
            if( a.length() > len ){
                ans = a;
                len = a.length();
            }
        }
    }
    for( map<string,int>::iterator it = m3.begin() ; it != m3.end() ; it++ ){
        string a = it -> first;
        int c = 0;
        if( m1[a] )c++;
        if( m2[a] )c++;
        if( m3[a] )c++;
        if( m4[a] )c++;
        if( c >= 3 ){
            if( a.length() > len ){
                ans = a;
                len = a.length();
            }
        }
    }
    for( map<string,int>::iterator it = m4.begin() ; it != m4.end() ; it++ ){
        string a = it -> first;
        int c = 0;
        if( m1[a] )c++;
        if( m2[a] )c++;
        if( m3[a] )c++;
        if( m4[a] )c++;
        if( c >= 3 ){
            if( a.length() > len ){
                ans = a;
                len = a.length();
            }
        }
    }
    cout << ans;
    return 0;
}
