/*
Given a roman numeral, convert it to an integer.

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
    int romanToInt(string s) {
    	int result=0;

    	for(int i=0;i<s.length();i++)
    	{
    		if(s[i]=='M')
    			result+=1000;
    		else if(s[i]=='D')
				result+=500;
			else if(s[i]=='C')
			{
				++i;
				if(s[i]=='D')  //CD
					result+=400;
				else if(s[i]=='M')  //CM
					result+=900; 	
				else
				{
					result+=100;
					i--;
				}	
			}
			else if(s[i]=='L')	
				result+=50;
			else if(s[i]=='X')	
			{
				++i;
				if(s[i]=='L')  //XL
					result+=40;
				else if(s[i]=='C')  //XC
					result+=90;
				else
				{
					result+=10;
					i--;
				}
					
			}
			else if(s[i]=='V')
				result+=5;
			else if(s[i]=='I')
			{
				++i;
				if(s[i]=='V')  //IV
					result+=4;
				else if(s[i]=='X')  //IX
					result+=9;
				else
				{
					result+=1;
					i--;
				}
					
			}
    	}
        
        return result;
    }
};


int main()
{
	Solution solution;
	int result;

	result=solution.romanToInt("MCMIV");
	cout<<"result:"<<result<<endl;

}