#include<bits/stdc++.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
    int height;
};
struct node *root = NULL;
int c, key, s;
int maxs( int a , int b )
{
    return ( a > b ) ? a : b;
}
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

    x -> height = maxs( height( x -> left ), height( x -> right ) ) + 1;
    y -> height = maxs( height( y -> left ), height( y -> right ) ) + 1;

    return y;
}
struct node *rightrotation( struct node *x )
{
    struct node *y = x -> left;
    struct node *T2 = y -> right;

    y -> right = x;
    x -> left = T2;

    x -> height = maxs( height( x -> left ), height( x -> right ) ) + 1;
    y -> height = maxs( height( y -> left ), height( y -> right ) ) + 1;

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
    else{
        printf("Node cant be equal\n");
        return N;
    }
    N -> height = 1 + maxs( height( N -> left ) , height( N -> right ) );
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
struct node* del( struct node *N , int key )
{
    if( key < N -> data ){
        N -> left = del( N -> left , key );
    }
    else if( key > N -> data ){
        N -> right = del( N -> right , key );
    }
    else{
        if( ( N -> left == NULL ) || ( N -> right == NULL ) ){
            struct node *temp = N -> left ? N -> left : N -> right ;
            if( temp == NULL ){
                temp = N;
                N = NULL;
            }
            else{
                *N = *temp;
            }
            free( temp );
        }
        else{
            struct node *temp = minvalue( N -> right );
            N -> data = temp -> data;
            N -> right = del( N -> right , temp -> data );
        }
    }
    if( N == NULL ){
        return N;
    }
    N -> height = 1 + maxs( height( N -> left ) , height( N -> right ) );
    int balance = checkbalance( N );

    if( balance > 1 && checkbalance( N -> left ) >= 0 ){
        return rightrotation( N );
    }
    else if( balance < -1 && checkbalance( N -> right ) <= 0 ){
        return leftrotation( N );
    }
    else if( balance > 1 && checkbalance( N -> left ) < 0 ){
        N -> left = leftrotation( N -> left );
        return rightrotation( N );
    }
    else if( balance < -1 && checkbalance( N -> right ) > 0 ){
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
int minss( struct node *N )
{
    if( N -> left != NULL ){
        minss( N -> left );
    }
    return N -> data;
}
int maxss( struct node *N )
{
    if( N -> right != NULL ){
        minss( N -> right );
    }
    return N -> data;
}
int main()
{
    while( 1 ){
        printf("1.Add 2.Delete 3.Search 4.Travel 5.Min max\nElse to Exit\n");
        scanf("%d",&c);
        if( c == 1 ){
            printf("Enter data : ");
            scanf("%d",&key);
            root = add( root , key );
        }
        else if( c == 2 ){
            if( root == NULL ){
                printf("Tree is now empty :( \n");
            }
            else{
                printf("Enter data to delete : ");
                scanf("%d",&key);
                root = del( root , key );
            }
        }
        else if( c == 3 ){
            printf("Search : ");
            scanf("%d",&key);
            if( searchn( root , key ) ){
                printf("Data Found!\n");
            }
            else{
                printf("Data not found;-;\n");
            }
        }
        else if( c == 4 ){
            int t;
            printf("Choose a way to travel\n1.Preorder 2.Inorder 3.Postorder\n");
            scanf("%d",&t);
            printf("height : %d\n",root -> height);
            if( t == 1 ){
                preorder( root );
                printf("\n");
            }
            else if( t == 2 ){
                inorder( root );
                printf("\n");
            }
            else if( t == 3 ){
                postorder( root );
                printf("\n");
            }
            else{
                printf("Wrong choice\n");
            }
        }
        else if( c == 5 ){
            printf("Min : %d\n",minss( root ));
            printf("Max : %d\n",maxss( root ));
        }
        else{
            break;
        }
    }
    return 0;
}
