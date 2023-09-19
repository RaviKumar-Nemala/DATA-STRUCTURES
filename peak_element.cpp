#include"tree_config.h"

int findPeakElement(vector<int>& nums) {
        
        
        if ( nums .size() == 1 )
        {
            return  0 ;
        }
        
        else if ( nums.size() ==2 )
        {
            if ( nums [ 0 ] > nums [ 1 ] )
            {
                return 0 ;
            }
            else
                return 1;
        }
        int low =  0;
        
        int high =  nums.size() -1 ;
        
        int n = nums.size() ;
        
        
        int ans = 0 ;
        
        while ( low <= high )
        {
            
            int mid_idx = low + ( high - low )/2;
            
            int mid_val = nums[ mid_idx ];
            // if we are at first position on the array then left 
// side no element .
            // then if the right side element is greater then current element return right_side element idx
          //  other wise return the current_element idx;
            
            if ( mid_idx == 0  )
            {
            
                
                    if ( nums [ mid_idx + 1 ] < mid_val )
                    {
                        ans= mid_idx;
                        break;
                    }
                    else
                    {
                        ans = mid_idx + 1 ;
                        break;
                    }
                
            }
            
 // if we move to the last element
            // check its before element if the before element is greater then last element then return before element index
           // otherwise return the last element index 
            
            else if ( mid_idx == nums.size() -1 )
            {
                if ( mid_val > nums [ mid_idx - 1 ] ) 
                {
                    ans = mid_idx;
                    
                    break;
                    
                }
                else
                {
                    ans = mid_idx - 1 ;
                    break;
                }
            }
            // main case peak element is greater then its //neighbours 
            else if (  mid_val > nums [ mid_idx -1 ] and mid_val > nums [ mid_idx + 1 ] )
            {
               
                 ans = mid_idx;
                    break;
            }    
            // used to moving to the right or left 
            else if (nums [ mid_idx - 1 ] > mid_val )
            {
                high = mid_idx -1;
            }
            else
            {
                low = mid_idx + 1 ;
            }
        }
        
        return ans ;//returns the idx 
        
    }

int main () 
{

// vector< int > arr = { 1 , 4 , 6 , 9 , 4};
vector< int > arr = { 10 , 20 ,30 ,14 } ;

 // A peak element is an element that is strictly greater than its neighbors.
cout <<" peak element = " << arr [ findPeakElement( arr )  ] << endl;

return 0;

}