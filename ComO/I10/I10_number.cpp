#include<bits/stdc++.h>

using namespace std;

int en;
int mi = 1e9;
int va[15], num;
int p[110], s;
int main()
{
    scanf("%d",&en);
    for( int i = 1 ; i <= 9 ; i++ ){
        scanf("%d",&va[i]);
        if( mi >= va[i] ){
            mi = va[i];
            num = i;
        }
    }
    while( en - mi >= 0 ){
        //printf("%d %d\n",num,en);
        p[s] = num;
        s++;
        en -= mi;
    }
    for( int i = 0 ; i < s ; i++ ){
        if( en <= 0 )break;
        for( int j = 9 ; j >= 1 ; j-- ){
            if( va[j] - va[p[i]] <= en && va[j] - va[p[i]] >= 0 && j > p[i] ){
                en -= ( va[j] - va[p[i]] );
                p[i] = j;
                break;
            }
        }
    }
    for( int i = 0 ; i < s ; i++ ){
        printf("%d",p[i]);
    }
    return 0;
}

