#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
		int xtmp,xtmp2,xtmp3;
		int length=0;
    	int i=0;
		int j=0;
		int v1,v2;
        if(x>0) 
        {
        	xtmp=x;
			while(xtmp>0)
			{
				i++;
				xtmp/=10;
			}
			
			i--;
			j=1;
			xtmp2=x;
			xtmp3=x;
			while(i>=j)
			{
			
				v1=xtmp2/pow(10,i);
				xtmp2=xtmp2-v1*pow(10,i);
				v2=xtmp3%10;
				xtmp3/=10;

				if(v1==v2)
				{
					i--;
					j++;
				}
				else
					return false;
			}	
			return true;
    	}
    	else if(x==0)
    		return true;
    	else  //x<0
    		return false;
    }
};


int main()
{
	Solution solution;
	bool count;
	
	count=solution.isPalindrome(10);
	cout<<count<<endl;
	return 0;
}

