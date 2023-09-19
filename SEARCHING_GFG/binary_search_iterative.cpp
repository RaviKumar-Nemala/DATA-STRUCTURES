#include<bits/stdc++.h>
using namespace std;

struct node
{
     int data ;
     node*left ;
     node*right;
     node ( int data )
     {
          this -> data =data;
          this ->left = nullptr;
          this->right = nullptr;
     }

};

node* add_node ( node *root , int data )
{
          if ( root == nullptr)
               return new node( data);
          if ( data > root -> data )
          {
               root->right = add_node( root -> right , data);
          }     
          else if ( data <= root->data)
          {
               root->left = add_node( root ->left , data);
          }
          return root;
}

void inorder ( node *root)
{
     if ( root== nullptr)
          return;
     inorder ( root ->left);
     cout << root ->data<<" " ;
     inorder ( root -> right );
}

bool search( int  *arr , int target , int low ,int high )
{

     if ( low > high)
          return false;  
     
     int mid_idx = ( low +  high )/2;

     int mid_val = arr[  mid_idx ] ;

     if ( mid_val == target)  return true;

     if ( target < mid_val)
     {
          if ( search( arr , target ,  low , mid_idx -1 ))  
               return true;
     }
     else 
     {
          if(search ( arr , target ,mid_idx +1 , high))
               return true;
     }
     
     return false ;


}


bool search_iterative (int *arr, int target ,int low ,int high )
{

     while ( low <= high)
     {    
          int mid_idx = ( low + high )/2;

          int mid_val = arr [ mid_idx];

          if ( target == mid_val )
          {
               return true;
          }
          else if ( target > mid_val)
          {
               low = mid_idx +1 ;
          }
          else 
          {
               high = mid_idx -1;
          }

     }

     return false ;
}

int main () 
{

     int arr[] = { 1 ,2 ,3 , 8 , 9 ,10 };

     
     if ( search(arr ,  8 , 0 , 6-1) )
     {
          cout <<"ELEEMENT  IS FOUND ";
     }
     else 
     {
          cout <<"ELEMENT IS NOT FOUND ";
     }
     return 0;
}


