#include<bits/stdc++.h>
using namespace std; 

class student 
{
     public:

     string student_name ;
     int roll;
     student( string student_name , int roll)
     {
          this -> student_name = student_name; 
          this ->roll = roll;
     }
};

struct comp
{
     bool operator()( student  s1 ,student s2 )
     {
          return s1.roll > s2.roll;
     }
};

void display (vector< student > stu_list)
{
     for( auto it : stu_list)
     {
          cout<< it.roll <<"  "<< it.student_name<< endl; 
     }
     return;
}


void display_min_heap ( priority_queue<student  , vector< student > , comp > min_heap)
{
     while ( ! min_heap.empty())
     {
          cout<< min_heap.top ( ).roll<<" " << min_heap.top().student_name << " " <<endl; 
          min_heap.pop ( ) ;
     }    
}


bool my_comp( student s1 , student s2)
{return s1.roll < s2.roll;}

int main()
{


     student s1("ravi" ,  8 );

     student  s2("kumar" ,  5);

     student s3 ( "ddos" ,  1 ) ;

     student my_arr[3] = { s1 , s2 , s3};

     vector<student > stu_list(my_arr , my_arr+3);

     //places the values in the assending order 
     sort( stu_list.begin() , stu_list.end() , my_comp);


     //using the min_heap for the custom classes ( need to pass the sturct or class which contains the operator method as the 3rdparam)
     priority_queue< student ,  vector< student> ,comp> min_heap (  my_arr , my_arr +3 ) ;

     display_min_heap( min_heap);
 
     return 0;
}