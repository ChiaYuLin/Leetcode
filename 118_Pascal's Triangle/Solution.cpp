/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
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
	
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > finalresult;
    	vector<int>backresult;
    	int i=0;
    	
    	if(numRows<=0) return finalresult;
    	
    	backresult.push_back(1);
    	finalresult.push_back(backresult);
    	numRows--;
    	
    	while(i<numRows)
    	{
    		backresult=triangle(backresult);
    		finalresult.push_back(backresult);
			i++;
    	}
        
        return finalresult;
    }
};


int main()
{
	Solution solution;
	vector<vector<int> > result;
	
	result=solution.generate(5);
	
	for(vector<vector<int> >::iterator it=result.begin();it!=result.end();it++)
	{
		cout<<"[";
		for(vector<int>::iterator it2=it->begin();it2!=it->end();it2++)
		{
			cout<<*it2<<",";
		}
		cout<<"]"<<endl;
	}
	return 0;
}
