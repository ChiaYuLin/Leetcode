/*Determine whether an integer is a palindrome. Do this without extra space.*/

#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
    	char* num=new char[10000];
    	stringstream ss;
		int i,j;
    	
        if(x>0) 
        {
        	ss<<x;
        	ss>>num;
		
        	i=0;
        	j=strlen(num)-1;

        	while(i<j)
        	{
				if(num[i]==num[j])
        		{
        		
					i++;
        			j--;
        		}
        		else
        			return false;
        	}
        	return true;
        }
        else
        	return false;
    
    }
};


int main()
{
	Solution solution;
	bool count;
	
	count=solution.isPalindrome(808);
	cout<<count<<endl;
	return 0;
}

