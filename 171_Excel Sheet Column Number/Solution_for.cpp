/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) 
	{
		int length=0;
		int last=0;
		int result=0;
		length=s.size();
	
		for(int i=0;i<length;i++)
	    {
	    	last=s.c_str()[i]-'A'+1;
			result=26*result+last;
	    }
	    
	    return result;
			
	}
};

int main()
{
	int count;
	Solution solution;
	count=solution.titleToNumber("AAA");
	cout<<count<<endl;
	return 0;
}
