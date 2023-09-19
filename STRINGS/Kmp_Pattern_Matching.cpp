#include<bits/stdc++.h>
using namespace std ;
vector < int >  handle ( string str )
{    
     int idx = 1 ;

     int len =  0;
     
     int n = str.size();

     vector< int > lps ( n , 0 ) ; 

     lps [ 0 ] = 0 ;
     
     while( idx < n ) 
     {
          if ( str [ len ] == str [ idx ])
          {
               len++;
               lps [ idx ] = len;
               idx ++;
          }
          else 
          {
               if ( len == 0 )
               {
                    lps [ idx ] = 0 ;
                    idx ++;
               }
               else 
               {
                    len = lps[ len - 1 ] ; //if the chars are not matched then go back try to match the before chars until length reaches to the zero
               }
          }
     }

     return lps;

}

void print_val (vector<int > temp )
{
     for ( auto it : temp)
     {
          cout << it << endl;
     }
}

//TIME COMPLEXITY = O(2N)where is is the length of the text
//
void kmp_pattern_matching ( string str , string pattern  )
{
     int idx = 0 ;
     int n = str.size();
     int j = 0 ;
     vector < int > lps = handle ( pattern ) ;//returns the lps( longest common proper prefix and normal suffix length for every element )
     
     while ( idx < n )
     {
          if ( str [ idx ] == pattern[ j ])
          {
               idx ++; 
               j ++ ;
          }    
          else if ( j >= pattern.size () ) 
          {
               cout <<  ( idx - j) << " " ;//gives the first idx where the matching of the pattern begins 
               j =  lps [ j -1];  //pattern shifted based on the lps value inorder to match the input againg
          }
          else 
          {
               if ( j ==0 ) //executes even one char in the pattern is not matched with the main string 
               {
                    idx ++;
               }
               //if the some chars are matched and remaining chars are not matched
               else
               {
                    j = lps [ j -1 ]; // lps [ j -1 ] returns lps value of the last matched char now we start comapring remaing char from that value
               }
          }

     }
          

     //DRY RUN
     /**
      *        a   b  a   b   c   a  b  a  b   ( text)
      *           
      *        a   b   a  b   d(patterns)
      * 
      *   // since first last char is not matched we need to move our pattern 
      *                       i
      *       a   b   a   b   c  a   b  a   b 
      *               a   b   a  b   d(pattern ignore first 2 because those are common)
      *                       j
      *
      * //lps value specifies how many idxs j value moves to match the next character
      */ 


}



int main ()
{
     string str = "ababcababaad";
     string pattern ="ababa";

     kmp_pattern_matching( str , pattern) ;

     return 0;
}