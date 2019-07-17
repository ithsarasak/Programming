#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *right;
    struct node *left;
    int height;
};
struct node *root = NULL;
int c, key, s;
int height( struct node *N )
{
    if( N == NULL ){
        return 0;
    }
    else{
        return N -> height;
    }
}
int checkbalance( struct node *N )
{
    if( N == NULL ){
        return 0;
    }
    else{
        return height( N -> left ) - height( N -> right );
    }
}
struct node *leftrotation( struct node *x )
{
    struct node *y = x -> right;
    struct node *T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    x -> height = max( height( x -> left ), height( x -> right ) ) + 1;
    y -> height = max( height( y -> left ), height( y -> right ) ) + 1;

    return y;
}
struct node *rightrotation( struct node *x )
{
    struct node *y = x -> left;
    struct node *T2 = y -> right;

    y -> right = x;
    x -> left = T2;

    x -> height = max( height( x -> left ), height( x -> right ) ) + 1;
    y -> height = max( height( y -> left ), height( y -> right ) ) + 1;

    return y;
}
struct node* minvalue( struct node *T )
{
    struct node *current = T;
    while( current -> left != NULL ){
        current = current -> left;
    }
    return current;
}
struct node* newnode( int key )
{
    struct node* build = ( struct node * )malloc( sizeof( struct node ) );
    build -> data   = key;
    build -> left   = NULL;
    build -> right  = NULL;
    build -> height = 1;
    return build ;
}
struct node* add( struct node *N , int key )
{
    if( N == NULL ){
        return newnode( key );
    }
    if( key < N -> data ){
        N -> left = add( N -> left , key );
    }
    else if( key > N -> data ){
        N -> right = add( N -> right , key );
    }
    N -> height = 1 + max( height( N -> left ) , height( N -> right ) );
    int balance = checkbalance( N );

    if( balance > 1 && key < N -> left -> data ){
        return rightrotation( N );
    }
    else if( balance < -1 && key > N -> right -> data ){
        return leftrotation( N );
    }
    else if( balance > 1 && key > N -> left -> data ){
        N -> left = leftrotation( N -> left );
        return rightrotation( N );
    }
    else if( balance < -1 && key < N -> right -> data ){
        N -> right = rightrotation( N -> right );
        return leftrotation( N );
    }
    return N;
}
int searchn( struct node *N , int key )
{
    if( N == NULL ){
        return 0;
    }
    else{
        if( N -> data == key ){
            return 1;
        }
        else if( key < N -> data ){
            searchn( N -> left , key );
        }
        else{
            searchn( N -> right , key );
        }
    }
}
int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&key);
        root = add( root , key );
    }
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d",&key);
        if( searchn( root , key ) ){
            printf("y\n");
        }
        else{
            printf("n\n");
        }
    }
    return 0;
}
