/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

*/

#include<iostream>
#include <cstdlib> 

using namespace std;

/*class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
		while(n>=1)
        {
			n&=(n-1);
            count++;   
        }
        return count;
    }
};*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
		while(n>1)
        {
			int mod=0;
			mod=n%2;
			if(mod==1)
                count++;
			n=n/2;	    
        }
        if(n==1)
        	count++;
        return count;
    }
};

int main()
{
	Solution solution;
	int result=0;
	cout<<"@@@@"<<endl;
	result=solution.hammingWeight(2147483648);
	cout<<"count:"<<result<<endl;
	return 0;
}

