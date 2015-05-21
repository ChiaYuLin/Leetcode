/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
Use two map for sting s and t.
<Key, Value> in map: key is char. Value in s is the char of t. Value in t is the char of s.
Scan the string s and t at the same time.
If the value of the char in s is not the char of t, return false.
If the value of the char in t is not the char of s, return false.


For example:
s=paper, t=title
p:{t}  t:{p}
When scan to p, the value should be "t".


//Only store the first index.

*/




class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> s_stringanalyze;
        map<char,char> t_stringanalyze;
        std::map<char,char>::iterator it;
        std::map<char,char>::iterator it2;


        for(int i=0;i<s.length();i++)
        {
        	it=s_stringanalyze.find(s[i]);
        	it2=t_stringanalyze.find(t[i]);


        	if(it==s_stringanalyze.end() && it2==t_stringanalyze.end())
        	{
        		s_stringanalyze[s[i]]=t[i];
        		t_stringanalyze[t[i]]=s[i];		
        	}	
        	else if(it!=s_stringanalyze.end() && it2!=t_stringanalyze.end())
        	{
        		if(it->second!=t[i] || it2->second!=s[i])
        			return false;
        	}
        	else
        		return false;
        }

        return true;      

    }
};

int main()
{
	Solution solution;
	bool result;
	string input1="paper";
	string input2="title";


	result=solution.isIsomorphic(input1,input2);

	cout<<"result:"<<result;
}