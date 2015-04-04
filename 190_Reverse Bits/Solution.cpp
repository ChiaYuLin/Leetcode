/*

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).

*/


#include<iostream>
#include <cstdlib> 
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		std::vector<uint32_t> binary;
        std::vector<uint32_t>::iterator it;
        uint32_t result=0;
        int size=0;
        
           
		while(n>1)
        {
			it=binary.begin();
			cout<<"n:"<<n<<endl;
			binary.insert(it,n%2);
			n=n/2;	    
        }
        it=binary.begin();
        binary.insert(it,n);
        

        
        for(std::vector<uint32_t>::iterator it=binary.begin();it!=binary.end();it++ )
        {
			cout<<*it;
        }
        cout<<endl;
        
        size=31;
        for(std::vector<uint32_t>::reverse_iterator rit=binary.rbegin();rit!=binary.rend();rit++ )
        {
			result=result+*rit*pow(2,size);
			size--;	
        }
        return result; 
    }
};

int main()
{
	Solution solution;
	int result=0;
	cout<<"@@@@"<<endl;
	result=solution.reverseBits(43261596);
	cout<<"answer:"<<result<<endl;
	return 0;
}

