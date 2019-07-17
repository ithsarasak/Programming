#include<bits/stdc++.h>

using namespace std;
struct mat{
    int r, c;
}ma[20];
int n, path[20][20];
int mul( int l, int r )
{
    if( l == r ) return 0;
    int mi = INT_MAX;
    for( int i = l ; i < r ; i++ ){
        int te = (ma[l].r*ma[i].c*ma[r].c)+mul(l,i)+mul(i+1,r);
        if( mi > te ){
            mi = te;
            path[l][r] = i;
        }
    }
    return mi;
}
void print( int l, int r )
{
    if( l == r ){
        printf("A%d",l+1);
        return ;
    }
    printf("(");
    print(l,path[l][r]);
    printf(" x ");
    print(path[l][r] + 1,r );
    printf(")");
    return ;
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&ma[i].r,&ma[i].c);
    }
    printf("%d\n",mul(0,n-1));
    print(0,n-1);
    return 0;
}
