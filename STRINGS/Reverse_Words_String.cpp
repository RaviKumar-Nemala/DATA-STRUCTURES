#include<bits/stdc++.h>
using namespace std;

void reverse( string &str , int start , int end)
{
     while ( start < end )
     {
          swap( str [ start ], str [ end ] );
          start ++;
          end --;
     }
     return;
}

//this aproach works with  the 0( 1 ) aux space
void reverse_words_opt( string str )
{
     //reverse the strings based on the space s
     //after the reverse all strings at a time 
     //EXAMPLE = "geeks for geeks" 
     //step-1 =  "skeeg  rof skeeg";
     //step-2 ="geeks for geeks" //reversing the whole string
     int start =0;
     for( int idx = 0 ; idx < str.length() ; idx ++ ) 
     {
          char curr_char = str [ idx ];

          if( curr_char == ' ')
          {
               reverse( str , start , idx-1); 
               start = idx + 1;
          }

     }
     reverse ( str , start , (str.size () -1 ) );

     reverse ( str , 0 , (str.size () -1));
     
     cout << str << endl;

}




void reverse_words( string str ) 
{
     stack<string> st;
   //  int before_idx = 0 ;
     int space_found = str.find (" ");

     // while( space_found != str.npos)
     // {
     //      string temp =  str.substr ( before_idx ,str.size()-before_idx - space_found);
     //      cout<< before_idx <<" " << space_found <<endl;
     //      cout << temp << endl;
     //      st.push( temp );
     //      before_idx =  space_found + 1 ; 
     //      space_found = str.find(" " , space_found +1 ) ; 
     // }

     // cout << before_idx << endl;


     // st.push ( str.substr( before_idx));
     string temp = "";
     for (int idx = 0; idx < str.size ()  ; idx ++ )
     {
          char curr_char = str [ idx] ; 
          if ( curr_char != ' ')
          {    
               temp  += curr_char ;
          }
          else 
          {
               st.push ( temp );
               temp ="";
          }

     }
     st.push ( temp);
     while( !st.empty() )
     {
          cout << st.top () << endl;
          st.pop();
     }
}


int main()
{
   string str = "hello there ddos";
     // cout << str.substr( 6,11)<<endl;
    reverse_words_opt( str ) ;

     return 0; 

} 