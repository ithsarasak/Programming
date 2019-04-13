#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 500;
char s[N], t[N];
int lps[N], a[3], one2, zero2;
void clearq()
{
    for(;a[0];a[0]--)printf("0");
    for(;a[1];a[1]--)printf("1");
}
int main()
{
	scanf("%s %s",s,t);
	int len = strlen( s ), len2 = strlen( t );
	for( int i = 0 ; i < len ; i++ ){
		if( s[i] == '1' )a[1]++;
		else a[0]++;
	}
	for( int i = 0 ; i < len2 ; i++ ){
		if( t[i] == '1' )one2++;
		else zero2++;
	}
	int now = 0; 
  	lps[0] = 0;
    int i = 1; 
    while ( i < len2 ){ 
        if (t[i] == t[now]) { 
            now++; 
            lps[i] = now; 
            i++; 
        } 
        else 
        {
            if( now != 0 ) { 
                now = lps[now - 1];
            } 
            else{ 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
    
    if( a[0] < zero2 || a[1] < one2 ){
    	printf("%s",s);
    	return 0;
    }
    printf("%s",t);
    a[0] -= zero2, a[1] -=one2;
    int j;
    for( j = lps[len2-1] ; ; )
	{
        if(a[t[j]-'0']<=0)
        {
            clearq();
            return 0 ;
        }
        cout << t[j];
        a[t[j]-'0']--;
        j++;
        if(j==len2) j = lps[len2-1]; 
 	}
 	return 0;
}