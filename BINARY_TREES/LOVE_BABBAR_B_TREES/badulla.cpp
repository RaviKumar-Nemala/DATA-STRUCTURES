#include<bits/stdc++.h>
using namespace std;


vector< int >   merge ( vector < int > in1 ,  int n1 , int n2 , vector < int > in2  )
{

  vector <int> res  ;

  int idx_1 = 0 ;
  
  int idx_2 = 0 ;

  while ( idx_1 < n1  and idx_2 <  n2  )
  {

      if ( in1 [  idx_1 ]  <  in2 [ idx_2 ] )
      {

          res.push_back ( in1[idx_1]);
          idx_1 ++;
      }

      else{

          res.push_back ( in2 [ idx_2 ]);

          idx_2 ++;

      }

  }

  while ( idx_1 < n1 )
  {

    res.push_back ( in1 [ idx_1 ] );

    idx_1 ++;
  
  }
  while ( idx_2 < n2 )
  {
    res.push_back ( in2 [ idx_2 ]);
    idx_2 ++;
  }


return  res ;

}


int main  () 
{


  vector < int  > in1 = { 3 ,2 ,5,  1 } ;

  vector  < int > in2 = { 3 ,5 ,8 ,7  };

  sort ( in1.begin() , in1.end() );
  
  sort ( in2.begin () , in2.end() ) ;

  vector < int > ans = merge(in1 , 4,4,in2 );
  
  for ( const auto it: ans )
  {
    cout << it <<"   " ; 
  }



  return 0 ;


  

}