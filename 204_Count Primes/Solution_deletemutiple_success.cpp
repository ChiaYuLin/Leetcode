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
//Mehtod: Delete Mutiple of valid prime

Use a bool array to be the map of every number.
The initial value in the map is true.
If the number can be divided by the number which is smaller than sqrt(n). The corresponding map becomes false.

The way to speed up:
1. The iteration will stop when the divisor is equal or bigger than sqrt(n).
2. We only divide the number by valid prime.
3. We start to trace number from i*i. 
(i*2,i*3,....i*i-1 have already been deleted when mutiple is smaller than i)
For example:
i=5. We start to trace number form 5*5
5*2, 5*3, 5*4 has been deleted when i=2,i=3
*/



class Solution {
public:
    int countPrimes(long int n) {
        bool number[n];
        int result=n;

        if(n>1)
        {
        	if(n==2)
        		return 0;
        	if(n==3)
        		return 1;

        	result-=2;  //prime doen't include 1 and itself
        	for(int i=0;i<n;i++)
	        	number[i]=1;	

	        //From 2 to sqrt(n)
	        //Delete the mutiple of 2,3,.....sqrt(n)
	        for(int i=2;i<sqrt(n);i++)
	        {
	        	if(number[i])  //Delete the number which is the mutiple of valid prime.
	        	{
	        		for(int j=i*i;j<n;j+=i)  //We start to trace number from i*i. j+=i is the mutple of i.
	        		{
	        			if(number[j])
	        			{
	        				number[j]=0;
	        				result--;
	        			}
	        				
	        		}
	        	}
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

	result=solution.countPrimes(499979);

	cout<<"result:"<<result<<endl;
}