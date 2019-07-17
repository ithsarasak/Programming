#include<bits/stdc++.h>

using namespace std;
set<string> all;
char a[30];
set<string>::iterator it, it2;
int n;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%s",a);
        all.insert( a );
        it = it2 = all.lower_bound( a );
        if( it == all.begin() ){
            printf("N/A ");
        }
        else{
            it--;
            string aa = *it;
            printf("%s ",aa.c_str());
        }
        it2++;
        if( it2 == all.end() ){
            printf("N/A");
        }
        else{
            string aa = *it2;
            printf("%s",aa.c_str());
        }
        printf("\n");
    }
}
