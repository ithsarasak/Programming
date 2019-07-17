#include<bits/stdc++.h>
int num, i = 1;
char line[100];
int main()
{
    FILE *fp;
    fp = fopen("userdb.txt","r");
    while( fgets( line , 100, fp ) != NULL ){
        printf("Customer %d : %s",i,line);
        i++;
    }
    fclose( fp );
    return 0;
}
