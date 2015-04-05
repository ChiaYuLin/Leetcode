/*Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    int atoi(string str) {
    	int length,j,i;
		long long int result=0;
		int flagcount=0;
		int start=0;
		int flag=-1;
		bool notcomplete=false;	
		length=str.size();

		cout<<"length:"<<length<<endl;
		
		
		if(length!=0)
		{
			j=0;
			i=length-1;	
			while(isspace(str[j])) //Delete space
			{
				j++;
				i--;
			}
			if(str[j]=='-')
			{
				flag=0;
				j++;
				i--;
			}
			else if(str[j]=='+')
			{
				flag=1;
				j++;
				i--;
			}	
			
		
			start=j;		
			for(;i>=0;i--)
			{
	
				cout<<"str.c_str()[j]:"<<str[j]<<endl;
				cout<<"flag:"<<flag<<endl;
				cout<<"j"<<j<<"  start"<<start<<"  i:"<<i<<endl;
				if (isdigit(str[j]))
					result=result+(str[j]-48)*pow(10,i);	
				else if((str[j]=='-') || (str[j]=='+')) 
				{
					if(j==start)
					{
						if(flag>=0)
							return 0;
						
					}
				
				}
				else
				{
					if(result!=0)
					{
						notcomplete=true;
						break;
					}   
					else
						return 0;
				}
				
				/*if(result >= std::numeric_limits<int>::max() || result<= std::numeric_limits<int>::min())
				{
					
					if(flag==0)
						result=0-result;
					if(result >= std::numeric_limits<int>::max())
						return std::numeric_limits<int>::max();	
					else if(result<= std::numeric_limits<int>::min())
						return std::numeric_limits<int>::min(); 
					else
						return result;
				}*/
				cout<<"result:"<<result<<endl;
								
				j++;
			}
			
	
			if(notcomplete)
				result=result/pow(10,length-j);
			if(flag==0)
				result=0-result;

			if(result >= std::numeric_limits<int>::max())
			{
				if(flag==0) //overflow and change to positive
					return std::numeric_limits<int>::min(); 
				else
					return std::numeric_limits<int>::max();   
			}
			else if(result<= std::numeric_limits<int>::min())
			{
				if(flag==1 || flag==-1) //overflow and change to negative
					return std::numeric_limits<int>::max();   
				else
					return std::numeric_limits<int>::min(); 
			}
				
			return result;   
		}
		else
			return 0;
		     
    }
};


int main()
{
	Solution solution;
	int result=0;
	
	//result=solution.atoi("   +-2");   //Expected:0
	//result=solution.atoi("   - 321");         //Expected:0
	//result=solution.atoi("++1");         //Expected:0
	//result=solution.atoi("");         //Expected:0
    
    //Not digit
	//result=solution.atoi("   -1123u3761867");   //Expected:-1123
    //result=solution.atoi("   -0012a42");   //Expected:-12
    //result=solution.atoi("    +004500");   //Expected:4500
    
    //Overflow
    //result=solution.atoi("-2147483648");         //Expected:-2147483648
	//result=solution.atoi("-2147483647");         //Expected:-2147483647
	//result=solution.atoi("2147483648");         //Expected:2147483647
	result=solution.atoi("9223372036854775809");   //Expected:2147483647
	    
	cout<<"result"<<result<<endl;
}
