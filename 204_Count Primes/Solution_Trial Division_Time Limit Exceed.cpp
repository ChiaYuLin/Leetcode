/*
Count the number of prime numbers less than a non-negative number, n

Reference:
https://primes.utm.edu/howmany.html
http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

/*
Method: Delete the number which is divisible by the valid prime. (Trail Devision)
Put the number into vector.
The valid prime in the vector as divisor.
Trace the remaining number in the vector.
If the remaining number is divisible by the valid prime, delete it from vector.


Since we divide every remaining number during each valid prime iteration, the time will exceed.


*/


class Solution {
public:
    int countPrimes(long int n) {
        vector<long int> number;
        long int current=0;  //current is the postion pointer of valid prime in vecotor
        int result=0;

        if(n>1)
        {
        	for(int i=2;i<n;i++)
	        {
	        	if(i%2!=0)
	        		number.push_back(i);
	        }
	        	
	        result++;   //Add prime=2;


	        if(!number.empty())
	        {
	        	while(number[current]<sqrt(n))   //number[current] is the valid prime
		        {
		        	for(int i=current+1;i<number.size();i++) //Start tracing the number which is the next of number[current]
		        	{
		        		if(number[i]%number[current]==0)   //If the number can be divible by valid prime, delete it from vector
		        			number.erase(number.begin()+i);
		        	}
		        	current++;
		        }

		        result+=number.size();  //The number of prime which is smaller than n is the size of vector
	        }
	       

	        return result;
        }
        else
        	return 0;
        
    }
};


int main()
{
	Solution solution;
	int result;

	result=solution.countPrimes(2);

	cout<<"result:"<<result<<endl;
}