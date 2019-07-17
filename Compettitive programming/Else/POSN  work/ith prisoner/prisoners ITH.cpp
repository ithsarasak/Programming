#include<bits/stdc++.h>

using namespace std;

vector< int > people;
int n, m, c = 1, i;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        people.push_back( i );
    }
    while( !people.empty() ){
        if( c == m ){
            printf("%d ",people[i]);
            c = 1;
            people.erase( people.begin() + i );
            if( i == people.size() ){
                i = 0;
            }
        }
        else{
            c++;
            i++;
            if( i == people.size() ){
                i = 0;
            }
        }
    }
    return 0;
}
