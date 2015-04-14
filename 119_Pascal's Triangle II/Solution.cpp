/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> triangle(vector<int> input)
	{
		vector<int> result;
		int size=input.size();
		
		
		result.push_back(1);
		size--;  //EX:[1 2 1]  The size is 3 but only sum twice.
		
		for(vector<int>::iterator it=input.begin();it!=input.end();it++)
		{
			if(size==0)
				break;
				
			result.push_back(*it+*(it+1));
			
			size--;
		}
		result.push_back(1);
		
		return result;
	}
	
    vector<int> getRow(int rowIndex) {
    	vector<int>finalresult;
    	
    	int i=-1;
    	
    	if(rowIndex<0) return finalresult;
    	
    	finalresult.push_back(1);
    	rowIndex--;
    	
    	while(i<rowIndex)
    	{
    		finalresult=triangle(finalresult);
    		
			i++;
    	}

        return finalresult;
    }
};


int main()
{
	Solution solution;
	vector<int> result;
	
	result=solution.getRow(0);
	
	cout<<"[";
	for(vector<int>::iterator it=result.begin();it!=result.end();it++)
	{
		cout<<*it<<",";
    }
    cout<<"]"<<endl;
	
	return 0;
}
