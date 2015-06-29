/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/*
If we create [m][n] and put result[1][1]=1 (The start method is 1). 
We will have the runtime error when we caculate result[i][j-1] or result[i-1][j](i=1 and j=1).

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > result(m,vector<int>(n));
        
        result[1][1]=1;

        for(int i=1;i<=m;i++)
        {
        	for(int j=1;j<=n;j++)
        	{
        		result[i][j]=result[i][j-1]+result[i-1][j];

        	}
        }

        return result[m][n];
    }
};


Therefore, We create a [m+1][n+1] array so we don't need to worry about the boundary.
we set result[0][1]=1 instead of setting result[0][1]=1 and result[1][0]=1.
Because the value of result[1][1] is 1, the value comes from result[0][1] is enough.
If we set result[0][1]=1 and result[1][0]=1, the value of result[1][1]=result[0][1]+result[1][0]=2.
The result will be wrong.

result[m][n]=result[m-1][n](up)+result[m][n-1](left).
Thus, we can use this formula to find the answer.

*/


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > result(m+1,vector<int>(n+1));
        
        result[0][1]=1; 

        for(int i=1;i<=m;i++)
        {
        	for(int j=1;j<=n;j++)
        	{
        		result[i][j]=result[i][j-1]+result[i-1][j];
        	}
        }

        return result[m][n];
    }
};




int main()
{
	Solution solution;
	int result=0;
	int m,n;
	m=1;
	n=2;
	result=solution.uniquePaths(m,n);
	cout<<"result:"<<result<<endl;
}