/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/



#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n)
	{

		int last=0;
		int count=-1;
	    char* str=new char[1000];
		string result;
		
		while(n>0)
		{
		    count++;
			last=n%26;
			n=n/26;
			
			if(last!=0)
				str[count]=last-1+65;
			else
			{
				str[count]=26-1+65;
				n--;
			}
				
			
		}
        
        for(int i=count;i>=0;i--)
        {
        	result.push_back(str[i]);
        }	
	    
	    return result;
			
	}
};

int main()
{
	string ss;
	Solution solution;
	ss=solution.convertToTitle(53);
	cout<<ss<<endl;
	return 0;
}
