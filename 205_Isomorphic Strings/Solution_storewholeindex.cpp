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
p:{1,3}  t:{1,3}
The duplicate character should have same index position.


//Use vector to store the index of char.

*/




class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,vector<int> > s_stringanalyze;
        map<char,vector<int> > t_stringanalyze;
        std::map<char,vector<int> >::iterator it;
        std::map<char,vector<int> >::iterator it2;


        for(int i=0;i<s.length();i++)
        {
        	it=s_stringanalyze.find(s[i]);
        	it2=t_stringanalyze.find(t[i]);


        	if(it==s_stringanalyze.end() && it2==t_stringanalyze.end())
        	{
        		vector<int> index;
        		index.push_back(i);
        		s_stringanalyze[s[i]]=index;
        		t_stringanalyze[t[i]]=index;		
        	}	
        	else if(it!=s_stringanalyze.end() && it2!=t_stringanalyze.end())
        	{
        		vector<int> &index1=it->second;
        		vector<int> &index2=it2->second;

        		if(index1.back()==index2.back())
        		{
        			index1.push_back(i);
        			index2.push_back(i);
        		}
        		else
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
	string input1="foo";
	string input2="bar";


	result=solution.isIsomorphic(input1,input2);

	cout<<"result:"<<result;
}