#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<stdlib.h>
struct Box {
     int h, w , l ;
};

     int comp( Box  a , Box b )
     {
          
          return a.l > b.l;

     }
     int max_height( Box arr[]  , int n )
           {
                Box rotate[3*n];
                int i , j; 
                int k = n ;
                int index= 0 ;
                for( i = 0 ;i < n ; i++ )
                {

                    rotate [  index ].h =  arr [ i ].h;

                    rotate [ index ].l = max (  arr [i ].l  , arr[ i ].w ) ;

                    rotate [ index ].w  =  min ( arr [ i ].w , arr [ i ]. l );

                    index ++;

                   rotate [  index ].h =  arr [ i ].w;

                    rotate [ index ].l = max (  arr [i ].l  , arr[ i ].h ) ;

                    rotate [ index ].w  =  min ( arr [ i ].l , arr [ i ]. h );

                    index ++ ;

                    rotate [  index ].h =  arr [ i ] .l ;

                    rotate [ index ]. l = max ( arr [ i ] .h ,  arr [ i ].w ) ;

                    rotate [ index ].w = min ( arr [ i ] .h  , arr [ i ] .w );

                    index ++;

                }

                n = n * 3;
                sort ( rotate , rotate + n , comp);
               int maximum_height_at_point[n];
                for ( i = 0 ;i < n ; i ++ )
                {
                     maximum_height_at_point[i] = rotate[i].h;
                }
                
                for (  i = 1 ; i < n ; i ++ )
                {

                    for ( j =  0 ; j < i ; j ++ )
                    {

                         if ( rotate [ i ].l < rotate [ j ].l and rotate [ i ].w < rotate [ j ].w )
                         {

                              if ( maximum_height_at_point [  i ] < maximum_height_at_point [j ]+ rotate[i].h)
                              maximum_height_at_point [ i ] =  maximum_height_at_point [ j ] + rotate [ i ].h;

                         }


                    }

                }

                int min_val = INT_MIN;
                for ( i = 0 ; i < n ; i++ )
                {
                    if(maximum_height_at_point[i] > min_val )
                    min_val = maximum_height_at_point[i];
                }
                return min_val;
           }

int main(){
     Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<max_height(arr, n );
}