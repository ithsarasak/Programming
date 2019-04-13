#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *right;
    struct node *left;
};
struct node *root = NULL;
int c, key, s;
struct node* newnode( int key )
{
    struct node* build = ( struct node * )malloc( sizeof( struct node ) );
    build -> data   = key;
    build -> left   = NULL;
    build -> right  = NULL;
    return build ;
}
struct node* add( struct node *N , int key )
{
    if( N == NULL ){
        printf("*\n");
        return newnode( key );
    }
    if( key < N -> data ){
        printf("L");
        N -> left = add( N -> left , key );
    }
    else if( key > N -> data ){
        printf("R");
        N -> right = add( N -> right , key );
    }
    return N;
}
int main()
{
    int n;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&key);
        root = add( root , key );
    }
    return 0;
}

