/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
/*
Declare a result[m][n] to store the result.
Since we don't declare result[m+1][n+1] this time, we have to deal with result[0][j] and result[i][0] individually.
We check whether obstacleGrid[i][j]==1. 
If it is equal to 1, the result value is 0.
If it is equal to 0, the result value is result[i][j]=result[i][j-1]+result[i-1][j].

*/



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int> >result(m,vector<int>(n));

        if(obstacleGrid[0][0]==0)
        	result[0][0]=1;

        for(int j=1;j<n;j++)   //First row
        {
        	if(obstacleGrid[0][j]==0)
        		result[0][j]=result[0][j-1];
        }	

        for(int i=1;i<m;i++)  //First column
        {
        	if(obstacleGrid[i][0]==0)
        		result[i][0]=result[i-1][0];
        }


        for(int i=1;i<m;i++)
        {
        	for(int j=1;j<n;j++)
        	{

        		if(obstacleGrid[i][j]==0)
        			result[i][j]=result[i][j-1]+result[i-1][j];
        	}
        }

        return result[m-1][n-1];
        
    }
};

int main()
{
	Solution solution;
	int result=0;
	vector<vector<int> >input;
	vector<int> inside;

	int myarray1 [] = {0,0,0} ;	
	inside.insert(inside.begin(), myarray1, myarray1+3);
	input.push_back(inside);
	inside.clear();

	int myarray2 [] = {0,1,0} ;	
	inside.insert(inside.begin(), myarray2, myarray1+3);
	input.push_back(inside);
	inside.clear();

	int myarray3 [] = {0,0,0} ;	
	inside.insert(inside.begin(), myarray3, myarray1+3);
	input.push_back(inside);
	inside.clear();
	
	result=solution.uniquePathsWithObstacles(input);
	cout<<"result:"<<result<<endl;
}