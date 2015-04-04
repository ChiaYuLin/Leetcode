/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
    	
    	std::map<int,int> countmap;
    	int result=0;
    	int size=0;

    	size=floor(num.size()/2);


    	for(std::vector<int>::iterator it=num.begin();it!=num.end();it++)
    	{
    		if(countmap.find(*it)!=countmap.end())
    		{
    			std::map<int,int>::iterator itformap;
    			itformap=countmap.find(*it);
    			int & count=itformap->second;
    			
    			count++;
    			
    			if(count > size)
    			    return *it;
    		}
    		else
    		{
    			int count=1;
    			countmap[*it]=1;
    			
    			if(count > size)
    			    return *it;
    		}
    	}


    }
};


int main()
{
	Solution solution;
	int result=0;
	vector<int> input;

		input.push_back(1);
		
	result=solution.majorityElement(input);
	cout<<result<<endl;
	return 0;
}
