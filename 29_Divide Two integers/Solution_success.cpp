#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;
/*
Two cases will overflow:
1.divisor = 0;
2.dividend = INT_MIN and divisor = -1 (because abs(INT_MIN) = abs(INT_MAX) + 1).

We use shift divisor to replace divide.
For example: (22,3)
If 22 > 3<<1(6), we shift left 3 first.
If 22 > 6<<1(12), we shift left 6.
22 < 12<<1(24). So we record the times of shift and calcute the remaining.
To this step, 22=3*4+10.
We shift twice. Therefore result=4 (2^2). 
We use the same method to calcute the remaining.
If 10 > 3<<1(6), we shift left 3 first.
10 < 6<<1(12). So we record the times of shift and calcute the remaining.
To this step, 22=3*4+3*2+4.
We shift once. Therefore result=4+2 (2^1).
We use the same method to calcute the remaining.
4 > 3  but 4 < 3<<1(6). Thus, result=4+2+1.

*/




class Solution {
public:
    int divide(int dividend, int divisor)  {
    	int result=0;
        int count=0;
    	bool flag=false;
        long long int dvd=0;
        long long int dvs=0;
        long long int tmp_dvs=0;


        if(dividend==INT_MIN && divisor == -1 || divisor==0 )
            return INT_MAX;
        else
        {
            
            if(dividend > INT_MIN && divisor==INT_MIN)    //The value of dividend is smaller than divisor
                return 0;
            else if(dividend == INT_MIN && divisor==INT_MIN)
                return 1;
            else
            {
                dvd=labs(dividend);  //This is the long int version of abs.
                dvs=labs(divisor);
            }
            

            if(dividend>=0 && divisor<0 || dividend<=0 && divisor>0)  //If dividend and divisor have different sign.
                flag=true;
            


            while(dvd>=dvs)
            {
                count=1; 
                tmp_dvs=dvs;
                while(dvd > tmp_dvs<<1)
                {
                    count=count<<1;
                    tmp_dvs=tmp_dvs<<1;
                    
                }
                dvd=dvd-tmp_dvs;   //To see whether remaining is larger than dvs
                result=result+count;

            }
            

            if(flag)
                result=0-result;
            return result;
        }
    }
};

int main()
{
	Solution solution;
	int result=0;
	//result=solution.divide(15,3);
    //result=solution.divide(-1010369383, -2147483648);  //Judge maximum
    //result=solution.divide(1, -1);  //Judge different sign 
    result=solution.divide(2147483647,1);
    //result=solution.divide(-2147483648, -2147483648);
    //result=solution.divide(2147483647, -2147483648);

	cout<<"result:"<<result<<endl;
}