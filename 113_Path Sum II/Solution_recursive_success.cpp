/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;




class Solution {
public:
	void Sum(TreeNode *root, int sum,vector<int> &path,vector<vector<int> > &finalresult) //Use call by reference to access the same variable: path and finalresult
	{


		if(root==NULL)
			return;
			
		if(root->val==sum && root->left==NULL && root->right==NULL) //When there is the sum, put path into finalresult
		{
			path.push_back(root->val);
			
			finalresult.push_back(path);
			
			path.pop_back();

			return;
			
		}	
		
		path.push_back(root->val);  //Record the path first

		Sum(root->left, sum-root->val,path,finalresult);  

		Sum(root->right, sum-root->val,path,finalresult);

		path.pop_back();  //If the path is finish, pop the value. The path will be put in the finalresult when there is the sum.

		return;
	}

	
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > finalresult;
		vector<int> path;


		Sum(root,sum,path,finalresult);


		return finalresult;
			
	
    }

};

TreeNode * Btree::contruct_tree()
{
	TreeNode *root=NULL;
	TreeNode *leaf=NULL;
	Btree btree;

	/*
	//Test case1:
	root=btree.insert(1);  //insert root
	leaf=btree.insert(2,root);
	*/
	
	//Test case2:
	root=btree.insert(5);  //insert root
	
	//left tree
	leaf=btree.insert(4,root);
	leaf=btree.insert_nocompare(11,leaf);
	btree.insert_nocompare(7,leaf);
	btree.insert_nocompare(2,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(8,root);
	btree.insert_nocompare(13,leaf);
	leaf=btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(5,leaf);
	leaf=btree.insert_nocompare(1,leaf);
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	vector<vector<int> > result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.pathSum(root, 22);
	
	
	for(vector<vector<int> >::iterator it=result.begin();it!=result.end();it++)
	{
		cout<<"[";
		for(vector<int>::iterator it2=it->begin();it2!=it->end();it2++)
		{
			cout<<*it2<<",";
		}
		cout<<"]"<<endl;
	}
	return 0;
}
