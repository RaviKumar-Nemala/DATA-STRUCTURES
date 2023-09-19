//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Box 
{
     int l , w, h ; 
};

bool comp( Box a , Box b )
{
    
}
// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
          vector<Box >  boxes;

          int i  , j ; 

          for( i  =  0 ; i < n ; i ++ )
          {
               Box  b ;
               b.l = length [ i ] ;
               b.w = width [  i ] ;
               b.h =  height [ i ] ; 
               boxes.push_back ( b ) ;
          }

          vector< Box >all_boxes;

          for( auto it : boxes )
          {
               all_boxes.push_back( it ) ;

               Box b ;
               b.h  = it.l;
               b.l =  max( it.w , it.h);
               b.w = min( it.w , it.h);

               all_boxes .push_back( b ) ;

               Box  b2  ;

               b2.h = it.w;

               b2.l = max( it.l , it.h);

               b2.w = min( it.l , it.h) ;

               all_boxes.push_back( b2);
           }

          sort ( all_boxes.begin() , all_boxes.end() ,  comp) ; 

          n = n * 3 ;
          vector<int > lcs( n ,  0 ) ;

          for( i = 0 ; i < n ; i ++ )
          {
               lcs [ i ] =  all_boxes[ i ].h ;
          }
          int max_val =  INT_MIN;
          for(  i =  1 ; i < n ; i ++)
          {
               for( j = 0 ; j < i ; j  ++ )
               {
                    if( all_boxes [ i ] .l < all_boxes[j].l and all_boxes[i].w < all_boxes [ j ].w )
                    {
                         lcs [ i ] = max( lcs[ i ] ,  lcs [ j ] + all_boxes[i].h);
                         max_val  = max ( max_val ,  lcs [ i ] ) ; 
                    }
               }
          }

          cout << max_val << " "; 

    }
};

//{ Driver Code Starts.

int main() {
	int height[] = {4,1,4,10};
     int width[] = {6,2,5,12};
     int length[] = {7,3,6,32};

     Solution obj ;

     obj.maxHeight( height ,  width ,  length , 4 );
}
	
// } Driver Code Ends