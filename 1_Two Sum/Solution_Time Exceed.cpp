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
#include <set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int i,j;
		int sum;

		i=0;
		while(i<nums.size())
		{
			j=i+1;
			sum=target-nums[i];
			while(j<nums.size())
			{
				if(nums[j]==sum)
				{
					result.push_back(i+1);
					result.push_back(j+1);
					break;
				}
				j++;
			}

			if(!result.empty())
				break;

			i++;
		}

		return result;

    }
};

int main()
{
	Solution solution;
	vector<int> input;
	vector<int> result;

	input.push_back(2);
	input.push_back(7);
	input.push_back(11);
	input.push_back(15);


	result=solution.twoSum(input,26);
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}

}