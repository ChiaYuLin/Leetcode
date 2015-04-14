/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class Solution {
public:
	string transform(string input)
	{
		string finalresult;
		int i,count;
		
		i=0;
		count=1;
		while(i<input.length())
		{
			if(input[i]==input[i+1]) 
			{
				count++;
				i++;	
			}
			else
			{

				finalresult.push_back(count+'0');  //counter   +'0' change to char
				finalresult.push_back(input[i]);  //digit
				i++;
				count=1;
			}
		}
		
		return finalresult;
	}
    string countAndSay(int n) {
		
		int callnum=0;
		string result="";
        
        if(n<=0)
			return "";
			
		result="1";
		n--;
		
		while(callnum<n)
		{
			result=transform(result);
			callnum++;		
		}
		
		return result;
    }
};


int main()
{
	Solution solution;
	string result;
	result=solution.countAndSay(5);
	cout<<"result:"<<result<<endl;
	
	return 0;
}


