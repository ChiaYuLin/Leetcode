/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Only change the digit value when there is carry
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		int flag=1;
        int sum=0;
    

		
		for(int i=digits.size()-1;i>=0 && flag;i--)   //At first, flag=1. for is positive
		{
			sum=digits[i]+flag;
			digits[i]=sum%10;   //Change the digit value directly
			flag=sum/10;
		}     
		
		if(flag)
			digits.insert(digits.begin(),1);
		  
        
        return digits;
    }
};



int main()
{
	Solution solution;
	vector<int> input;
	vector<int> result;
	
	input.push_back(9);
	input.push_back(9);
	input.push_back(9);
	input.push_back(9);
	input.push_back(9);
	
	result=solution.plusOne(input);
	
	for(std::vector<int>::iterator it=result.begin();it!=result.end();it++)
	{
		cout<<*it<<",";
	}
	cout<<endl;
	
	return 0;
	
}
