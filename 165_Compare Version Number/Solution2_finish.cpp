/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of 
the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

*/

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> split(string str, char delimiter) 
	{
  		vector<string> internal;
  		stringstream ss(str); // Turn the string into a stream.
  		string tok;
  
  		while(getline(ss, tok, delimiter))
		{
    		internal.push_back(tok);
  		}
  
   		return internal;
	}

    int compareVersion(string version1, string version2)
	 {
    	
    	int result=-2;
    	stringstream buffer1;
    	int v1,v2;
		std::vector<string> sub=split(version1,'.');
		std::vector<string> sub2=split(version2,'.');
		std::vector<string>::iterator it1;
		std::vector<string>::iterator it2;
		int subsize=0;
		int subsize2=0;
		
		subsize=sub.size();
		subsize2=sub2.size();
		

		it1=sub.begin();
		it2=sub2.begin();
			
		while(subsize>0 && subsize2 >0)
		{
			buffer1 << *it1;
            buffer1 >> v1;
			buffer1.clear(); 		
				
			buffer1 << *it2;
            buffer1 >> v2;
			buffer1.clear(); 
				
			if(v1>v2)
			{
				result=1;
				break;
			}
			else if(v1<v2)
			{
				result=-1;
				break;
			}
			else  //v1=v2
			{
				it1++;
				it2++;
				subsize--;
				subsize2--;
			}
		}
		if(result==-2)
		{
			if(subsize>subsize2) //subsize!=0
			{
				buffer1 << *it1;
            	buffer1 >> v1;
				buffer1.clear();
				
				if(v1!=0)  //1.0 vs 1
					result=1;
				else
					result=0;
			}
				
			else if(subsize2>subsize) //subsize2!=0
			{
				buffer1 << *it2;
            	buffer1 >> v2;
				buffer1.clear();
				
				if(v2!=0)  //1 vs 1.0
					result=-1;
				else
					result=0;
			}
			else
				result=0;
		}
			
    	return result;
    }
};


int main()
{
	
	Solution solution;
	int result=0;
	result=solution.compareVersion("1","1.0");
	cout<<"result:"<<result<<endl;
	return 0;
}
