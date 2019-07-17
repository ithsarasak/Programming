#include<stdio.h>
#include<vector>
using namespace std;
vector<int> vec[1000];
int check[1000];
int n, sum;
void traverse( int k , int p , int lv )
{
    printf("%d ",k);
    sum += lv;
    for( int i = 0 ; i < vec[k].size() ; i++ ){
        if( vec[k][i] != p ){
            traverse( vec[k][i] , k , lv + 1 );
        }
    }
}
int main()
{
    scanf("%d",&n);

    for( int i = 0 ; i < n - 1 ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        vec[f].push_back( t );
        vec[t].push_back( f );
    }
    traverse( 1 , 0 , 1 );
    printf("\n%d",sum);
    return 0;
}
