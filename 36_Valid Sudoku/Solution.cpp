/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int contrast[9][9];
        int row,column,value,totalcount,contrastcount,columncount;
        
        for(int i=0;i<9;i++)
        {
        	for(int j=0;j<9;j++)
        		contrast[i][j]=0;
        }
        	
        
		
		//Check row
		row=0;
        while(row<9)
        {
        	column=0;
			while(column<9)
        	{
				if(board[row][column]=='.')
        			column++;
        		else 
				{
					value=board[row][column]-'0'-1;
					
					if(contrast[row][value]==0)
					{
						contrast[row][value]=1;
						column++;
					}	
					else
						return false;  //digit duplicate 
				}	
        	}
        	row++;
        }
        
        
        for(int i=0;i<9;i++)
        {
        	for(int j=0;j<9;j++)
        		contrast[i][j]=0;
        }
        
        
        //Check column
        column=0;
        while(column<9)
        {
        	row=0;
        	while(row<9)
			{
				if(board[row][column]=='.')
					row++;
				else
				{
					value=board[row][column]-'0'-1;
					if(contrast[value][column]==0)
					{
						contrast[value][column]=1;
						row++;
					}	
					else
						return false;  //digit duplicate 
				}	
			}  
			column++;      	
        }
        
        for(int i=0;i<9;i++)
        {
        	for(int j=0;j<9;j++)
        		contrast[i][j]=0;
        }
        
        
        totalcount=1;  //For the set: set1:column0~2  set2:column3~5   set3:column6~8
        contrastcount=-1;  //For the row of contrast:0~8
        while(totalcount<=3)
        {
        	row=0;
			while(row<9)
			{
				if(row%3==0)   //When row%3==0, it finishes one square 3x3 check.
					contrastcount++; 
				
				if(totalcount==1)
        			column=0;
        		else if(totalcount==2)
        			column=3;
        		else 
        			column=6;
				
					
				columncount=0;   //For column iterative:0~2
				while(columncount<=2)
				{
					if(board[row][column]=='.')
					{
						columncount++;
						column++;
					}
					else
					{
						value=board[row][column]-'0'-1;
						if(contrast[contrastcount][value]==0)
						{
							contrast[contrastcount][value]=1;
							columncount++;
							column++;
						}	
						else
							return false;  //digit duplicate 
					}	
				}
				row++;
			}
			totalcount++;
        }
        
        return true;
    }
};



int main()
{
	Solution solution;
	bool result=false;
	vector<vector<char> >input;
	vector<char> inside;

	
	char myarray1 [] = {'5','3','.','.' ,'7','.','.','.','.'} ;	
	inside.insert(inside.begin(), myarray1, myarray1+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray2 []= {'6','.','.','1','9','5','.','.','.'} ;
	inside.insert(inside.begin(), myarray2, myarray2+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray3 []= {'.','9','8','.','.','.','.','6','.'} ;
	inside.insert(inside.begin(), myarray3, myarray3+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray4 []= {'8','.','.','.','6','.','.','.','3'} ;
	inside.insert(inside.begin(), myarray4, myarray4+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray5 []= {'4','.','.','8','.','3','.','.','1'} ;
	inside.insert(inside.begin(), myarray5, myarray5+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray6 []= {'7','.','.','.','2','.','.','.','6'} ;
	inside.insert(inside.begin(), myarray6, myarray6+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray7 []= {'.','6','.','.','.','.','2','8','.'} ;
	inside.insert(inside.begin(), myarray7, myarray7+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray8 []= {'.','.','.','4','1','9','.','.','5'} ;
	inside.insert(inside.begin(), myarray8, myarray8+9);
	input.push_back(inside);
	inside.clear();
	
	char myarray9 []= {'.','.','.','.','8','.','.','7','9'} ;
	inside.insert(inside.begin(), myarray9, myarray9+9);
	input.push_back(inside);
	inside.clear();
	
	
    for(vector<vector<char> >::iterator it=input.begin();it!=input.end();it++)
	{
		cout<<"[";
		for(vector<char>::iterator it2=it->begin();it2!=it->end();it2++)
		{
			cout<<*it2<<",";
		}
		cout<<"]"<<endl;
	}
	
	
	result=solution.isValidSudoku(input); 
	
	cout<<"result:"<<result<<endl;
	
	return 0;
}
