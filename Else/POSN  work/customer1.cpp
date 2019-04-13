#include<bits/stdc++.h>
int num, i, age;
char name[1000], surname[1000], tel[15];
int main()
{
    FILE *fp;
    fp = fopen("userdb.txt","w");
    scanf("%d",&num);
    for( i = 0 ; i < num ; i++ ){
        scanf("%s",name);
        scanf("%s",surname);
        scanf("%d",&age);
        scanf("%s",tel);
        fprintf( fp ,"%s,%s,%d,%s\n",name,surname,age,tel);
    }
    printf("Customers' data is saved to userdb.txt");
    fclose( fp );
    return 0;
}
