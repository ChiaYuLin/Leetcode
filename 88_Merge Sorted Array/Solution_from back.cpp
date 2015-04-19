#include <iostream>
#include <cstdlib>

/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional 
elements from B. The number of elements initialized in A and B are m and n respectively.

*/

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
      
		int mtmp=m;
		int ntmp=n;   
	 
		//method1:From back. Do not need extra space to store merged array.
		//If A[0]<B[0], A[0] will not moved.
		//If A[0]>B[0], A[0] will be located in the right place. m==0 will be postive to put the rest element of B
    	while(n>0) A[m+n-1] = (m==0||B[n-1] > A[m-1]) ? B[--n] : A[--m];
        
		/*
		//method2:From back. 
		int i=m-1, j=n-1, k=m+n-1;
	    while (i>-1 && j>-1) {
	    	A[k--]= (A[i]>B[j]) ? A[i--] : B[j--];
	    }
	    while (j>-1)         A[k--]=B[j--];	
	    */
    
    		
		for(int k=0;k<mtmp+ntmp;k++)
        {
        	cout<<A[k]<<",";
        }
        cout<<endl;
    }
};



int main()
{
	Solution solution;
	int input_A[3]={1,4,6};
	int input_B[3]={2,2,3};
	
	solution.merge(input_A,3,input_B,3);
	
	return 0;
}
