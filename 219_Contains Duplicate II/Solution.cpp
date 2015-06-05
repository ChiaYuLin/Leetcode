/*
Given an array of integers and an integer k, 
find out whether there there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and j is at most k.

*/


#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)  {
        map<int,int> nummap;
        std::map<int,int>::iterator it;

        for(int i=0;i<nums.size();i++)
        {
        	if(!nummap.empty())
	        {	
	        	it=nummap.find(nums[i]);
	        	if(it==nummap.end())
	        		nummap[nums[i]]=i;
	        	else
	        	{
	        		if(i-it->second <=k)  //The difference between i and j is at most k
	        			return true;
	        		else
	        			nummap[nums[i]]=i;  //Update the newest index in the map
	        	}
	        		
	        }
	        else
	        	nummap[nums[i]]=i;
        }

        return false;
        
    }
};


int main()
{
	Solution solution;
	bool result;
	vector<int> input;

	
	input.push_back(1);
	input.push_back(2);
	input.push_back(1);
	result=solution.containsNearbyDuplicate(input,1);
	cout<<"result:"<<result<<endl;




}