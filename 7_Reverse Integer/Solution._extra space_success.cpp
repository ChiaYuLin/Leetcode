/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>  
using namespace std;


class Solution {
public:
    int reverse(int x)  {
    	bool negative=false;
    	char* num=new char[10000];
    	char* tmp=new char[1];
    	stringstream ss;
		int i,j;

        if(x<0) 
        {
        	negative=true;
        	x=0-x;  //Change to positive
        }	
		
		ss<<x;
        ss>>num;
		ss.clear();
		
        i=0;
        j=strlen(num)-1;

        while(i<j)
        {
			tmp[0]=num[i];
			num[i]=num[j];
			num[j]=tmp[0];
			i++;
			j--;
        }
        
       
        ss<<num;
        ss>>x;
        

		if(x >= std::numeric_limits<int>::max()|| x<= std::numeric_limits<int>::min())
			return 0;
			
			
			
		if(negative)
		{
			x=0-x;
		}
			
		return x;
    
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

