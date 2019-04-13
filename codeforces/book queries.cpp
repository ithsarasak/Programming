#include<bits/stdc++.h>

using namespace std;
int q, l = 200001, r = 200002;
int pos[200100];
int main()
{
    scanf("%d",&q);
    while( q-- ){
        char ch;
        scanf(" %c",&ch);
        int book;
        if( ch == 'L' ){
            scanf("%d",&book);
            pos[book] = l;
            l--;
        }
        else if( ch == 'R' ){
            scanf("%d",&book);
            pos[book] = r;
            r++;
        }
        else{
            scanf("%d",&book);
            //printf("%d %d %d\n",l,r,pos[book]);
            printf("%d\n",min( pos[book] - l - 1, r - pos[book] - 1 ) );
        }
    }
    return 0;
}
