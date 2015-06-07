/*
Given an array of integers, find out whether there are two distinct indices i and j 
in the array such that the difference between nums[i] and nums[j] is at most t 
and the difference between i and j is at most k.

*/


#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>

using namespace std;




class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)  {

        vector<int> result;
		map<int,int> nums_index;
		std::map<int,int>::iterator it;
		

		for(int i=0;i<nums.size();i++)
		{
			if(i>k)
				nums_index.erase(nums[i-k-1]);  //The map size is k+1. When i>k, start to erase the oldest element.

			it=nums_index.lower_bound(nums[i]-t); //The lower_bound will point to the value which is larger or equal to lower_bound but is smallest.

			if(it!=nums_index.end()) 
			{
				if(abs(nums[i]-it->first)<=t)  //check nums[i]+t
					return true;
			}

			nums_index[nums[i]]=i;
		}	


        return false;
        
    }
};


int main()
{
	Solution solution;
	bool result;
	vector<int> input;

	/*
	//Test case1: [0,2147483647], 1, 2147483647
	input.push_back(0);
	input.push_back(2147483647);*/

	/*
	//Test case2: [-1,2147483647], 1, 2147483647
	input.push_back(-1);
	input.push_back(2147483647);*/

	//Test case3:
	input.push_back(1);
	input.push_back(9);
	input.push_back(4);
	input.push_back(7);
	input.push_back(5);
	input.push_back(10);



	result=solution.containsNearbyAlmostDuplicate(input,1,2147483647);
	cout<<"result:"<<result<<endl;



}