/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2


*/


#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		map<int,int> nums_index;
		int targetvalue;
		std::map<int,int>::iterator it;
		
		//We can find the targetvalue and input the vector into map at the same time.
		//Find the target value first. If we can not find the targer, we put the current number into map.
		for(int i=0;i<nums.size();i++)
		{

			targetvalue=target-nums[i];
				
			it=nums_index.find(targetvalue);

			if(it!=nums_index.end())
			{

				result.push_back(it->second);  //The index of target value is smaller than the current value.
				result.push_back(i+1);

				break;
			}

			nums_index[nums[i]]=i+1;
		}	

		return result;

    }

};

int main()
{
	Solution solution;
	vector<int> input;
	vector<int> result;

	
	//Testcase1:
	input.push_back(0);
	input.push_back(4);
	input.push_back(3);
	input.push_back(0);

	/*
	//Testcase2:
	int i=0;
	while(i<32046)
	{
		input.push_back(i);
		i+=2;
	}*/

	
	//Testcase3:
	/*input.push_back(-1);
	input.push_back(-2);
	input.push_back(-3);
	input.push_back(-4);
	input.push_back(-5);*/
	
	result=solution.twoSum(input,0);
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}

}