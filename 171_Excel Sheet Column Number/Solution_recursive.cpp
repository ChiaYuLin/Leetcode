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


#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Solution {
public:
	int transform(char* s,int size)
	{
		int result;
		char* cutstr=new char[1000];
		char* last=new char[1];
		
		if(size==1)
		{
			result=s[size-1]-'A'+1;
			return result;
		}	
		else
		{
			int i;
			for(i=0;i<size-1;i++)
				cutstr[i]=s[i];
				
			last[0]=s[i];
			
			size--;
				
			return 26*transform(cutstr,size)+(last[0]-'A'+1);
		}	
		
	}
    int titleToNumber(string s) {
    	int count=0;
    	char* input=new char[1000];
    	
    	strcpy(input,s.c_str());

		count=transform(input,s.size());
    	
        
        return count;
    }
};


int main()
{
	Solution solution;
	int count=0;
	
	count=solution.titleToNumber("AAA");
	cout<<count<<endl;
	return 0;
}
