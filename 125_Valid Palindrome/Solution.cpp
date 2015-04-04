/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i,j;
        bool result=0;
        char* sentence=new char[1000000];
        
        strcpy(sentence,s.c_str());

        for (char *iter = sentence; *iter != '\0'; ++iter)
		{
		    *iter = std::tolower(*iter);
		    cout<<*iter<<endl;
		}
      	
      	
		i=0;
		j=s.size()-1;
		while(i<=j)
	    {
	    	if(isalnum(sentence[i]))
	    	{
	    		if(isalnum(sentence[j]))
	    		{
	    			if(sentence[i]!=sentence[j])
	    				return result;
	    			else
	    			{
	    				i++;
	    				j--;
	    			}
	    		}
	    		else
	    			j--;
	    	}
	    	else
	    		i++;
	    }
	    result=1;
	    
	    return result;
    }
};

int main()
{
	Solution solution;
	bool count;
	
	count=solution.isPalindrome("1a2");
	cout<<count<<endl;
	return 0;
}
