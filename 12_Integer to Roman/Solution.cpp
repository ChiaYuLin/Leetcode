/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

/** Roman numerals rule (Refernce: http://en.wikipedia.org/wiki/Roman_numerals)
 *
 * Symbol  Value
 * I   1
 * V   5
 * X   10
 * L   50
 * C   100
 * D   500
 * M   1,000
 *
 * the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX) respectively
 * X can be placed before L and C to make 40 (XL) and 90 (XC) respectively
 * C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern
 * An example using the above rules would be 1904: this is composed of
 * 1 (one thousand), 9 (nine hundreds), 0 (zero tens), and 4 (four units).
 * To write the Roman numeral, each of the non-zero digits should be treated separately.
 * Thus 1,000 = M, 900 = CM, and 4 = IV. Therefore, 1904 is MCMIV.
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        int count=0;
        int rest=0;

        while(num>0)
        {
        	if(num>=1000)
	        {
	        	if(num==1000)
	        	{
	        		result.append("M");
	        		break;
	        	}	
	        	else
	        	{
	        		count=num/1000;
		        	num=num-count*1000;

		        	for(int i=0;i<count;i++)
		        		result.append("M");
	        	}
	        	
	        }
	        else if(num>=100)
	        {
	        	if(num==500)
	        	{
	        		result.append("D");
	        		break;
	        	}
	        	else if(num==100)
	        	{
	        		result.append("C");
	        		break;
	        	}
	        	else
	        	{
	        		count=num/100;
		        	num=num-count*100;

		        	if(count==9)
		        		result.append("CM");
		        	else if(count==4)
		        		result.append("CD");
		        	else
		        	{
		        		rest=count%5;
		        		count=count/5;

		        		if(count!=0)  //>5
		        			result.append("D");

		        		for(int i=0;i<rest;i++)
		        			result.append("C");
		        	}
	        	}
	        	
	        }
	        else if(num>=10)
	        {
	        	if(num==50)
	        	{
	        		result.append("L");
	        		break;
	        	}
	        	else if(num==10)
	        	{
	        		result.append("X");
	        		break;
	        	}
	        	else
	        	{
	        		count=num/10;
		        	num=num-count*10;

		        	if(count==9)
		        		result.append("XC");
		        	else if(count==4)
		        		result.append("XL");
		        	else
		        	{
		        		rest=count%5;
		        		count=count/5;

		        		if(count!=0)  //>5
		        			result.append("L");

		        		for(int i=0;i<rest;i++)
		        			result.append("X");
		        	}
	        	}
	        	
	        }
	        else if(num>=1)
	        {
	        	if(num==5)
	        	{
	        		result.append("V");
	        		break;
	        	}
	        	else if(num==1)
	        	{
	        		result.append("I");
	        		break;
	        	}
	        	else
	        	{
	        		count=num;
		        	num=0;

		        	if(count==9)
		        		result.append("IX");
		        	else if(count==4)
		        		result.append("IV");
		        	else
		        	{
		        		rest=count%5;
		        		count=count/5;

		        		if(count!=0)  //>5
		        			result.append("V");

		        		for(int i=0;i<rest;i++)
		        			result.append("I");
		        	}
	        	}

	        
	        }
        }


        return result;
       

    }
};


int main()
{
	Solution solution;
	string result;

	result=solution.intToRoman(10);

	cout<<"result:"<<result<<endl;


}
