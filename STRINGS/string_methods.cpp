#include<bits/stdc++.h>
using  namespace std ;




int main ()
{         
     string str = "hello world";

     //ASSIGN METHOD
     //USED TO ASSIGN THE VALUE OF ONE STRING TO THE ANOTHER STRING

     string str2 ;
     
     str2.assign(str);

     cout << str2 << endl;

     str2.assign(str ,7 , 2) ;//second param is the start pos of the str and the third param is the length of chars that we want to assign
     //if we only specifies the two params we got the exception
     cout << str2 << endl;




     //INSERT METHOD 
     //used to insert the strings at the specified indexes
     str = "HELL AND HEAVEN";
     str2 = "";

     // str2.insert(0 ,  str);
     // cout << str2 << endl;

     // str2.insert( 4 , str) ; 

     //inserts first two chars of the str to the str2 at the start 
     str2.insert(0 , str ,  0 , 2); 
     //first param  is the starting index of the to be inserted
     //second parame is the string that we taking the reference
     // third params is the pos of the substring in the str
     // last param is the len of substr that we want to insert 

     //inserts 3 dots at the end of the string
     str2.insert( str2.size() , 3  , '.');
     //first param is the index where we want to insert
     //second param is the len of string that we want to insert
     //third parame is the char that we want to insert     
     cout << str2<< endl;



     //ERASE METHOD
     str  = "HELL AND HEAVEN";
     

     // str.erase(0 ,  2) ;
     //start from 0th index removes first 2 characters


     // str.erase(str.begin()); //removes the first character

     // str.erase ( str.begin() , str.end() );//removes the chars  from start to end

     str.erase (str.begin()+3);//removes the 4th char

     cout << str << endl;



     //REPLACE METHOD
 
     str2 ="HELL AND HEAVEN";
     str = "REPLACE";

     
     // str2.replace(0 , str.size (),str );
     //first param is the start index
     //second param is the length of the string
     //third param is the string that we want to replace


     // str ="ttx";

     // str2.replace ( 0 , 6 , str ) ; //our string size is 3 but we specified str len as the 6 in this case it simply ignores remainign 3 chars

     cout << str2 << endl;
     
     str2.replace( str2.begin()+1 , str2.begin()+4 ,  "hell");

     cout << str2 << endl ;

     //SWAPPING STRINGS 
     str ="HELL";
     str2 ="HEAVEN";

     str.swap(str2);

     cout << str <<  " " << str2 << endl;



     //FIND METHOD USED TO CHECK IF THE STRING PRESENT OR NOT
     //returns the index of the matched string or the string::npos if the specified string is not found

     str = "hell";
     str2 = "heaven";

     int idx = str.find("ll");
     cout << idx << endl;
     char ch = 'l';
     idx = str.find (ch);//works for the characters too

     cout << idx << endl; 

     if ( str.find("ddos") == str.npos)
     {
          cout <<"SPECIFIED STRING NOT FOUND"<< endl;
     }

     //find the pos of the char after this position
     int first_pos = idx ;

     idx = str.find ( ch, first_pos + 1 );

     cout << idx << endl;


     //rfind is used to find out the last occurance of the string

     idx = str.rfind('l');

     cout << idx << endl;

     //substr method

     str ="hell and heaven";

     cout<< str.substr( 0 , 3 )<< endl;

     return 0; 


}