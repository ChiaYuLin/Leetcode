/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

*/


#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numset;

        for(int i=0;i<nums.size();i++)
        {
        	if(!numset.empty())
	        {
	        	
	        	if(numset.find(nums[i])==numset.end())
	        		numset.insert(nums[i]);
	        	else
	        		return true;
	        }
	        else
	        	numset.insert(nums[i]);
        }

        return false;
        
    }
};


int main()
{
	Solution solution;
	bool result;
	vector<int> input;

	for(int i=0;i<10;i++)
		input.push_back(i);
	

	result=solution.containsDuplicate(input);
	cout<<"result:"<<result<<endl;




}