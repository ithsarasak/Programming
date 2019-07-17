#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int i,j;
    int column,row;

    cin >> row;
    cin >> column;

    int mat1[row][column],mat2[row][column];

    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cin >> mat1[i][j];
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cin >> mat2[i][j];
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d ",mat1[i][j]+mat2[i][j]);
        }
        cout << endl;
    }
}
