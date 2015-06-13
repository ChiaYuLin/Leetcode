/*
Given a string, find the length of the longest substring wit_resulthout repeating characters. For example, the longest substring wit_resulthout repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", wit_resulth the length of 1.
*/


#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

/*
Use a map to record the index of characters.
Use two pointers: the start and the moving pointer.
The start pointer (windowstart) points to the start position of current substring.
The moving pointer (current) records the lenth of current substring.

If the char hasnot in the map, we put the index of char into map.
If the char has shown in the map, we have to decide whether the windowstart is smaller than the index of duplicate char.

If windowstart is larger than the index of duplicate char, we don't need to care this duplication.
That is, the substring doesn't contain this duplicate char.

If windowstart is smaller than the index of duplicate char, the index of current char minus the index of duplicate char.
The result becomes the length of substring.
The winodwstart points to the next char of duplicate char.



*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> indextable;
        std::map<char,int>::iterator it_index; //Records the index of char
        int maxlength=0;     //The maxlength of the substring
        int current=0;       //The current length of substring
        int windowstart=1;   //The start position of current substring

        for(int i=0;i<s.length();i++)
        {
        	it_index=indextable.find(s[i]);
        
        	if(it_index==indextable.end())
        	{
        		indextable[s[i]]=i+1;
        		current++;

        		if(current>maxlength)
        			maxlength++;

        	}
        	else
        	{
        		if(windowstart<=it_index->second)
        		{
                    current=i+1-it_index->second;   //Recauculate the length of substring
                    
                    windowstart++;
                    while(windowstart<=it_index->second)  //The winodwstart points to the next char of duplicate char.
                        windowstart++;    
        			
        			indextable[s[i]]=i+1;
        		}
                else   //If windowstart is larger than the index of duplicate char, we don't need to care this duplication.
                {
                    indextable[s[i]]=i+1;
                    current++;

                    if(current>maxlength)
                        maxlength++;
                }
        		
        		
        	}
        		
        }

        return maxlength;


    }
};


int main()
{
	Solution solution;
	string input;
	int result;

    //input="aa";
	//input="bpfbhmipx";
    //input="pwwkew";
	//input="ggububgvfk";
    input="eeydgwdykpv";

	result=solution.lengthOfLongestSubstring(input);

	cout<<"result:"<<result<<endl;
}