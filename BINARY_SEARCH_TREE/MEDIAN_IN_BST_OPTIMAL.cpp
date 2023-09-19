#include<bits/stdc++.h>
using namespace std;


struct node 
{

     int val ; 

     node * left ;
     
     node * right ;

     node ( int val )
     {
          this -> val = val ;
          
          this -> left = nullptr ;

          this ->right = nullptr ;

     }

};

int no_of_nodes  = 0 ;



int tree_size (  node * root )
{

     if ( root == nullptr )
     return  0 ;

     no_of_nodes = tree_size ( root-> left ) + tree_size ( root -> right ) +  1 ;

     return no_of_nodes  ;

}



//if the size of the sequence if even we can have 2 mid values 

// first mid_val will be pointed by the prev and second mid_val will be pointed by the current

//if the sequence is odd then curr pointer point to the correspoinding  node 

void inorder( node * root  ,
 int &count  , 
 const int  k , 
 bool &flag , 
node* &prev   ,
node *  &curr)


{

     if ( !root )
          return ;

     inorder ( root -> left , count, k , flag , prev ,curr );

     if( prev == nullptr )
     {
          prev = root ;

          count ++ ;

     }
     //for finding the second mid_val if the sequence is even 
     if ( count == k )
     {
          curr =  root ;

          count ++;
          
          flag = false ;

     }
     
     if ( flag == true )
     {
          prev = root ;
          
          count ++;
          cout << prev -> val << "  " ;
     }

     inorder ( root -> right  , count , k ,  flag , prev, curr ) ;

     return ;

}

float  find_avg ( node * root )
{

     int temp = tree_size ( root ) ;


     const int mid_idx =  ( ::no_of_nodes/ 2 ) + 1 ; // if size of the sequence in even if can have two mid values ;

     cout<< "MID_IDX " << mid_idx<< endl;
     int count = 0 ;


     bool flag = true ;

     node * prev=  nullptr ;

     node * curr = nullptr ;

     inorder (  root ,count ,  mid_idx , flag , prev  , curr );

     float avg = 0.0 ;

     cout << "NO OF THE NODES  " << ::no_of_nodes << endl;

     if ( no_of_nodes %2 == 0 )
     {
          cout <<"two nodes " << endl;
          avg  =  float ( (prev-> val + curr->val ) / 2.0 ) ;

     }
     else
     {
          //if the sequence is odd we can have only one midval which will be pointed by the prev pointer

          avg = curr-> val;    

     }

     return avg ;

}




int main ( )
{

     node * root = new node ( 20 ) ;

     root -> left = new node(  8 ) ;

     root -> right = new node ( 22 ) ;

     root -> left -> left = new node ( 4) ;

     root -> left -> right = new node  (12 ) ;

     root -> left -> right ->left = new  node ( 10);

     root -> left -> right -> right  = new  node ( 14) ;




     cout << find_avg ( root ) << endl;


}


