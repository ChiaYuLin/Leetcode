/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


//Cannnot check "([])"
class Solution {
public:
    bool isValid(string s) {
		
		vector<int> flag1;  //flag for "()"
		vector<int> flag2;  //flag for "[]"
		vector<int> flag3;  //flag for "{}"
		int length=s.size();
		int location;
		
		if(length%2==0)
		{
			for(int i=0;i<length;i++)
			{
				if(s[i]=='(')
					flag1.push_back(i);
				else if(s[i]==')')
				{
					if(flag1.size()!=0)
					{
						location=flag1.back();
					
						if((i-location)%2==0) //There is incomplete parenthesis in the middle
							return false;
						else
							flag1.pop_back();  //Delete the last element
					}
					else  //directly ")"
						return false;
					
				}
				else if(s[i]=='[')
					flag2.push_back(i);
				else if(s[i]==']')
				{
					if(flag2.size()!=0)
					{
						location=flag2.back();
					
						if((i-location)%2==0) //There is incomplete parenthesis in the middle
							return false;
						else
							flag2.pop_back();  //Delete the last element
					}
					else  //directly "]"
						return false;
					
				}
				else if(s[i]=='{')
					flag3.push_back(i);
				else if(s[i]=='}')
				{
					if(flag3.size()!=0)  
					{
						location=flag3.back();
					
						if((i-location)%2==0) //There is incomplete parenthesis in the middle
							return false;
						else
							flag3.pop_back();  //Delete the last element
					}
					else	 //directly "}"
						return false;
					
				}	
			}
			
			if(flag1.size()==0 && flag2.size()==0 && flag3.size()==0)
				return true;
			else
				return false;
		}
		else
			return false;  ////odd length is not pair
    }
};



int main()
{
	Solution solution;
	bool result;
	
	//result=solution.isValid("(");  //Expected false
	//result=solution.isValid("([)]");  //Expected false
	//result=solution.isValid("([])");  //Expected true
	//result=solution.isValid("()[]{}");  //Expected true
	//result=solution.isValid("[{()}]");  //Expected true
	//result=solution.isValid("[({(())}[()])]");  //Expected true
	result=solution.isValid("(}(({(}()(({)](({[");  //Expected false
	
	cout<<"result:"<<result<<endl;
	return 0;
}
