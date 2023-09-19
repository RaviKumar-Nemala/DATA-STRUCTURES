#include"tree_config.h"
//REFERENCE = https://youtu.be/Mo6OOe9KZM0

node * insert  ( node * root , int key , node *&succ  )
{

     if ( !root )
          {
               return new node( key );
          }
     
     int current_node = root -> val ;

     if (  current_node < key )
     {

          root ->right = insert ( root -> right , key , succ );

     }

     if ( current_node > key )
     {
          succ = root ;

          root ->left = insert  ( root -> left , key , succ) ;

     }

     return root ;

}


void print_val ( vector< int > arr )
{
     for( auto it : arr )
     {
          cout << it << "  " ;
     }cout << endl;
}

void solve ( vector < int > arr   , int n )
{

     node* succecor  = nullptr ;

     node *root = nullptr ;


     cout <<"BEFORE THE REPLACEMENT "<< endl;

     print_val ( arr ) ;
     




     for ( int  idx = n -1 ;  idx >= 0 ; idx -- )
     {

          int element =  arr [ idx ] ;

          root = insert( root , element , succecor ) ;

          if ( succecor )
          {
               arr [ idx ] = succecor -> val;
          }
          else{
               arr [ idx ] = -1 ;
          }

     }

        cout <<"AFTER THE REPLACEMENT  :"<< endl;

        print_val (  arr ) ;


}


int main ( void )
{



     vector < int > arr = { 4 , 8 , 10 , 12,14, 20,22};

     solve (arr ,  7 );



}