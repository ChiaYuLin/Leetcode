/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

/*
Set the first element of vector be the result.
Compare the result and the following string.
If there is different char, erase characters of result string fromt the different char to the end.

*/



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string result="";
    	string comparestring;
    	bool differentflag=false;

    	if(!strs.empty())
    	{
    		result=strs[0];
    		for(int i=1;i<strs.size();i++)
	    	{
	    		comparestring=strs[i];
	    		if(result.length()>=1 && comparestring.length()>=1)
	    		{
	    			int k=0;
	    			for(int j=0;j<comparestring.length();j++)
			    	{
			    		if(j<=result.length()-1 && result[j]!=comparestring[j])
			    		{
			    			result.erase(result.begin()+j,result.end());  //erase characters of result string fromt the different char to the end.
			    			k=result.length();
			    			differentflag=true;   //Can handle [ca,a]
			    			break;
			    		}
			    		k=j;
			    	}
			    	//result.length > comparestring.length and all comparestring is same with result string 
			    	//If comparestring is not same with result string, the differentflag will be true.
			    	//EX: [aaa,aa,aaa]
			    	if(k <= result.length()-1 && !differentflag)  
			    		result=comparestring;


			    	differentflag=false;

	    		}
	    		else
	    			return "";
	    		

	    				
	    	}
	    	return result;
    	}
    	else
    		return result;
    	
        
    }
};


int main()
{
	Solution solution;
	string result;
	vector<string> input;

	/*
	//Test case1:
	input.push_back("aaa");
	input.push_back("aa");
	input.push_back("aaa");*/

	/*
	//Test case2:
	input.push_back("aa");
	input.push_back("");*/

	/*
	//Test case3:
	input.push_back("abcd");
	input.push_back("abce");*/
	

	/*
	//Test case4:
	input.push_back("flower");
	input.push_back("flow");
	input.push_back("flight");*/
	

	/*input.push_back("ca");
	input.push_back("a");*/

	input.push_back("a");
	input.push_back("b");


	result=solution.longestCommonPrefix(input);
	cout<<"result:"<<result<<endl;
}