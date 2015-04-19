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
        
        int result[m+n];
        int A_start,count,i,j;
        
		A_start=0;
		count=0;
		i=0;  //B
		j=0;  //A
		while(i<n)  //B
        {
        	if(j<m)
        	{
        		if(B[i]>A[j])
        		{
        			
					if(j==m-1)  //The last element of A which is still smaller than B[i].A has not put in the result array
        			{
						while(A_start<=j)
        				{
							result[count]=A[A_start];
							count++;
							A_start++;
        				}
        			}	
					j++;
        		}
	        	else if(B[i]<=A[j])
	        	{
					if(A_start!=j)
	        		{
	        			for(int k=A_start;k<j;k++)  //Copy the element which is smaller than B[i] to result array
						{
							result[count]=A[k];
							count++;
						}	
						result[count]=B[i];  //Copy B[i] to result array.
						count++;
							
						A_start=j;
	        		}
	        		else  //The next B[i] is still smaller than A[j]. Copy B[i] to result array directly.
	        		{
	        			result[count]=B[i];  //Copy B[i] to result array.
						count++;
	        		}
					
					i++; //B move to next	
	        	}	
        	}
        	else  //A has finished scanning. Copy the rest of element in B to result array.
        	{
        		result[count]=B[i];  //Copy B[i] to result array.
				cout<<"i"<<i<<"B[i]"<<B[i]<<"count"<<count<<endl;
				count++;
				i++;
				
        	}
			
        	
        }
        while(j<m)  //A hasn't finish
        {
        	result[count]=A[j];
			count++;
			j++;
        }
        cout<<"count"<<count<<endl;
        
        
        //Copy result array to A
        for(int k=0;k<count;k++)
        {
        	A[k]=result[k];
        	cout<<A[k]<<",";
        }
        cout<<endl;
        
    }
};




int main()
{
	Solution solution;
	int input_A[3]={1,2,3};
	int input_B[3]={2,5,6};
	
	solution.merge(input_A,3,input_B,3);
	
	return 0;
}
