#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int info;
    node * left ;
    node * right ;
};
 node * tree = NULL ;
 node * insert ( node * node , int info ) ;
 void preorder ( node * tree ) ;
 void inorder ( node * tree ) ;
 void postorder ( node * tree ) ;

int main ( )
 {
    int choice , info ;
    while ( 1 )
    {
        cout<<"\n1. Insert Node"<<endl;
        cout<<"2. Preorder traversal"<<endl;
        cout<<"3. Inorder Traversal"<<endl;
        cout<<"4. Postorder Traversal"<<endl;
        cout<<"5. Exit\n"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        cout<<"\n";
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the number : ";
                cin>>info;
                tree=insert(tree,info);
                break;
            }
            case 2:
            {
                preorder ( tree ) ; break;
            }
            case 3:
            {
                inorder( tree ) ; break ;
            }
            case 4:
            {
                postorder ( tree ) ; break ;
            }
            case 5:
            {
                exit (0);
                break;
            }

        }
    }
 }
 node * insert ( node * newnode , int info )
 {
    if ( newnode == NULL )
    {
        node * temp = new node ;
        temp -> info = info ;
        temp -> left = NULL ; temp -> right = NULL ;
        newnode = temp ;
    }
    else if ( newnode -> info > info)
    {
        newnode -> left = insert ( newnode -> left , info ) ;
    }
    else
    {
        newnode -> right =insert ( newnode -> right , info ) ;
    }
    return newnode ;
 }

void preorder ( node * tree )
{
    if ( tree != NULL )
    {
        cout<<tree->info<<"\t";
        preorder( tree-> left ) ;
        preorder( tree-> right ) ;
    }
 }
 void inorder(node* tree)
  {
    if( tree != NULL )
    {
        inorder( tree -> left ) ;
        cout<< tree ->info<<"\t";
        inorder( tree -> right ) ;
    }
}
 void postorder( node * tree )
{
    if ( tree != NULL )
    {
        postorder( tree-> left );
        postorder( tree ->right );
        cout<< tree -> info <<"\t";
    }
 }
