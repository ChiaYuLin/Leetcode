/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

*/

#include <iostream>
#include <cstdlib>

using namespace std;


class Solution {
public:
    void rotate(int nums[], int n, int k) {

    	int tmp[k];
       
	    if(k!=0 && k!=n)
		{	
			if(k>n)
        	{
        		k=k%n;
        	}
			for(int i=0;i<k;i++)
				tmp[i]=nums[n-k+i];
        	
			
			for(int j=n-k-1;j>=0;j--)
				nums[j+k]=nums[j];
			

			for(int i=0;i<k;i++)
				nums[i]=tmp[i];
    	}
			
        
        
        for(int i=0;i<n;i++)
            cout<<nums[i];
        cout<<endl;
        return;
    }
};

class Solution {
public:
    void rotate(int nums[], int n, int k) {
    	if(k!=0 && k!=n)
		{	
			if(k>n)
        	{
        		k=k%n;
        	}
        	for(int i=0;i<k;i++)  //Hom many times to rotate
        	{
        		int lastelement=0;
				lastelement=nums[n-1];
			
				for(int j=n-1;j>0;j--)  //rotate
					nums[j]=nums[j-1];
			
			
				nums[0]=lastelement;
        	}

        }
        
        for(int i=0;i<n;i++)
            	cout<<nums[i];
        	cout<<endl;
        return;
    }
}


int main()
{
	Solution solution;
	int nums[6];
	
	for(int i=0;i<6;i++)
	    nums[i]=i+1;
	solution.rotate(nums,6,11);
	
	return 0;
}
