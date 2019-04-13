#include<bits/stdc++.h>

using namespace std;
int t;
int main()
{
    scanf("%d",&t);
    while( t-- ){
        int ll,v,l,r;
        scanf("%d %d %d %d",&ll,&v,&l,&r);
        printf("%d\n",ll/v-r/v+(l-1)/v);
    }
    return 0;
}
