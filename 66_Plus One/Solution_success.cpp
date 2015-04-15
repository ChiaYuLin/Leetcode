/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        std::vector<int>::iterator it;


		int flag=0;
        int sum=0;
    
		sum=digits.back()+1;
		it=result.begin();
		result.insert(it,sum%10);
		flag=sum/10;
		
		for(int i=digits.size()-2;i>=0;i--)
		{
			sum=digits[i]+flag;
			it=result.begin();
			result.insert(it,sum%10);
			flag=sum/10;
		}     
		
		if(flag)
		{
			it=result.begin();
			result.insert(it,1);
		}   
        
        return result;
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
