#include<bits/stdc++.h>
using namespace std ;

class Solution 
{

public:
     // simply finding the toposort for the given graph
     void dfs ( vector < int >   graph []  , int src ,  string &ans , vector <  bool > &visited  )
     {

          visited [ src ] = true ;
          
          for ( auto it : graph [ src ] ) {
     
               if ( !visited [ it ] )
               {
                    dfs ( graph , it , ans , visited ) ;
               }
          }

          char  ch = src + 'a';

          ans = ch + ans ; // makesure ch + ans not ans+ ch because we are finding the toposort

          return ;

     }


     void solve ( vector < string > words )
     {

          int n = words.size() ;

          vector < int > graph [ n ] ;

          for ( int i = 0 ; i < n-1 ; i ++ )
          {

               string s1 = words [ i ] ;

               string s2 = words [ i + 1 ];


          // a letter mundu vastado compare cheyyadaniki ee loop use avvudi
          // then store those in the graph 
               for ( int j = 0 ; j < min ( s1.length()  , s2.length() ) ; j ++)
               {

                    char s1_letter = s1 [ j ];

                    char s2_letter = s2 [ j ] ;

                    if ( s1_letter != s2_letter ) 
                    {
                         // interger lo ki convert cheyyadaniki
                         
                         // graph [ u ] .push_back ( V ) means ( u  mundu vastadi v kanna);

                         graph[ s1_letter -'a'].push_back ( s2_letter -'a' );
                         
                         break;
                    }
                    else
                    {
                         continue;
                    }

               }

          }

          vector < bool > visited ( n , false ) ;

          string ans = "";

          // we need to find the first k alphabets order 

          int k = 4 ;

          for ( int i = 0 ; i < 4 ; i ++ )
          {

               if( !visited [ i ] ) 
               {
                    dfs (graph , i ,  ans , visited ) ;
               }
          }

          cout <<" ORDER OF THE WORDS = "<< ans << endl;

     }




};




int main () 
{

     vector < string > words =   { "baa","abcd","abca","cab","cad" }  ; 

     // words anevi sorted in alien languae
     //deenelo first k words order find out cheyyali
     // suppose compare ( baa , abcd ) (  indulo baa first vachindi so second word lo "A" kanna mundu first word lo "b" vastadi (  b -> a ) );

     // suppose compare( abcd , abca) ( indulo two words lo a , a , are equal then go to next letter
     // b ,b  are equal same c ,c equal in the two words finnally  ( d ,a ) not equal so ( first word lo d undi kabatti ( d ->  a )  avvuddi)
     
     // like that the order is  ( b -> d -> a -> c ) b first vastadi d second vastadi tarvata a, lasty c 

     Solution obj ;

     obj.solve ( words ) ;
     
     return 0;

}