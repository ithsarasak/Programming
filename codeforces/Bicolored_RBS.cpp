#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, dep[N];
char s[N];
stack<int> st;
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for( int i = 0 ; i < n ; i++ ) {
        if( s[i] == ')' ) {
            int t = st.top(); st.pop();
            dep[i] = dep[t] = st.size() + 1;
        }
        else st.push( i );
    }
    for( int i = 0 ; i < n ; i++ ) {
        if( dep[i] % 2 ) printf("1");
        else printf("0");
    }
    return 0;
}