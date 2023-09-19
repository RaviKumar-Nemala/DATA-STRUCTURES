#include<bits/stdc++.h>
using namespace std ;

class Solution
{

public:

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set < string > mp ;
        
        for ( auto it :wordList )
        {
            mp.insert ( it ) ;
        }
        
        if ( mp.find( endWord ) == mp.end () ) 
        {
            return 0 ;
        }
        
        
        queue < string > q ;
        
        q.push ( beginWord );
        
        int len = 0;
        
        while ( !q.empty() )
        {
            
            // incrementing the length when we pick new word from the queue
            len ++;
            
            int n =  q.size() ;
            
         
            
            for ( int i = 0 ; i <  n ; i ++ )
            {
                
                 string s  = q.front();
            
                q.pop();
                
                for ( int j = 0  ; j < s.length() ; j ++)
                {
                    
                    char temp  = s [ j ];// oka letter ni change chesina tarvata next time aa malli next iteration lo original string unna same letter kavali so munde store chesukovali

                    // it is used to change the one letter in the string 
                    //oka letter change chesina tarvata vachina result anedi ichina word list lo undo ledo chudali
                    //okavela unte danni queue lo ki push chesukovali
                    for ( char ch = 'a' ; ch <= 'z' ; ch ++)
                    {
                        
                        s [ j ] =  ch;
                        // letter change chesina tarvata letter anedi end word ki equal ithe then legth return cheyyali
                        if ( s == endWord )
                                return len + 1;
                        // letter change chesina tarvata vachina string mp lo leka pote continue cheyyali
                        if ( mp.find ( s ) == mp.end() )
                            continue;
                        else
                        {
                            // string anedi already given word list lo unte then oka valid answer dorinkinattu dani queue lo ki push chesukovali
                            
                            q.push ( s ) ;
                            
                            mp.erase( s ) ;
                        }
                        
                    }
                    // suppose s ="abc" // inner loop lo 'a' ni change chesina tarvatha next iteration
                    // lo 'b' ni change chestamu appudu before 'a' anedi kavali anduke temp lo letter ni store chesukoni 
                    //anni combinations try chesina tarvtha malli danni original position lo pettali
                    
                    s [ j ] = temp ;
                    
                    
                }
                    
                
            }
            
                
        }
        
        
        return 0;
        
    }
    





};

int main () 
{
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.

Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.

sk == endWord

Given two words, 
beginWord and endWord, and a dictionary wordList, 
return the number of words in the shortest transformation sequence from beginWord to endWord, 
or 0 if no such sequence exists.


Input: beginWord = "hit", endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.


*/



}