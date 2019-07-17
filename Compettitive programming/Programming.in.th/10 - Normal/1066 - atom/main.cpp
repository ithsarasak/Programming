#include<stdio.h>
int atom1[1010], i, j, atoms, maxdif, dif, pos, score;
int main()
{
    scanf("%d",&atoms);
    for( i = 0 ; i < atoms ; i++ ){
        scanf("%d",&atom1[i]);
    }
    while( atoms > 1 ){
        maxdif = 0;
        for( i = 0 ; i < atoms - 1 ; i++ ){
            if( atom1[i] >= atom1[i + 1] ){
                dif = atom1[i] - atom1[i + 1];
            }
            else{
                dif = atom1[i + 1] - atom1[i];
            }
            if( maxdif < dif ){
                pos = i;
                maxdif = dif;
            }
        }
        atom1[pos] = 0;
        atom1[pos + 1] = 0;
        score += maxdif;
        int count = 0;
        for( i = 0 ; i < atoms ; i++ ){
            if( atom1[i] != 0 ){
                atom1[count] = atom1[i];
                count++;
            }
        }
        atoms -= 2;
        //printf("%d ",score);
    }
    printf("%d",score);
    return 0;
}
