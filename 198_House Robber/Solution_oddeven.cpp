#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
  		int vectorcount=0;
  		int oddmoney=0;
  		int evenmoney=0;
  		
			for(vector<int>::iterator it=num.begin();it!=num.end();it++)
			{
				vectorcount++;
				if((vectorcount%2)==1)  //odd
					oddmoney=oddmoney+*it;
				else
					evenmoney=evenmoney+*it;
					
				cout<<"oddmoney"<<oddmoney<<endl;
			cout<<"evenmoney"<<oddmoney<<endl;
			}
			
				
		if(oddmoney>evenmoney)
			return oddmoney;
		else
			return evenmoney;
    }
};

int main()
{
	vector<int> input;
	Solution solution;
	int result=0;
	
	input.push_back(6);
	input.push_back(3);
	input.push_back(10);
	input.push_back(8);
	input.push_back(2);
	input.push_back(10);
	input.push_back(3);
	input.push_back(5);
	input.push_back(10);
	input.push_back(5);
	input.push_back(3);
	result=solution.rob(input);
	
	cout<<result<<endl;
	
	return 0;
}
