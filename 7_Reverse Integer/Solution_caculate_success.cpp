/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
using namespace std;

//If exchange number from the head and end, it will overflow and fail.
class Solution {
public:
    int reverse(int x) {
		long long int reverse=0;
		bool negative=false;
        
		
		if(x >= std::numeric_limits<int>::max()|| x<= std::numeric_limits<int>::min())
			return 0;   
		    
		if(x<0) 
        {
        	negative=true;
        	x=0-x;  //Change to positive
        }	
        
        while(x>0)
        {
        	reverse=reverse*10+x%10;
        	x=x/10;
        	
        	cout<<"reverse:"<<reverse<<endl;
        	cout<<"x:"<<x<<endl;
        }
		if(reverse >= std::numeric_limits<int>::max()|| reverse<= std::numeric_limits<int>::min())  //After change, overflow
		        return 0;
		
		
						
			
		if(negative)
		{
			reverse=0-reverse;
		}
			
		return reverse;

    }
};


int main()
{
	Solution solution;
	int count;
	
	count=solution.reverse(1534236469);
	cout<<count<<endl;
	return 0;
}

