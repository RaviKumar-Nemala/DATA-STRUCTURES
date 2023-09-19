#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define rows 3
#define colms 3


class Solution{
     private : 
          int kadeans(int *temp , int *start , int *end ,  int n )
          {
               int sum=0, i ,j ;
               int main_sum=INT_MIN;
               int local_start = 0;
               for( i =0 ; i < n ;i++)
               {
                    sum += temp[i];
                    if(sum < 0)
                    {
                     local_start = i+1;
                     sum =0;    
                    }
                    else if(sum > main_sum)
                    {
                         *start = local_start;
                          *end  =  i;
                          main_sum =  sum;
                    }
               }
               return main_sum;
          }
     public :
      int max_sum_rectangle( int arr[][colms] )
      {
          int left,right ,  top , bottom;
          int temp[rows];
          int i,j,sum;
          int start ,end;
          int max_sum= INT_MIN;
          int topleft,topright , topupper , topbottom;
          for (left=0;left<colms; left++)
          {
               memset(temp, 0 ,sizeof(temp));
               for(right = left; right < colms ;right++)
               {
                    
                    for(i = 0 ; i <rows ;i++)
                    {
                         temp[i] = temp[i] + arr[i][right];
                    }
                    sum = kadeans(temp ,&start , &end , rows);
                    if(sum > max_sum)
                    {
                         max_sum=sum;
                         topleft=left;
                         topright=right;
                         topbottom=end;
                         topupper=start;
                    }
               }
          }
          cout << max_sum<<endl;
          cout<<"top left : "<<topleft<<"\n top right : "<<topright<<"\n top bottom : "<<topbottom<<"\n top uppter : "<<topupper;
           return max_sum;
      }
};


int main(){
  int arr[rows][colms] =  { {1,2,-1} , {-8,-3,4},
                       {3 , 8 , 10 } } ;   
                       
                  //  { {1, 2, -1, -4 , -20} , {-8 , -3 , 4 ,2 ,1 } , {3 , 8 ,10 , 1 ,3 } , {-4 , -1 , 1 ,7 , -6  }};
                       
                       Solution obj;
     int max_sum=obj.max_sum_rectangle(arr);
     cout<<"\n printing  the max sum in the main method : "<<max_sum<<endl;

}