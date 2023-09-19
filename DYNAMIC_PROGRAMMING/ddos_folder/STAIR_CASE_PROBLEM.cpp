#include<bits/stdc++.h>
using namespace std;

class Solution{
     public :

      int util_no_of_ways_to_reach_stair( int n  )
      {
           if(n==0 || n==1)
           return n;
           return (util_no_of_ways_to_reach_stair(n-1 ) + util_no_of_ways_to_reach_stair(n-2));
      }

      int no_of_ways_to_reach_stair(int n)
      {
           return util_no_of_ways_to_reach_stair(n+1);
      }
      
};
int main(){
     int n =4; 
     Solution obj;
     cout << obj.no_of_ways_to_reach_stair(n);
}
/*Method 1: The first method uses the technique of recursion to solve this problem.
Approach: We can easily find the recursive nature in the above problem. The person can reach nth stair from either (n-1)th stair or from (n-2)th stair. Hence, for each stair n, we try to find out the number of ways to reach n-1th stair and n-2th stair and add them to give the answer for the nth stair. Therefore the expression for such an approach comes out to be : 

ways(n) = ways(n-1) + ways(n-2)
The above expression is actually the expression for Fibonacci numbers, but there is one thing to notice, the value of ways(n) is equal to fibonacci(n+1). 

ways(1) = fib(2) = 1
ways(2) = fib(3) = 2
ways(3) = fib(4) = 3
For a better understanding, let’s refer to the recursion tree below -: 

Input: N = 4

                  fib(5)
           '3'  /        \   '2'
               /          \
           fib(4)         fib(3)
     '2'  /      \ '1'   /      \  
         /        \     /        \ 
     fib(3)     fib(2)fib(2)      fib(1) 
     /    \ '1' /   \ '0'
'1' /   '1'\   /     \ 
   /        \ fib(1) fib(0) 
fib(2)     fib(1)
*/