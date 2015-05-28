/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

*/


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
 		s.insert(s.begin(),'\0');
        int wordlength=0;  //The legnth of a word
        int wordcount=0;  //The begining position of inserting a word
        int current=0;
        bool spaceflag=false;

        current=s.length()-1;
        while(s[current]!='\0')
        {
            if(!isspace(s[current]))  //char
            {
                if(spaceflag)   //space->char
                    spaceflag=false;

                wordlength++;

                s.insert(s.begin()+wordcount,s[current]);

            }
            else  //space=>Change to next word
            {
                
                if(!spaceflag)  //char->space. Only deal with one space. 
                {
                    wordcount=wordcount+wordlength;
                    s.insert(s.begin()+wordcount,' ');  //insert a space
                    wordcount++;

                    wordlength=0;
                    current=s.length()-1;

                    spaceflag=true; 
                }
                

            }


            s.erase(s.length()-1,1); //delete the last character

            current=s.length()-1;   //We have to recaculate the length since there might be two more space.
        }

        s.erase(current,1); //delete '\0'

        while(s[0]==' ')   //To delete the begining space. For example: the input is "1 ". We will ouput " 1".
           s.erase(0,1);

        while(s[s.length()-1]==' ')   //To delete the trailing space. For example: the input is " 1". We will ouput "1 ".
           s.erase(s.length()-1,1);
        	
        return;
    }
};


int main()
{
	Solution solution;
	string input;

	input="the sky is blue";

	solution.reverseWords(input);

	cout<<"result:"<<input<<endl;


}
