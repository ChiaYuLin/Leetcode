/*
ABCDE
FGHIJ
.....

If input "CHGLM", output rr*d*l*d*r
The tracing of char is continous.

r:right  l:left
d:down   u:up


*/


#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	string Trace(vector<char>& chars){
		std::string result="";
		char current=chars[0];
		int last_row=0;
		int last_column=0;
		int row=0;
		int column=0;
		int diff;
		
		for(int i=0;i<chars.size();i++)
		{
			if(chars[i]-current==0)
			{
				result.append("*");
			    last_row=abs(chars[i]-'A')/5;;
				last_column=abs(chars[i]-'A')%5;
			}	
			else
			{
				row=abs(chars[i]-'A')/5;
				column=abs(chars[i]-'A')%5;

				diff=row-last_row;
				while(abs(diff)>0)
				{
					if(diff<0)
					{
						result.append("u");
						diff++;
					}
						
					else if(diff>0)
					{
						result.append("d");
						diff--;
					}	
				}

				diff=column-last_column;
				while(abs(diff)>0)
				{
					if(diff<0)
					{
						result.append("l");
						diff++;
					}
						
					else if(diff>0)
					{
						result.append("r");
						diff--;
					}	
				}

				last_row=row;
				last_column=column;
			}
			
			if(result[result.length()-1]!='*' && i!=chars.size()-1)
				result.append("*");

		}

		return result;
	}


};

int main()
{
	Solution solution;
	vector<char> input;
	string result;

	input.push_back('A');
	input.push_back('Z');
	input.push_back('V');
	input.push_back('L');
	input.push_back('M');

	result=solution.Trace(input);
	cout<<result;
	
	return 0;
}
