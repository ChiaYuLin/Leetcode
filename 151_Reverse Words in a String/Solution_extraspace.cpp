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

/*
Use a result string to copy the reverse of the original string and swap result and original string in the end.
Use a spaceflag to delete the space if it has two more space between two words.


Special input:

Input1:
Input:  "1 "
Expected:   "1"

Input2
Input:  " "
Expected:   ""
:


*/



class Solution {
public:
    void reverseWords(string &s) {
        string result;
        int length=s.length();
        int current=0;
        bool spaceflag=false;
        bool charflag=false;  //If string only contains " ", will resturn "".


        for(int i=0;i<length;i++)
        {
            if(!isspace(s[i]))
            {
                //if(!charflag)
                //    charflag=true;  //Delete the space in the string which only contains space

                result.insert(result.begin()+current,s[i]);

                if(spaceflag)  //space->char
                    spaceflag=false;


                current++;
            }
            else  //space
            {
                //if(charflag)  //If string only contains " ", will resturn "".
                //{
                    current=0;  //Move the pointer to the begging and insert the space.

                    if(!spaceflag)   //char->space
                        result.insert(result.begin()+current,s[i]);   //Only insert one space between two words.

                    spaceflag=true;
                //}
               
            }


        }

        while(result[0]==' ')   //To delete the begining space. For example: the input is "1 ". We will ouput " 1."
           result.erase(0,1);  

        s.swap(result);
    }
};


int main()
{
	Solution solution;
	string input;

	input="the sky is blue";
    cout<<"input:"<<input<<endl;

	solution.reverseWords(input);


	cout<<"result:"<<input<<endl;


}
