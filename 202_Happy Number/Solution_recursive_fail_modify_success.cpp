/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 8^2
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>



class Solution {
public:
    bool isHappy(int n) {
        vector<int> digit;
        int rest;
        int newvalue;
        bool result;


        if(n<10)
        {
        	if(n==1 || n==7)
        	   return true;
        	else
        	   return false;
        }
        else
        {
        	rest=n;
        	newvalue=0;

        	while(rest>0)
        	{
        		digit.insert(digit.begin(),rest%10);

        		rest=rest/10;
        	}

        	for(int i=0;i<digit.size();i++)
        		newvalue+=(int)pow(digit[i],2);


        	result=isHappy(newvalue);

            //To check the return value of the recursive function. To return the value. 
            if(result)
                return true;
            else 
                return false;
        	
        }
        
    }

};

int main()
{
	Solution solution;
	bool result=false;

	result=solution.isHappy(19);

	cout<<"result:"<<result<<endl;

	return 0;
}