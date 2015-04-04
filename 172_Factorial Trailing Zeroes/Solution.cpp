/*
Given an integer n, return the number of trailing zeroes in n!.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        
        while(n>0)
        {
        	n/=5;
			count=count+n;
        }
		
        
        return count;
    }
};

int main()
{
	Solution solution;
	int result=0;
	result=solution.trailingZeroes(30);
	cout<<result<<endl;
	
	return 0;
}
