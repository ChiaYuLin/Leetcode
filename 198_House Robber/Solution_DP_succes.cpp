/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Iterative
class Solution {
public:
    int rob(vector<int> &num) {
    
	    int size=num.size();
	    int odd=0;
	    int even=0;
	    
	    
	    for(int i=0;i<size;i++)
	    {
	    	if(i%2==1)
	    	{
	    		if((odd+num[i])>even)
	    			odd=odd+num[i];
	    		else
	    			odd=even;
	    	}
	    	else
	    	{
	    		if((even+num[i])>odd)
	    			even=even+num[i];
	    		else
	    			even=odd;
	    	}
		}
		
		if(odd>even)
			return odd;
		else
			return even;
	}
};



int main()
{
	vector<int> input;
	Solution solution;
	int result=0;
	

	input.push_back(8);
	input.push_back(9);
	input.push_back(9);
	input.push_back(4);
	input.push_back(10);
	input.push_back(5);
	input.push_back(6);
	input.push_back(9);
	input.push_back(7);
	input.push_back(9);

	
	result=solution.rob(input);
	
	cout<<result<<endl;
	
	return 0;
}
