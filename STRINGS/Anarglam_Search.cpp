#include<bits/stdc++.h>
using namespace std ;

bool are_same( vector<int> f1 , vector <int > f2  )
{
     if ( f1 == f2 )     return true;
     return false; 
}


bool is_present_optimal( string text , string pattern )
{    
     vector < int > text_freq ( 256 ,  0 );

     vector <  int > patt_freq( 256 , 0  );

     int n = text.size () ;

     int m = pattern.size () ;

     int idx = 0 ; 

     for( idx = 0 ; idx < m ; idx ++ )
     {
          text_freq [ text [ idx ] ] ++;
          patt_freq  [ pattern [ idx ]] ++;
     }

     for ( idx = m ;  idx  < n  ; idx ++ )
     {
          if ( are_same( text_freq , patt_freq ) )
          {
               cout << "yes"<< endl;
          }
          //sliding window approach
          text_freq [ text[ idx -m ]] --; //removing the first char ( in the text_fre     )

          text_freq [ text[idx]]++; //adding the current char freq ( againg recheck the condition)
     }

}



bool is_match( string text , string pattern , int start)
{
     vector<int > freq( 256  , 0 ) ;
     int k = 0;  
     for ( int idx  = start ; idx <  ( start +  pattern.size () ) ; idx ++)
     {
          freq[ text[ idx ] ] ++;
          freq [ pattern[k]]--;
          k++;
     } 

     for( auto  it : freq)
     {
          if ( it !=  0) return false;
     }

     return true;
}


//TC =O(n-m)*256 (where 256 IS THE AUX SPACE ARRAY LENGTH )

bool is_present ( string text , string pattern )
{ 

     for( int idx = 0 ; idx <= text.size () - pattern.size () ; idx ++ )
     {
          char curr_char = text[ idx] ;

          if( curr_char == pattern [ 0 ] ) 
          {
               if( is_match( text , pattern , idx )) 
               {
                    cout << idx << endl;
               }
          }
     }


     return true;
}


int main ()
{

string text = "geeksforgeeks";

string str ="frog" ; //since (  forg  in text converted to frog after permutation so print yes)

// is_present( text , str) ; 

is_present_optimal(text , str ) ;


/**
 * text ="geeksforgeeks" ;
 * 
 * str = "fks" //output = no ( since there is contiguous string in text whose permutation is equal to the current string )
 * 
 */

return 0;
}