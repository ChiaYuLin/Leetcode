/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	int sum;
    	string result;
    	int i,j,flag;
    	
    	
    	flag=0;
    	i=a.length()-1;
    	j=b.length()-1;
    	while(i>=0 && j>=0)
    	{
			sum=(a[i]-'0')+(b[j]-'0')+flag;
			result=char(sum%2+'0')+result;
			flag=sum/2;
    		
			i--;
			j--;		

    			
    	}

        
    	if(i>-1)
		{
			while(i>=0)
    		{
				if(flag)  //flag==1
	    		{
	    			sum=a[i]-'0'+flag;
	    			result=char(sum%2+'0')+result;
	    			flag=sum/2;
	    		}	
	    		else
	    			result=a[i]+result;
	    		
	    		i--;
    		}
		}	
    		
    	
    	
    	
    	if(j>-1)
    	{
    		while(j>=0)
    		{
    			if(flag)  //flag==1
    			{
	    			sum=b[j]-'0'+flag;
	    			result=char(sum%2+'0')+result;
	    			flag=sum/2;
    			}	
    			else
    				result=b[j]+result;	

    			j--;
    		}
    	}
    	
    	if(flag)  //flag==1
			result=char(1+'0')+result;
			
			
    	return result;
    }
};


int main()
{
	Solution solution;
	string s;

	s=solution.addBinary("11","1");
	cout<<"result:"<<s<<endl;
	
	return 0;
}
