#include<bits/stdc++.h>

using namespace std;

int data[10000], fi;
int main()
{
    scanf("%d",&fi);
    for( int i = 0 ; i < 1000 ; i++ ){
        data[i] = rand() % 1000;
    }
    sort( data , data + 1000 );
    /*for( int i = 0 ; i < 1000 ; i++ ){
        printf("%d ",data[i]);
    }*/
    int l = 0, r = 999;
    while( l <= r ){
        //printf("%d %d %d %d\n",l,data[l],r,data[r]);
        int m = ( l + r )/ 2;
        if( fi <= data[m] ){
            r = m - 1;
        }
        else if( fi > data[m] ){
            l = m + 1;
        }
    }

    if( data[l] == fi ){
        printf("Found at position : %d",l);
    }
    else{
        printf("Not found");
    }
    return 0;
}
