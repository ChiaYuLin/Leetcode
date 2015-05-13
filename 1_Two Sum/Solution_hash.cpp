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
		map<int,vector<int> > nums_index;  //Use vector<int> as value to stored the index of duplicated number
		int targetvalue;
		std::map<int,vector<int> >::iterator it2;
		

		for(int i=0;i<nums.size();i++)  //Put the number as key, index as value into map
		{
			
			it2=nums_index.find(nums[i]);
			if(it2==nums_index.end())
			{
				vector<int> tmp;
				tmp.push_back(i+1);
				nums_index[nums[i]]=tmp;
			}
			else
			{
				vector<int> &tmp=it2->second;
				tmp.push_back(i+1);
			}

		}
			

		//Iterate the map to find the sum.
		for(map<int,vector<int> >::iterator it=nums_index.begin();it!=nums_index.end();it++)  
		{

			targetvalue=target-it->first;
				
			it2=nums_index.find(targetvalue);

				if(it2!=nums_index.end())
				{
					if(it2!=it)
					{
						vector<int> & tmp=it->second;
						vector<int> & tmp2=it2->second;
						if(tmp[0]<tmp2[0])  //index1 should be smaller than index2
						{
							result.push_back(tmp[0]);
							result.push_back(tmp2[0]);
						}
						else
						{
							result.push_back(tmp2[0]);
							result.push_back(tmp[0]);
						}
					}
					else  //The anwer is same value.
					{
						vector<int> & tmp=it->second;
						result.push_back(tmp[0]);
						result.push_back(tmp[1]);
					}
					

					break;

			}	
		}	

		return result;

    }

};

int main()
{
	Solution solution;
	vector<int> input;
	vector<int> result;

	/*
	//Testcase1:
	input.push_back(0);
	input.push_back(4);
	input.push_back(3);
	input.push_back(0);*/

	/*
	//Testcase2:
	int i=0;
	while(i<32046)
	{
		input.push_back(i);
		i+=2;
	}*/

	
	//Testcase3:
	input.push_back(-1);
	input.push_back(-2);
	input.push_back(-3);
	input.push_back(-4);
	input.push_back(-5);
	
	result=solution.twoSum(input,-8);
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}

}