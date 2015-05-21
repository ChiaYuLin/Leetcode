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
<Key, Value> in map: key is char. Value is the index of char in string and t.
Scan the string s and t at the same time.
If the previous index of the char in s and t is different, return false.

For example:
s=paper, t=title
p:{1}  t:{1}
The duplicate character should have same index position.


//Only store the first index.

*/




class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> s_stringanalyze;
        map<char,int> t_stringanalyze;
        std::map<char,int>::iterator it;
        std::map<char,int>::iterator it2;


        for(int i=0;i<s.length();i++)
        {
        	it=s_stringanalyze.find(s[i]);
        	it2=t_stringanalyze.find(t[i]);


        	if(it==s_stringanalyze.end() && it2==t_stringanalyze.end())
        	{
        		s_stringanalyze[s[i]]=i;
        		t_stringanalyze[t[i]]=i;		
        	}	
        	else if(it!=s_stringanalyze.end() && it2!=t_stringanalyze.end())
        	{
        		if(it->second!=it2->second)
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