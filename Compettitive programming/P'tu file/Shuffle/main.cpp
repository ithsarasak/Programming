#include<stdio.h>
#include<vector>

using namespace std;

vector<int> vec;

int n, op, i, j;
int main()
{
    scanf("%d",&n);
    scanf("%d",&op);
    for( i = 1 ; i <= n ; i++ ){
        vec.push_back( i );
    }
    for( i = 0 ; i < op ; i++ ){
        //printf("%d\n",i);
        int go, to;
        scanf("%d %d",&go,&to);
        for( j = go - 1 ; j < to ; j++ ){
            vec.push_back( vec[j] );
        }
        if( go == to ){
            vec.erase( vec.begin() + ( go - 1 ) );
        }
        else{
            vec.erase( vec.begin() + ( go - 1 ) , vec.begin() + to );
        }
        /*for( int k = 0 ; k < n ; k++ ){
            printf("%d ",vec[k]);
        }
        printf("\n");*/
    }
    for( i = 0 ; i < n ; i++ ){
        printf("%d\n",vec[i]);
    }
    return 0;
}
