#include<bits/stdc++.h>

using namespace std;
int en, z;
int mi = 1e9;
int va[15], num;
int p[1001000], s, s2;
int main()
{
    scanf("%d",&en);
    for( int i = 0 ; i <= 9 ; i++ ){
        scanf("%d",&va[i]);
        if( i == 0 )z = va[i];
        else if( mi >= va[i] ){
            mi = va[i];
            num = i;
        }
    }
    if( en < mi ){
        printf("-1");
        return 0;
    }
    p[0] = num;
    s++;
    en -= mi;
    if( mi > z ){
        mi = z;
        num = 0;
    }
    while( en - mi >= 0 ){
        //printf("%d %d\n",num,en);
        p[s] = num;
        s++;
        en -= mi;
    }
    //printf("%d",s);
    /*for( int i = 0 ; i < s ; i++ ){
        printf("%d",p[i]);
    }*/
    for( int i = 0 ; i < s ; i++ ){
        //printf("%d\n",en);
        if( en <= 0 )break;
        if( i == 0 ){
            for( int j = 9 ; j >= 1 ; j-- ){
                if( va[j] - va[p[i]] <= en && va[j] - va[p[i]] >= 0 && j != p[i] ){
                    en -= ( va[j] - va[p[i]] );
                    p[i] = j;
                    break;
                }
            }
        }
        else{
            for( int j = 9 ; j >= 0 ; j-- ){
                if( va[j] - va[p[i]] <= en && va[j] - va[p[i]] >= 0 && j != p[i] ){
                    en -= ( va[j] - va[p[i]] );
                    p[i] = j;
                    break;
                }
            }
        }
    }
    for( int i = 0 ; i < s ; i++ ){
        printf("%d",p[i]);
    }
    return 0;
}
